#include <stdio.h>

int main() {
    int n, i, j, total_wt = 0, total_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], wt[n], tat[n], completed[n];

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        completed[i] = 0;
    }

    int time = 0;
    for(i = 0; i < n; i++) {
        int min_index = -1;
        for(j = 0; j < n; j++) {
            if(completed[j] == 0 && at[j] <= time) {
                if(min_index == -1 || bt[j] < bt[min_index]) {
                    min_index = j;
                }
            }
        }

        if(min_index != -1) {
            time += bt[min_index];
            tat[min_index] = time - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            completed[min_index] = 1;
        } else {
            time++;
            i--;
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
