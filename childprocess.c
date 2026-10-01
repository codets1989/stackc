#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void executeCommand(int choice);

int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf("PROCESS CREATION AND TERMINATION\n");
        printf("========================================\n");
        printf("1. Execute ls -l\n");
        printf("2. Execute sleep 5\n");
        printf("3. Execute an invalid command\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                executeCommand(1);
                break;

            case 2:
                executeCommand(2);
                break;

            case 3:
                executeCommand(3);
                break;

            case 4:
                printf("\nParent process is exiting. Goodbye!\n");
                break;

            default:
                printf("\nInvalid menu choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void executeCommand(int choice) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        /* Child process */

        printf("\n--- Child Process ---\n");
        printf("Child process PID: %d\n", getpid());
        printf("Parent PID of child: %d\n", getppid());

        if (choice == 1) {
            printf("Command child will execute: ls -l\n");

            execlp("ls", "ls", "-l", (char *)NULL);

            /* Only reached if exec fails */
            perror("exec failed");
            exit(1);
        }
        else if (choice == 2) {
            printf("Command child will execute: sleep 5\n");

            execlp("sleep", "sleep", "5", (char *)NULL);

            /* Only reached if exec fails */
            perror("exec failed");
            exit(1);
        }
        else if (choice == 3) {
            printf("Command child will execute: invalidcommand\n");

            execlp("invalidcommand", "invalidcommand", (char *)NULL);

            /* exec must fail for this option */
            perror("exec failed");
            exit(1);
        }
    }
    else {
        /* Parent process */

        printf("\n--- Parent Process ---\n");
        printf("Parent process PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);

        printf("Parent is waiting for the child...\n");

        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child terminated normally.\n");
            printf("Child exit status: %d\n", WEXITSTATUS(status));
        }
        else {
            printf("Child did not terminate normally.\n");
        }

        printf("Parent resumed after the child terminated.\n");
    }
}