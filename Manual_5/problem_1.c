#include <stdio.h>

void priority_scheduling(int processes[], int n, int priorities[]) {
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;

    waiting_time[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1];
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("Process %d\t Priority %d\t Waiting Time %d\t Turnaround Time %d\n", i + 1, priorities[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int processes[] = {5, 3, 8, 6, 2};
    int priorities[] = {2, 1, 3, 2, 4};
    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Priority CPU Scheduling Algorithm:\n");
    priority_scheduling(processes, n, priorities);

    return 0;
}
