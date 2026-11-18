#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int n, a[100], even_sum = 0, odd_sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 1;

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    pid_t pid = fork();
    if (pid < 0) return 1;
    if (pid == 0) {
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0) even_sum += a[i];
        printf("Child: sum of even numbers = %d\n", even_sum);
        exit(0);
    } else {
        for (int i = 0; i < n; i++)
            if (a[i] % 2 != 0) odd_sum += a[i];
        wait(NULL);
        printf("Parent: sum of odd numbers = %d\n", odd_sum);
    }
    return 0;
}
