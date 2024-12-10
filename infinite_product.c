#include <stdio.h>
#include <math.h>
#include <stdlib.h>
unsigned long long convert8_10(unsigned long long x)
{
    unsigned long long y = 0;
    unsigned long long putere = 1;
    while (x)
    {
        y += putere * (x % 10);
        x /= 10;
        putere *= 8;
    }
    return y;
}
void secondmax(long long a, long long *amax1, long long *amax2)
{
    if (a > *amax1)
    {
        *amax2 = *amax1;
        *amax1 = a;
    }
    else if (a > *amax2 && a != *amax1)
        *amax2 = a;
}
int main()
{
    int n;
    unsigned long long ps = 0;
    long long a, b, amax1 = -1, amax2 = -1, bmax1 = -1, bmax2 = -1;
    double na = 0, nb = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a, &b);
        a = convert8_10(a);
        b = convert8_10(b);
        ps += a * b;
        secondmax(a, &amax1, &amax2);
        secondmax(b, &bmax1, &bmax2);
        na += a * a;
        nb += b * b;
    }
    printf("%lld\n", ps);
    printf("%lld ", amax2);
    printf("%lld\n", bmax2);
    printf("%.7lf %.7lf\n", sqrt(na), sqrt(nb));
}
