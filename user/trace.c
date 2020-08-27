#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/** INTERFACE
 * 
 * EXPECTS:
 *  -   argv will contain something to this effect... trace <cmd> [<args>] 
 * 
 * FUNCTION:
 *  -   executes the command, with arguments, passed to trace
 *  -   for each systemcall, prints the following:
 *      -   (pid) syscall (syscall name) -> (return value)
 *  -   should only effect the process running
 * 
 * REQUIRS:
 *  -   syscall 'settrace', which sets a boolean value, whether or not to print syscalls
 *  -   syscall 'untrace', which unsets said boolean, making sure the state does not effect future processes
 *
 */

int main(int argc, char*argv[]) {

    // setup the trace, make sure it succeeds
    int stret = settrace();
    if (stret <0) {
        printf("Could not set the trace\n");
    }

    int pid = fork();

    if (pid != 0) {
        wait(&pid);
    } else {
        // get the arguments and exec
        char * newargs[argc - 1];
        for (int i = 1; i <argc; i++) {
            newargs[i-1] = argv[i];
        }
        // call exec with the new arguments
        exec(newargs[0], newargs);
    }
    // all done

    int utret = untrace();
    if (utret <0) {
        printf("Could not unset the trace\n");
    }
    exit(0);
}