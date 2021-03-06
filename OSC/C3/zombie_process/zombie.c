// Just demo code show how to create a zombie process

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main(void) {

    pid_t pid;
    // fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork error \n");
        return 1;
    } else if (pid == 0) {
        // in child process, fork() return 0 in child process
        // return child process id in parent process
        exit(0);
    } else {
        // as parent process still alive, but not wait() child process
        // the child process become zombie process
        fprintf(stderr, "Parent go to complete, but not wait child.\n");
        sleep(30);
        exit(0);
    }

    return 0;
}
