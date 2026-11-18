#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) return 1;

    if (pid == 0) {
        printf("Child executing date command:\n");
        execl("/bin/date", "date", (char *)NULL);
        perror("execl");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent executing ls -l command:\n");
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        perror("execl");
    }
    return 0;
}
