#include <stdio.h>

#define N 10

typedef struct{
  int a[N];
  int b[N];
  int c[N];
  int* pointer;
}Numbers;

int main(int argc, char const *argv[]) {
  int i = 0;
  int count = N;
  int number = 999;
  Numbers num1,num2;

  //num1 初期化
  for ( i = 0; i < N; i++) {
    num1.a[i] = i;
    num1.b[i] = i*10;
    num1.c[i] = i*100;
  }
  num1.pointer = &number;

  //num1内容確認
  for ( i = 0; i < N; i++) {
    printf("1a : %d\n",num1.a[i]);
    printf("1b : %d\n",num1.b[i]);
    printf("1c : %d\n",num1.c[i]);
  }
  printf("\n");
  //num2内容確認
  for ( i = 0; i < N; i++) {
    printf("2a : %d\n",num2.a[i]);
    printf("2b : %d\n",num2.b[i]);
    printf("2c : %d\n",num2.c[i]);
  }
  printf("\n");
  //num1 num2 ポインタ確認
  printf("num1: %x %d\n", num1.pointer, *num1.pointer);
  //printf("num2: %x %d\n", num2.pointer, *num2.pointer); //未代入のためsegmentation fault
  printf("\n");
  //代入
  num2 = num1;

  //num2内容確認
  for ( i = 0; i < N; i++) {
    printf("2a : %d\n",num2.a[i]);
    printf("2b : %d\n",num2.b[i]);
    printf("2c : %d\n",num2.c[i]);
  }
  printf("\n");

  //num1の全ての要素に0を代入
  for ( i = 0; i < N; i++) {
    num1.a[i] = i*0;
    num1.b[i] = i*0;
    num1.c[i] = i*0;
  }
  //num1内容確認
  for ( i = 0; i < N; i++) {
    printf("1a : %d\n",num1.a[i]);
    printf("1b : %d\n",num1.b[i]);
    printf("1c : %d\n",num1.c[i]);
  }
  printf("\n");
  //num2内容確認
  for ( i = 0; i < N; i++) {
    printf("2a : %d\n",num2.a[i]);
    printf("2b : %d\n",num2.b[i]);
    printf("2c : %d\n",num2.c[i]);
  }
  printf("\n");

  //num1 num2 ポインタ確認
  printf("num1: %x %d\n", num1.pointer, *num1.pointer);
  printf("num2: %x %d\n", num2.pointer, *num2.pointer);

  number++;

  //num1 num2 ポインタ確認
  printf("num1: %x %d\n", num1.pointer, *num1.pointer);
  printf("num2: %x %d\n", num2.pointer, *num2.pointer);

  return 0;
}
