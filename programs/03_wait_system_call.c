#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) return 1;

    if (pid == 0) {
        printf("I am Child\n");
        exit(0);
    } else {
        wait(NULL);
        printf("I am Parent\n");
        printf("The Child PID = %d\n", pid);
    }
    return 0;
}
