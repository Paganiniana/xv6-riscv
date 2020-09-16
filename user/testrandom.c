#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char const *argv[])
{
    int * test = malloc(450);

    // counter
    int i;

    // initialize values

    for (i = 0; i < 100; i ++) {
        test[i] = 0;
    }

    int times = 10000;
    int sleeps = 10;

    int r;
    for (int ii = 0; ii < sleeps; ii ++) {
        for (i = 0; i < times; i++) {
        r = getrandom(100);
        test[r] = test[r] + 1;
        }
        sleep(1);   
    }

    // print the values

    for (i = 0; i < 100; i ++) {
        printf("Number %d was called: %d\n", i, test[i]);
    }

    exit(0);
}
