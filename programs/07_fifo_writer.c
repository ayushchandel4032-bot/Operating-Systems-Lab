#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    const char *path = "myfifo";
    char message[100];
    mkfifo(path, 0666);
    int fd = open(path, O_WRONLY);
    if (fd < 0) return 1;

    printf("Enter a message: ");
    if (fgets(message, sizeof(message), stdin)) {
        message[strcspn(message, "\n")] = '\0';
        write(fd, message, strlen(message) + 1);
    }
    close(fd);
    return 0;
}
