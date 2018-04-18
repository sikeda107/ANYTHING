//Reference:http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/MT2002/mt19937ar.html
//SourceURL:http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/MT2002/CODES/mt19937ar.sep.tgz
//Thesis: https://dl.acm.org/citation.cfm?id=272995
//Bibtex:
// @article{matsumoto1998mersenne,
//   title={Mersenne twister: a 623-dimensionally equidistributed uniform pseudo-random number generator},
//   author={Matsumoto, Makoto and Nishimura, Takuji},
//   journal={ACM Transactions on Modeling and Computer Simulation (TOMACS)},
//   volume={8},
//   number={1},
//   pages={3--30},
//   year={1998},
//   publisher={ACM}
// }
#include <stdio.h>
#include <time.h>
#include "./MersenneTwister/mt19937ar.h"

int main(void){
  int i;
  init_genrand((unsigned)time(NULL));//初期化
  for(i=0;i<10;i++){
    printf("%ld\n",genrand_int32());//乱数生成
  }
  for(i=0;i<100;i++){
    printf("%ld ",genrand_int32()%10);//0~9の乱数生成
    if(i%10==9)printf("\n");
  }
  return 0;
}
//乱数生成関数一覧
// genrand_int32() //符号なし32ビット長整数
// genrand_int31() //符号なし31ビット長整数
// genrand_real1() //一様実乱数[0,1] (32ビット精度)
// genrand_real2() //一様実乱数[0,1) (32ビット精度)
// genrand_real3() //一様実乱数(0,1) (32ビット精度)
// genrand_res53() //一様実乱数[0,1) (53ビット精度
