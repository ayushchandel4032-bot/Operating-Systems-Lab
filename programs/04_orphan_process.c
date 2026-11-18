#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) return 1;

    if (pid == 0) {
        sleep(5);
        printf("I am Child. My PID = %d and PPID = %d\n", getpid(), getppid());
    } else {
        printf("I am Parent. My Child PID = %d and my PID = %d\n", pid, getpid());
    }
    printf("Terminating PID = %d\n", getpid());
    return 0;
}
