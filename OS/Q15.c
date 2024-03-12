#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, total = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];

    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int direction;
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    int distance = 0;
    int current = head;

    if (direction == 0) {
        for (i = head; i >= 0; i--) {
            printf("%d ", i);
            distance += abs(current - requests[i]);
            current = requests[i];
        }
        distance += current;
        current = 0;
        for (i = head + 1; i < n; i++) {
            printf("%d ", i);
            distance += abs(current - requests[i]);
            current = requests[i];
        }
    } else {
        for (i = head; i < n; i++) {
            printf("%d ", i);
            distance += abs(current - requests[i]);
            current = requests[i];
        }
        distance += abs(current - (n - 1));
        current = n - 1;
        for (i = head - 1; i >= 0; i--) {
            printf("%d ", i);
            distance += abs(current - requests[i]);
            current = requests[i];
        }
    }

    printf("\nTotal distance: %d\n", distance);

    return 0;
}
