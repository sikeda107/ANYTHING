//ref: http://www1.cts.ne.jp/~clab/hsample/Math/Math5.html

#include <stdio.h>
#include <math.h>    /* exp(  )pow(  )で必要 */

double CalPois(double a, double n);
double Fact(double n);
void main(void);

  /* a分間にn回起きる確率（ポアッソン分布）を計算する */
double CalPois(double a, double n)
{
    return (exp(-a) * pow(a, n) / Fact(n));
}

  /* 階乗を計算する */
double Fact(double n)
{
    return((n == 0.0 ) ? 1: n * Fact(n - 1.0));
}

void main(void)
{
    double pois;
    double n;
    double a = 1.0;

    printf("1 分間に平均で１回起きる現象が\n");
    printf("n回\t起きる確率\n\n");

    for (n = 0.0; n <= 10.0; n++) {
        pois = CalPois(a, n);
        printf("%2.0lf\t%10.8lf\n", n, pois);
    }
}
