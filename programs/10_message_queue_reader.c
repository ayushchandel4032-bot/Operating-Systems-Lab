#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long type;
    char text[100];
};

int main(void) {
    key_t key = ftok(".", 'A');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) return 1;

    struct message msg;
    if (msgrcv(msgid, &msg, sizeof(msg.text), 1, 0) == -1) return 1;
    printf("Received message: %s\n", msg.text);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
