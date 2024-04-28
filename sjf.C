#include <stdio.h>

#define MAX_PROCESSES 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sjf(int processes[], int n, int burst_times[]) {
    // Sort processes based on burst time using bubble sort
    int i, j;
    int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if (burst_times[j] > burst_times[j + 1]) {
                swap(&burst_times[j], &burst_times[j + 1]);
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    // Calculate waiting time for each process
    waiting_time[0] = 0;
    for(i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for(j = 0; j < i; j++)
            waiting_time[i] += burst_times[j];
    }

    // Calculate turnaround time for each process
    for(i = 0; i < n; i++)
        turnaround_time[i] = burst_times[i] + waiting_time[i];

    // Print the order of execution and waiting/turnaround time for each process
    printf("Order of execution:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", processes[i]);
    }
    printf("\n");

    printf("Process\t Waiting Time\t Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t %d\t\t %d\n", processes[i], waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n, i;
    int processes[MAX_PROCESSES], burst_times[MAX_PROCESSES];

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the burst times for each process
    printf("Enter the burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_times[i]);
        processes[i] = i + 1; // Assign process IDs
    }

    // Call the SJF function
    sjf(processes, n, burst_times);

    return 0;
}
