#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

void displayMenu(void) {
    printf("\n========================================\n");
    printf("PROCESS CREATION AND TERMINATION\n");
    printf("========================================\n");
    printf("1. Execute ls -l\n");
    printf("2. Execute sleep 5\n");
    printf("3. Execute an invalid command\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void executeCommand(char *const argv[], const char *cmdDisplay) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }
    else if (pid == 0) {
        /* CHILD */
        printf("Child process started. PID %d, Parent PID %d.\n",
               getpid(), getppid());
        printf("Child PID %d is executing %s.\n", getpid(), cmdDisplay);

        execvp(argv[0], argv);

        /* exec failed */
        fprintf(stderr, "Child PID %d: exec failed for '%s': %s\n",
                getpid(), argv[0], strerror(errno));
        exit(EXIT_FAILURE);
    }
    else {
        /* PARENT */
        printf("Parent process PID %d created child PID %d.\n",
               getpid(), pid);
        printf("Parent process PID %d is waiting for child PID %d.\n",
               getpid(), pid);

        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            return;
        }

        if (WIFEXITED(status)) {
            printf("Child PID %d terminated normally.\n", pid);
            printf("Exit status %d.\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status)) {
            printf("Child PID %d was terminated by signal %d.\n",
                   pid, WTERMSIG(status));
        }
        else {
            printf("Child PID %d terminated abnormally.\n", pid);
        }

        printf("Parent process PID %d resumed.\n", getpid());
    }
}

int main(void) {
    int choice;

    while (1) {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            continue;
        }

        switch (choice) {
            case 1: {
                char *args[] = { "ls", "-l", NULL };
                executeCommand(args, "ls -l");
                break;
            }
            case 2: {
                char *args[] = { "sleep", "5", NULL };
                executeCommand(args, "sleep 5");
                break;
            }
            case 3: {
                char *args[] = { "invalidcommand", NULL };
                executeCommand(args, "invalidcommand");
                break;
            }
            case 4:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
                break;
        }
    }

    return 0;
}