#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void createChild();
void childExecute();

int main() {
    int choice;

    do {
        printf("\n===== PROCESS MANAGEMENT MENU =====\n");
        printf("1. Create Child Process\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createChild();
                break;

            case 2:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 2);

    return 0;
}

void createChild() {
    pid_t pid;
    int status;

    printf("\nParent process is creating a child...\n");

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        // Child process
        childExecute();

        // This runs only if exec fails
        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent process PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);

        printf("Parent is waiting for the child...\n");

        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child terminated normally.\n");
            printf("Child exit status: %d\n", WEXITSTATUS(status));
        }
        else {
            printf("Child did not terminate normally.\n");
        }
    }
}

void childExecute() {
    printf("Child process is executing another program...\n");

    // Execute the "ls" program
    execlp("ls", "ls", "-l", NULL);
}