#include <stdio.h>

int main() {
    int n, quantum, i, time = 0, completed = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], remaining_time[n], waiting_time[n], turnaround_time[n];

    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
        remaining_time[i] = burst_time[i];
        waiting_time[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while (completed < n) {
        int all_done = 1;

        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                all_done = 0;
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i];
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }

        if (all_done)
            break;
    }

    for (i = 0; i < n; i++)
        turnaround_time[i] = burst_time[i] + waiting_time[i];

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
