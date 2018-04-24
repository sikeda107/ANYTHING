#include <stdio.h>
#include <stdlib.h>
#include "./MersenneTwister/mt19937-64.h"
#include <time.h>

#define RATE 0.05
#define RATE2 0.05

int decision_by_probability(double probability){
   return (genrand64_real1() <= probability);//genrand64_real1() returns [0,1]-real-interval
}

void test(){
  double drandnum = 0.0;
  int i, count = 100000, result = 0;
  int result_times[3] = {0};

  printf("START %s\n",__func__ );
  init_genrand64((unsigned)time(NULL));

  for ( i = 0; i < count; i++) {
    result = decision_by_probability(RATE);
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
    printf("END %s\n",__func__ );
}//end-function

void test2(){
  double drandnum = 0.0;
  int i, count = 100000, result = 0;
  int result_times[2] = {0};
  int flag = 0, flagCount = 0;

  printf("START %s\n",__func__ );
  init_genrand64((unsigned)time(NULL));

  for ( i = 0; i < count; i++) {
    if(decision_by_probability(RATE)){
      result_times[0]++;
      flag = 1;
    }
    else if(decision_by_probability(RATE + RATE2)){
      result_times[1]++;
      if(flag){
        printf("flagON\n");
        flagCount++;
      }
    }
    // else if(decision_by_probability(RATE2)){
    //   result_times[1]++;
    //   if(flag){
    //     printf("flagON\n");
    //     flagCount++;
    //   }
    // }

    // if(decision_by_probability(RATE2)){
    //   result_times[1]++;
    //   if(flag){
    //     printf("flagON\n");
    //     flagCount++;
    //   }
    // }
    else{}
    flag = 0;
  }//end-for
  printf("expected probability: RATE %f  RATE2 %f \n", RATE, RATE2 );
  printf("pop probability  0 by func: %f \n",(double)result_times[0]/(double)count );
  printf("pop probability  1 by func: %f \n",(double)result_times[1]/(double)count );
  printf("pop probability  f by func: %f \n",(double)flagCount/(double)count );
  printf("END %s\n",__func__ );
}//end-function
int main(int argc, char const *argv[]) {
  test();
  getchar();
  test2();
  return 0;
}
