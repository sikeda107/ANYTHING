#include <stdio.h>
#include <stdlib.h>
#include "MT.h"
#include <time.h>

#define RATE 0.05

int decision_by_probability(double probability){
   return (genrand64_real1() <= probability);//genrand64_real1() returns [0,1]-real-interval
}

int main(int argc, char const *argv[]) {
  double drandnum = 0.0;
  int i, count = 100000, result = 0;
  int result_times[3] = {0};
  init_genrand64((unsigned)time(NULL));

  for ( i = 0; i < count; i++) {
    printf("loop %d\n",i );
    result = decision_by_probability(RATE);
    printf("return %d \n",result);
    switch (result) {
      case 0:
      result_times[0]++;
      break;

      case 1:
      result_times[1]++;
      break;

      default:
      fprintf(stderr,"unexpected result %d \n",result );
      break;
    }//end-swich
  }//end-for

  printf("expected probability: %f \n", RATE );
  printf("pop probability  0 by func: %f \n",(double)result_times[0]/(double)count );
  printf("pop probability  1 by func: %f \n",(double)result_times[1]/(double)count );
  return 0;
}
