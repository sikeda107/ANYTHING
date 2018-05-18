// 参考:
// http://flat-leon.hatenablog.com/entry/cpp_preprocessor
#include <stdio.h>

// 引数に#をつけると文字列定数化できる
#define GET_VALUE_NAME(n) #n

//組み込みマクロを使ったログの表示
#define PRINT_LOG( log ) printf( "File:%s Line:%d Func:%s Log:%s\n", __FILE__, __LINE__, __func__, log )

int main(int argc, char const *argv[]) {
  int value = 0;
  char logname[256] = "MYLOG";
  printf("%s\n",GET_VALUE_NAME(value));
  PRINT_LOG(logname);
  return 0;
}
