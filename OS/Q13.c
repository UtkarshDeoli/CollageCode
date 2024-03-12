#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int counter[MAX_FRAMES];
    int page_faults = 0;
    int i, j, k, min, flag, found, position;

    printf("Enter the page reference string: ");
    for (i = 0; i < MAX_PAGES; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }

    for (i = 0; i < MAX_PAGES; i++) {
        found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                counter[j] = i;
                break;
            }
        }

        if (found == 0) {
            min = 0;
            for (j = 1; j < MAX_FRAMES; j++) {
                if (counter[j] < counter[min]) {
                    min = j;
                }
            }
            frames[min] = pages[i];
            counter[min] = i;
            page_faults++;
        }

        printf("\nPage reference: %d\n", pages[i]);
        printf("Frames: ");
        for (k = 0; k < MAX_FRAMES; k++) {
            printf("%d ", frames[k]);
        }
    }

    printf("\n\nTotal page faults: %d\n", page_faults);

    return 0;
}
