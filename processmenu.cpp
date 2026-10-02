#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void display_menu(void)
{
    printf("\n");
    printf("PROCESS CREATION AND TERMINATION\n");
    printf("1. Execute ls -l\n");
    printf("2. Execute sleep 5\n");
    printf("3. Execute an invalid command\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    fflush(stdout);
}

void report_child_status(pid_t child_pid, int status)
{
    if (WIFEXITED(status)) {
        printf("Child PID %d terminated normally.\n", child_pid);
        printf("Exit status %d.\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Child PID %d was terminated by signal %d.\n",
               child_pid, WTERMSIG(status));
    } else {
        printf("Child PID %d terminated abnormally (status = %d).\n",
               child_pid, status);
    }
}

void execute_ls(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        printf("Child process started. PID %d, Parent PID %d.\n",
               getpid(), getppid());
        printf("Child PID %d is executing ls -l.\n", getpid());
        fflush(stdout);

        execlp("ls", "ls", "-l", (char *)NULL);

        fprintf(stderr, "Child PID %d: execlp(\"ls\") failed: %s\n",
                getpid(), strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process PID %d created child PID %d.\n",
               getpid(), pid);
        printf("Parent process PID %d is waiting for child PID %d.\n",
               getpid(), pid);
        fflush(stdout);

        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            return;
        }

        report_child_status(pid, status);
        printf("Parent process PID %d resumed.\n", getpid());
    }
}

void execute_sleep(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        printf("Child process started. PID %d, Parent PID %d.\n",
               getpid(), getppid());
        printf("Child PID %d is executing sleep 5.\n", getpid());
        fflush(stdout);

        execlp("sleep", "sleep", "5", (char *)NULL);

        fprintf(stderr, "Child PID %d: execlp(\"sleep\") failed: %s\n",
                getpid(), strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process PID %d created child PID %d.\n",
               getpid(), pid);
        printf("Parent process PID %d is waiting for child PID %d.\n",
               getpid(), pid);
        fflush(stdout);

        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            return;
        }

        report_child_status(pid, status);
        printf("Parent process PID %d resumed.\n", getpid());
    }
}

void execute_invalid(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        printf("Child process started. PID %d, Parent PID %d.\n",
               getpid(), getppid());
        printf("Child PID %d is executing invalidcommand.\n", getpid());
        fflush(stdout);

        execlp("invalidcommand", "invalidcommand", (char *)NULL);

        fprintf(stderr,
                "Child PID %d: execlp(\"invalidcommand\") failed: %s\n",
                getpid(), strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process PID %d created child PID %d.\n",
               getpid(), pid);
        printf("Parent process PID %d is waiting for child PID %d.\n",
               getpid(), pid);
        fflush(stdout);

        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            return;
        }

        report_child_status(pid, status);
        printf("Parent process PID %d resumed.\n", getpid());
    }
}

int main(void)
{
    int choice;

    while (1) {
        display_menu();

        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Invalid input. Please enter a number 1-4.\n");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (choice) {
        case 1:
            execute_ls();
            break;
        case 2:
            execute_sleep();
            break;
        case 3:
            execute_invalid();
            break;
        case 4:
            printf("Exiting program. Goodbye!\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please select 1, 2, 3 or 4.\n");
            break;
        }
    }

    return 0;
}