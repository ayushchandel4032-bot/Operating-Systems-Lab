#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) return 1;

    if (pid == 0) {
        printf("Child process exiting. PID = %d\n", getpid());
        exit(0);
    } else {
        printf("Parent sleeping. Check the process table for a zombie child.\n");
        sleep(30);
    }
    return 0;
}
