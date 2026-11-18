#include <stdio.h>
#include <string.h>
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
    msg.type = 1;
    printf("Enter a message: ");
    if (!fgets(msg.text, sizeof(msg.text), stdin)) return 1;
    msg.text[strcspn(msg.text, "\n")] = '\0';

    if (msgsnd(msgid, &msg, strlen(msg.text) + 1, 0) == -1) return 1;
    printf("Message sent: %s\n", msg.text);
    return 0;
}
