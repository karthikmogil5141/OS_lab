#include <stdio.h>

int main() {
    int n, i, j, min_index, temp;
    int burst_time[100], waiting_time[100], turnaround_time[100], total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    for(i = 0; i < n; i++) {
        min_index = i;
        for(j = i + 1; j < n; j++) {
            if(burst_time[j] < burst_time[min_index]) {
                min_index = j;
            }
        }
        if(min_index != i) {
            temp = burst_time[i];
            burst_time[i] = burst_time[min_index];
            burst_time[min_index] = temp;
        }
    }

    waiting_time[0] = 0;
    for(i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        total_waiting_time += waiting_time[i];
    }

    for(i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    return 0;
}
