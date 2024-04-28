#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

// Function to calculate the total head movement
int calculateTotalHeadMovement(int head, int *requests, int num_requests) {
    int total_movement = 0;
    int current_position = head;
    int i;
    for (i = 0; i < num_requests; i++) {
        total_movement += abs(requests[i] - current_position);
        current_position = requests[i];
    }
    
    return total_movement;
}

int main() {
    int head_position, num_requests;
    int request_queue[MAX_REQUESTS];
    int i;
    printf("Enter the current head position: ");
    scanf("%d", &head_position);
    
    printf("Enter the number of requests: ");
    scanf("%d", &num_requests);
    
    printf("Enter the disk request queue: ");
    for (i = 0; i < num_requests; i++) {
        scanf("%d", &request_queue[i]);
    }
    
    // Print total head movement directly without saving in a variable
    printf("Total head movement for FCFS: %d\n", calculateTotalHeadMovement(head_position, request_queue, num_requests));
    
    return 0;
}
