#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/stat.h"
#include "kernel/syscall.h"
#include "kernel/pref.h"

// //------1----
// void print_perf(struct perf *performance);

// int main(int argc, char** argv){
//   int pid1, status1;
//     struct perf perf2;
//     pid1 = fork();
//     if (pid1 > 0) {
//         wait_stat(&status1, &perf2);
//         print_perf(&perf2);
//     } else {
//         for (int a = 0; a < 10; ++a) {
//           sleep(1);
              
// }
//     }
// exit(0);
//     }

// void print_perf(struct perf *performance) {
//     fprintf(1, "pref:\n");
//     fprintf(1, "\tctime: %d\n", performance->ctime);
//     fprintf(1, "\tttime: %d\n", performance->ttime);
//     fprintf(1, "\tstime: %d\n", performance->stime);
//     fprintf(1, "\tretime: %d\n", performance->retime);
//     fprintf(1, "\trutime: %d\n", performance->rutime);
//     fprintf(1, "\n\tTurnaround time: %d\n", (performance->ttime - performance->ctime));
// }


// // -----2-----
// int main(int argc, char** argv){
//    int cpid=fork();
//    int *stat = (int*)malloc(sizeof(int));
//    struct perf *perf = (struct perf*)malloc(sizeof(perf));
//    if (cpid != 0){
//       int ret = wait_stat(stat,perf);
//       fprintf(2, "return value: %s %d\n", "wait_stat", ret);
//       fprintf(2,"Sleep: %d Running: %d Runnable: %d Status: %d Creation: %d Termination\n",perf->stime,perf->rutime,perf->retime,*stat, perf->ctime, perf->ttime);
//    }else{
//       sleep(20);
//    }
//    exit(0);
// }

// //-----3-----
int main(int argc, char** argv){
    int mask = 1<<6 | 1 <<16; //trace kill and write
    trace(mask, getpid());
        int pid = fork();
    int status;
        if (pid > 0){ //parent
        wait(&status);
            int pid2 = fork();
            if (pid2 == 0){ //child2
        trace(1<<6, getpid()); //trace kill
        int pid4 = fork();
        wait(&status);
        if (pid4 >0){ //child 2
            kill(pid4); //should be traced
                write(1, "child2\n", 7);  //shouldnt be traced
        }
            }
            else{ //parent
        wait(&status);
                write(1, "parent\n", 7); //should be traced
        open("/path", 0); //shouldn't be traced
            }
        }
    else{ //child1
        write(1, "child1\n", 7);  //should be traced
        int pid3 = fork(); //shouldnt be traced
        if (pid3 >0){ //child1
        wait(&status);
        kill(pid3);  //should be traced
        }
    }
exit(0);
}