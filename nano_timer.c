#include <stdio.h>
#include <time.h>
// POSIX.1-2008 では gettimeofday() は廃止予定
// clock_gettime() の使用が推奨
//参考:
// https://linuxjm.osdn.jp/html/LDP_man-pages/man2/gettimeofday.2.html
// https://www.mm2d.net/main/prog/c/time-05.html
// プログラム参考:
// https://qiita.com/MuriNishimori/items/9f360c327e756b98f26d
// https://qiita.com/katoken-0215/items/3acb8b674c5e5bbbf9a4

// CLOCK_REALTIME
// システムで一意な実時間、システム時間の手動設定やNTPによる変更の影響を受ける

// 構造体について
// struct timespec {
// 	time_t tv_sec;        /* 秒 */
// 	long   tv_nsec;       /* ナノ秒 */
// }

void timespec_diff(struct timespec *start, struct timespec *stop,struct timespec *result){
  if ((stop->tv_nsec - start->tv_nsec) < 0) {
    result->tv_sec = stop->tv_sec - start->tv_sec - 1;
    result->tv_nsec = stop->tv_nsec - start->tv_nsec + 1000000000;
  } else {
    result->tv_sec = stop->tv_sec - start->tv_sec;
    result->tv_nsec = stop->tv_nsec - start->tv_nsec;
  }
}

void test_timer(){
  struct timespec startTime, endTime, sleepTime,elapsedTime;
  struct timespec res;
  int ii,jj;

  sleepTime.tv_sec = 0;
  sleepTime.tv_nsec = 1;

  // 指定されたクロック clk_id の分解能 (精度) をresへ格納
  clock_getres(CLOCK_REALTIME, &res);
  printf("実時間精度 = %ld[ns]\n",res.tv_nsec);

  // 時刻をCLOCK_REALTIMEで取得し,startTimeへ格納する
  clock_gettime(CLOCK_REALTIME, &startTime);

  //-----何らかの処理を実行-----
  for ( ii = 0; ii < 100; ii++){
    for ( jj = 0; jj < 100; jj++){
      nanosleep(&sleepTime, NULL);
    }
  }
  // -----ここまで-----

  // 時刻をCLOCK_REALTIMEで取得し,endTimeへ格納する
  clock_gettime(CLOCK_REALTIME, &endTime);

  // 処理時間をelapsedTimeへ格納する
  timespec_diff(&startTime,&endTime,&elapsedTime);

  // 出力
  printf("開始時刻 = %10ld.%09ld\n", startTime.tv_sec, startTime.tv_nsec);
  printf("終了時刻 = %10ld.%09ld\n", endTime.tv_sec, endTime.tv_nsec);
  printf("経過時間 = %10ld.%09ld\n", elapsedTime.tv_sec, elapsedTime.tv_nsec);
}

int main(int argc, char const *argv[]) {
  test_timer();
  return 0;
}
