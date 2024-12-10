#include <stdio.h>
#include <stdlib.h>
void citmatrix(int n, int a[1001][1001])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
int main()
{
    int n, tabla[1001][1001];
    long long mut = 0;
    int i = 0, j = 0;
    scanf("%d", &n);
    citmatrix(n, tabla);
    do
    {
        int *poz = &tabla[i][j];
        mut += abs(tabla[i][j]);
        if ((i + j) % 2 == 0) // daca suntem pe alb
        {
            j += tabla[i][j];
            if (j >= n)
                j %= n;
            if (j < 0)
                j = n - (-j % n);
        }
        else // daca suntem pe negru
        {
            i += tabla[i][j];
            if (i >= n)
                i %= n;
            if (i < 0)
                i = n - (-i % n);
        }
        *poz = 0;
    } while (tabla[i][j] != 0);
    printf("%lld\n", mut);
    i = n - i;
    char c2 = 'A' + j % 26;
    char c = 'A' + j / 26 - 1;
    if (j < 26)
        printf("%d %c\n", i, c2);
    else if(j >= 26 && j < 988)
        printf("%d %c%c\n", i, c, c2);
    else
        {
            c = 'A' + j / 26 % 26;
            printf("%d A%c%c", i, c, c2);
        }
}