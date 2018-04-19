#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc, char const *argv[]) {
  char filename[20] = "./CSV/sample.csv";
  int i;
  FILE* fp;

  for (i = 0; i < N; i++) {
    sprintf(filename,"./CSV/sample%d.csv",i);
    fp = fopen(filename,"w");
    if(fp == NULL){
      fprintf(stderr, "%s : file open error\n",filename );
      exit(1);
    }
    fprintf(fp, "%d %d \n",i,rand());
    close(fp);
  }

  return 0;
}
