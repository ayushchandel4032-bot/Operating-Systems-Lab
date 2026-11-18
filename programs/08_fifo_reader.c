#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    const char *path = "myfifo";
    char buffer[100];
    mkfifo(path, 0666);
    int fd = open(path, O_RDONLY);
    if (fd < 0) return 1;

    ssize_t count = read(fd, buffer, sizeof(buffer));
    if (count > 0) printf("Reader received: %s\n", buffer);
    close(fd);
    return 0;
}
