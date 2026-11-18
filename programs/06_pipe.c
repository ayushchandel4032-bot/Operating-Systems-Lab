#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];
    char message[100], buffer[100];
    if (pipe(fd) == -1) return 1;

    pid_t pid = fork();
    if (pid < 0) return 1;

    if (pid == 0) {
        close(fd[0]);
        printf("Enter a string: ");
        if (!fgets(message, sizeof(message), stdin)) exit(1);
        message[strcspn(message, "\n")] = '\0';
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
        exit(0);
    } else {
        close(fd[1]);
        ssize_t count = read(fd[0], buffer, sizeof(buffer));
        if (count > 0) printf("Parent read: %s\n", buffer);
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}
