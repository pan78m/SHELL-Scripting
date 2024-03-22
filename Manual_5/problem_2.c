#include <stdio.h>

void round_robin_scheduling(int processes[], int n, int burst_times[], int quantum) {
    int remaining_burst_time[n], waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int time = 0;

    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_times[i];
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = 0;
                if (remaining_burst_time[i] > quantum) {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    time += remaining_burst_time[i];
                    waiting_time[i] = time - burst_times[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_times[i] + waiting_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("Process %d\t Burst Time %d\t Waiting Time %d\t Turnaround Time %d\n", i + 1, burst_times[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int processes[] = {1, 2, 3, 4, 5};
    int burst_times[] = {10, 5, 8, 12, 4};
    int quantum = 3;
    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Round Robin CPU Scheduling Algorithm:\n");
    round_robin_scheduling(processes, n, burst_times, quantum);

    return 0;
}
