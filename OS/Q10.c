#include <stdio.h>

#define MAX_FRAMES 3

void fifoPageReplacement(int pages[], int n, int frames[]) {
    int pageFaults = 0;
    int frameIndex = 0;
    int frameFull = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pageFound = 0;

        // Check if the page is already present in the frames
        for (int j = 0; j < frameFull; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If page not found, replace the oldest page in the frame
        if (!pageFound) {
            frames[frameIndex] = page;
            frameIndex = (frameIndex + 1) % MAX_FRAMES;
            if (frameFull < MAX_FRAMES) {
                frameFull++;
            }
            pageFaults++;
        }

        // Print the current state of frames
        printf("Frames: ");
        for (int j = 0; j < frameFull; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int n;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int frames[MAX_FRAMES] = {0};

    fifoPageReplacement(pages, n, frames);

    return 0;
}
