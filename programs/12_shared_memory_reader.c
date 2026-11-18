#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void) {
    key_t key = ftok(".", 'S');
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) return 1;

    char *ptr = (char *)shmat(shmid, NULL, 0);
    if (ptr == (char *)-1) return 1;

    printf("Shared memory contains: %s\n", ptr);
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
