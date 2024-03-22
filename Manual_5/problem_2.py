#Round Robin CPU Scheduling Algorithm:
def round_robin_scheduling(processes, burst_times, quantum):
    n = len(processes)
    remaining_burst_time = burst_times[:]
    waiting_time = [0] * n
    turnaround_time = [0] * n
    time = 0

    while True:
        done = True
        for i in range(n):
            if remaining_burst_time[i] > 0:
                done = False
                if remaining_burst_time[i] > quantum:
                    time += quantum
                    remaining_burst_time[i] -= quantum
                else:
                    time += remaining_burst_time[i]
                    waiting_time[i] = time - burst_times[i]
                    remaining_burst_time[i] = 0

        if done:
            break

    for i in range(n):
        turnaround_time[i] = burst_times[i] + waiting_time[i]

    print("Process\tBurst Time\tWaiting Time\tTurnaround Time")
    total_waiting_time = 0
    total_turnaround_time = 0
    for i in range(n):
        total_waiting_time += waiting_time[i]
        total_turnaround_time += turnaround_time[i]
        print(f"{processes[i]}\t{burst_times[i]}\t\t{waiting_time[i]}\t\t{turnaround_time[i]}")

    print(f"\nAverage Waiting Time: {total_waiting_time / n}")
    print(f"Average Turnaround Time: {total_turnaround_time / n}")


# Example usage:
processes = [1, 2, 3, 4, 5]
burst_times = [10, 5, 8, 12, 4]
quantum = 3
round_robin_scheduling(processes, burst_times, quantum)
