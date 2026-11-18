#include <stdio.h>
#include <unistd.h>

int main(void) {
    fork();
    printf("LINUX\n");
    return 0;
}
