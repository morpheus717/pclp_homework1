#include <stdio.h>
#define NMAX 101
void citire(int n, int a[NMAX][NMAX])
{
    int k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        a[i][0] = k;
        for (int j = 1; j <= k; j++)
            scanf("%d", &a[i][j]);
    }
}
void createmyline(int n, int m, int nomo[NMAX][NMAX], int mylinii[NMAX][NMAX])
{
    for (int i = 0; i < n; i++)
    {
        int k = 0, sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += nomo[i][j];
            if (nomo[i][j] == 0 && sum != 0)
            {
                mylinii[i][++k] = sum;
                sum = 0;
            }
        }
        if (sum != 0)
        {
            mylinii[i][++k] = sum;
            sum = 0;
        }
        mylinii[i][0] = k;
    }
}
void createmycolumn(int n, int m, int nomo[NMAX][NMAX], int mycoloane[NMAX][NMAX])
{
    for (int j = 0; j < m; j++)
    {
        int k = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nomo[i][j];
            if (nomo[i][j] == 0 && sum != 0)
            {
                mycoloane[j][++k] = sum;
                sum = 0;
            }
        }
        if (sum != 0)
        {
            mycoloane[j][++k] = sum;
            sum = 0;
        }
        mycoloane[j][0] = k;
    }
}
int main()
{
    int t;
    int n, m, linii[NMAX][NMAX], coloane[NMAX][NMAX];
    int mylinii[NMAX][NMAX], mycoloane[NMAX][NMAX];
    int nomo[NMAX][NMAX];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        citire(n, linii);
        citire(m, coloane);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &nomo[i][j]);
        createmyline(n, m, nomo, mylinii);
        createmycolumn(n, m, nomo, mycoloane);
        int ok = 1;
        for (int i = 0; i < n; i++)
        {
            if (mylinii[i][0] != linii[i][0])
                ok = 0;
            else
                for (int j = 1; j <= mylinii[i][0]; j++)
                    if (mylinii[i][j] != linii[i][j])
                        ok = 0;
        }
        for (int i = 0; i < m; i++)
        {
            if (mycoloane[i][0] != coloane[i][0])
                ok = 0;
            else
                for (int j = 1; j <= mycoloane[i][0]; j++)
                    if (mycoloane[i][j] != coloane[i][j])
                        ok = 0;
        }
        if (ok)
            printf("Corect\n");
        else
            printf("Eroare\n");
    }
}