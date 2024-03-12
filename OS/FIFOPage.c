#include <stdio.h>

#define MAX_FRAMES 3

void fifoPageReplacement(int pages[], int n, int frames[]) {
    int pageFaults = 0;
    int frameIndex = 0;
    int frameFull = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pageFound = 0;

        for (int j = 0; j < frameFull; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            if (frameFull < MAX_FRAMES) {
                frames[frameFull] = page;
                frameFull++;
            } else {
                frames[frameIndex] = page;
                frameIndex = (frameIndex + 1) % MAX_FRAMES;
            }

            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[MAX_FRAMES] = {0};

    fifoPageReplacement(pages, n, frames);

    return 0;
}
