#Priority CPU Scheduling Algorithm:
def priority_scheduling(processes, priorities):
    n = len(processes)
    waiting_time = [0] * n
    turnaround_time = [0] * n

    # Sort processes based on priority
    sorted_processes = sorted(zip(processes, priorities), key=lambda x: x[1])

    waiting_time[0] = 0

    # Calculate waiting time for each process
    for i in range(1, n):
        waiting_time[i] = waiting_time[i - 1] + sorted_processes[i - 1][0]

    # Calculate turnaround time for each process
    for i in range(n):
        turnaround_time[i] = waiting_time[i] + sorted_processes[i][0]

    print("Process\tPriority\tWaiting Time\tTurnaround Time")
    total_waiting_time = 0
    total_turnaround_time = 0
    for i in range(n):
        total_waiting_time += waiting_time[i]
        total_turnaround_time += turnaround_time[i]
        print(f"{sorted_processes[i][0]}\t{sorted_processes[i][1]}\t\t{waiting_time[i]}\t\t{turnaround_time[i]}")

    print(f"\nAverage Waiting Time: {total_waiting_time / n}")
    print(f"Average Turnaround Time: {total_turnaround_time / n}")


# Example usage:
processes = [1, 2, 3, 4, 5]
priorities = [2, 1, 3, 2, 4]
priority_scheduling(processes, priorities)
