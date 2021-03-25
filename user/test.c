#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/stat.h"
#include "kernel/syscall.h"

int main(int argc, char** argv){
    fprintf(2, "hello\n");
    trace(1 << 6, 2);
    kill(2);
    exit(0);
}