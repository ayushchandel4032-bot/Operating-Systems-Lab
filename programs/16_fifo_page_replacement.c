#include <stdio.h>

int main(void) {
    int n, frames, pages[100], frame[20], next = 0, faults = 0;
    printf("Enter reference string length: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 1;
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    if (frames < 1 || frames > 20) return 1;

    for (int i = 0; i < frames; i++) frame[i] = -1;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i]) found = 1;
        if (!found) {
            frame[next] = pages[i];
            next = (next + 1) % frames;
            faults++;
        }
        for (int j = 0; j < frames; j++)
            if (frame[j] == -1) printf("-\t");
            else printf("%d\t", frame[j]);
        printf("\n");
    }
    printf("Number of page faults: %d\n", faults);
    return 0;
}
