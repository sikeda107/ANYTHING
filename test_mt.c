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
#include "./MersenneTwister/mt19937-64.h"

int main(void){
  int i;
  init_genrand64((unsigned)time(NULL));//初期化
  for(i=0;i<10;i++){
    printf("%d\n",genrand64_int63());//乱数生成
  }
  for(i=0;i<100;i++){
    //genrand64_real1() generates a random number on [0,1]-real-interval
    printf("%d ",(int)(genrand64_real1()*10));//random number on integral [0,9]
    printf("%f ",genrand64_real1());//random number on [0,1]
    if(i%10==9)printf("\n");
  }
  return 0;
}
