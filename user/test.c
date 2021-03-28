#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/stat.h"
#include "kernel/syscall.h"

int main(int argc, char** argv){
    int mask=(1<< 1)|( 1<< 6)| ( 1<< 12) | ( 1<< 16);
    trace(mask, 2);
    exit(0);
}