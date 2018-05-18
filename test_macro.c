// 参考:
// http://flat-leon.hatenablog.com/entry/cpp_preprocessor
#include <stdio.h>

// 引数に#をつけると文字列定数化できる
#define GET_VALUE_NAME(n) #n

int main(int argc, char const *argv[]) {
  int value = 0;

  printf("%s\n",GET_VALUE_NAME(value));
  return 0;
}
