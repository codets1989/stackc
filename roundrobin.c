#include <stdio.h>

int main() {
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], remaining[n];
    int waiting[n], turnaround[n];

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);

        remaining[i] = burst[i];
        waiting[i] = 0;
        turnaround[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int time = 0;
    int done;

    printf("\nRound Robin Schedule:\n");
    printf("0");

    do {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;

                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    turnaround[i] = time;
                    waiting[i] = turnaround[i] - burst[i];
                    remaining[i] = 0;
                }

                printf(" --P%d--> %d", i + 1, time);
            }
        }
    } while (!done);

    double totalWT = 0, totalTAT = 0;

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t\t%d\t\t\t\t%d\n",
               i + 1,
               burst[i],
               waiting[i],
               turnaround[i]);

       
        totalWT += waiting[i];
        totalTAT += turnaround[i];
    }
   


    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}