#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 10

void worstFit(int blocks[], bool used[], int m, int processes[], int n) {
    int allocation[100];
    int i;
    int worst_fit_index;
    int j;
    for (i = 0; i < n; i++) {
        // Initialize allocation for process i as -1 (indicating unallocated)
        allocation[i] = -1;

        // Find the worst fit block for current process
        worst_fit_index = -1; // Reset worst_fit_index for each process
        for (j = 0; j < m; j++) {
            if (!used[j] && blocks[j] >= processes[i]) {
                if (worst_fit_index == -1 || blocks[j] > blocks[worst_fit_index]) {
                    worst_fit_index = j;
                }
            }
        }

        // Allocate process i to the worst fit block
        if (worst_fit_index != -1) {
            allocation[i] = worst_fit_index;
            blocks[worst_fit_index] -= processes[i];
            used[worst_fit_index] = true; // Mark the block as used
        }
    }

    // Print the allocation
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blocks[MAX_BLOCKS], processes[MAX_BLOCKS];
    bool used[MAX_BLOCKS] = {false}; // Array to keep track of used blocks
    int m, n;
    int i;
    // Input the number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    // Input the sizes of memory blocks
    printf("Enter the sizes of memory blocks:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &blocks[i]);
    }

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the sizes of processes
    printf("Enter the sizes of processes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }

    // Call the worst fit memory allocation function
    worstFit(blocks, used, m, processes, n);

    // Waits for a key press before exiting
    return 0;
}
