#include <stdio.h>

int main(void) {
    int n, bt[50], pid[50], wt[50], tat[50], total_wt = 0, total_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n < 1 || n > 50) return 1;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (bt[i] > bt[j]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
    return 0;
}
