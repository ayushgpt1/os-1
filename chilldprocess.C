#include <stdio.h>
#include <unistd.h> // for fork

int main() {
    pid_t child_pid;

    // Fork a child process
    child_pid = fork();

    if (child_pid == 0) {
        // Code for child process
        printf("Child process: PID = %d\n", getpid());
    } else if (child_pid > 0) {
        // Code for parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
