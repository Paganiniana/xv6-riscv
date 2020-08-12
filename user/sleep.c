#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please provide an argument, preferable, number of seconds.\n");
        exit(1);
    }

    int num_seconds = atoi(argv[1]);

    int s = sleep(num_seconds);
    while(s != 0) {
        continue;
    }
    exit(0);
}