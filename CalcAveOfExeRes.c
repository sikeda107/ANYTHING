#include <stdio.h>

int main(int argc, char* argv[])
{
  double num[10001] = { };
  int i;
  int scanret;
  double ave       = 0.0;
  double sum       = 0.0;
  int n_min = 0;
  int n_max = 0;

  /* for(i=0;i<(sizeof(num)/sizeof(num[0]));i++){
  * printf("%f",num[i]);
  * }*/

  for(i = 0; i < (sizeof(num) / sizeof(num[0])); i++)
  {
    scanret = scanf("%lf", &num[i]);
    if(scanret == EOF)
    {
      break;
    }
    if(num[n_max] < num[i])
    {
      n_max = i;
    }
    if(num[n_min] > num[i])
    {
      n_min = i;
    }
    sum += num[i];
  }

  ave = sum / (double) i;

  printf("%3d:data\n %.3f:min\n %.3f:max\n %.3f:ave\n %.3f:sum\n", i, num[n_min], num[n_max], ave, sum);
  return 0;
}
