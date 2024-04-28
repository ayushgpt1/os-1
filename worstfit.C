#include <stdio.h>
#include <conio.h>

#define MAX_BLOCKS 10

void worstFit(int blocks[], int m, int processes[], int n) {
    int allocation[100];
    int i;
    int worst_fit_index=-1;
    int j;
    for (i = 0; i < n; i++) {
        // Initialize allocation for process i as -1 (indicating unallocated)
        allocation[i] = -1;

	// Find the worst fit block for current process
	for (j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (worst_fit_index == -1 || blocks[j] > blocks[worst_fit_index]) {
                    worst_fit_index = j;
                }
            }
        }

        // Allocate process i to the worst fit block
        if (worst_fit_index != -1) {
            allocation[i] = worst_fit_index;
            blocks[worst_fit_index] -= processes[i];
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
    worstFit(blocks, m, processes, n);

    getch(); // Waits for a key press before exiting
    return 0;
}
