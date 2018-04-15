#include<stdio.h>

int main(int argc, char const *argv[]) {
  int a,b;
  a = 0;
  b = 0;
  printf("0 0 | %d \n",a^b );
  a = 0;
  b = 1;
  printf("0 1 | %d \n",a^b );
  a = 1;
  b = 0;
  printf("1 0 | %d \n",a^b );
  a = 1;
  b = 1;
  printf("1 1 | %d \n",a^b );
  return 0;
}
