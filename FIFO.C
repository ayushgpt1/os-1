#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100

// Function to find if a page is present in memory
int findPage(int page, int *memory, int numFrames) {
int i; 
for (i = 0; i < numFrames; i++) {
        if (memory[i] == page) {
            return 1; // Page found
        }
    }
    return 0; // Page not found
}

// Function to replace a page using FIFO policy
void replacePage(int page, int *memory, int numFrames, int *nextIndex) {
    memory[*nextIndex] = page; // Replace the page at nextIndex
    *nextIndex = (*nextIndex + 1) % numFrames; // Move to the next frame in a circular fashion
}

int main() {
    int referenceString[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int numPages = sizeof(referenceString) / sizeof(referenceString[0]);
    int memory[MAX_PAGES]; // Memory to store pages
    int numFrames = 3; // Number of frames in memory
    int pageFaults = 0; // Count of page faults
    int nextIndex = 0; // Index to keep track of the next frame to replace
    int i,j;
    // Initialize memory
    for (i = 0; i < numFrames; i++) {
        memory[i] = -1; // -1 indicates an empty frame
    }

    // Simulate page replacement
    for (i = 0; i < numPages; i++) {
        int page = referenceString[i];
        if (!findPage(page, memory, numFrames)) {
            pageFaults++;
            replacePage(page, memory, numFrames, &nextIndex);
        }
        printf("Memory: ");
        for (j = 0; j < numFrames; j++) {
            if (memory[j] == -1)
                printf("Empty ");
            else
                printf("%d ", memory[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
