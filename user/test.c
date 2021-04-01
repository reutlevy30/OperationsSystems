#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/stat.h"
#include "kernel/syscall.h"
#include "kernel/pref.h"

int main(int argc, char** argv){
//   //  int mask=(1<< 1)|( 1<< 6)| ( 1<< 12) | ( 1<< 16);
//    // trace(mask, 2);
//     struct perf* performace=(struct perf*) malloc(sizeof(struct perf));
//     int status=2;
//     printf("---------status-------%d\n",&status);
//     wait_stat(&status,performace);
//     printf("---------statussssss-------%d\n",status);
//  //   printf("%s","helllllllllllo\n");
//     exit(0);

   int cpid=fork();
   int *stat = (int*)malloc(sizeof(int));
   struct perf *perf = (struct perf*)malloc(sizeof(perf));
   if (cpid != 0){
      int ret = wait_stat(stat,perf);
      fprintf(2, "return value: %s %d\n", "wait_stat", ret);
      fprintf(2,"Sleep: %d Running: %d Runnable: %d Status: %d Creation: %d Termination\n",perf->stime,perf->rutime,perf->retime,*stat, perf->ctime, perf->ttime);
   }else{
      sleep(20);
   }
   exit(0);
}