# First Come First Serve (FCFS) Scheduling Algorithm

## What is FCFS?
First Come First Serve (FCFS) is the simplest CPU scheduling algorithm. In this scheduling algorithm, processes are executed in the order they arrive in the ready queue. It is a non-preemptive scheduling algorithm, meaning once a process starts execution, it continues until it completes or blocks for I/O.

## How FCFS Works
- Processes are allocated CPU in the order of their arrival
- The process that requests the CPU first gets allocated first
- It is implemented using a FIFO queue
- Once a process gets the CPU, it keeps it until termination or I/O wait

## Characteristics
- Non-preemptive scheduling algorithm
- Easy to understand and implement
- Fair to processes in order of arrival
- Poor in performance as average wait time can be high

## Algorithm Steps
1. Sort all processes by arrival time
2. For each process in order:
   - If CPU is free and process has arrived, allocate CPU
   - Calculate completion time, turnaround time, and waiting time
   - Move to next process when current one finishes

## Implementation (C++)
***Refer To main.c for ideal case***
***Refer To mainExtended.c for processes with arrival time case***

## Example
Consider the following set of processes with their arrival and burst times:

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| P1      | 0            | 6          |
| P2      | 1            | 4          |
| P3      | 2            | 2          |
| P4      | 3            | 5          |

### Solution using FCFS:

1. P1 arrives first at t=0, so it starts execution immediately
   - Completes at t=0+6=6
   - Turnaround time: 6-0=6
   - Waiting time: 6-6=0

2. P2 arrives at t=1, but must wait until P1 completes, so it starts at t=6
   - Completes at t=6+4=10
   - Turnaround time: 10-1=9
   - Waiting time: 9-4=5

3. P3 arrives at t=2, but must wait until P2 completes, so it starts at t=10
   - Completes at t=10+2=12
   - Turnaround time: 12-2=10
   - Waiting time: 10-2=8

4. P4 arrives at t=3, but must wait until P3 completes, so it starts at t=12
   - Completes at t=12+5=17
   - Turnaround time: 17-3=14
   - Waiting time: 14-5=9

### Gantt Chart:
```
 P1      |  P2   |  P3 |    P4    |
0        6       10    12         17
```

Average Turnaround Time = (6 + 9 + 10 + 14) / 4 = 9.75
Average Waiting Time = (0 + 5 + 8 + 9) / 4 = 5.5

## Advantages of FCFS
1. Simple and easy to understand
2. Easy to implement
3. No starvation as every process gets chance to execute
4. First job gets good response time

## Disadvantages of FCFS
1. Convoy Effect: Short processes behind long processes suffer
2. Long average waiting time
3. Not optimal for time-sharing systems
4. Not optimal for interactive environments
5. No prioritization of important processes

## Conclusion
FCFS is suitable for batch systems where process execution time is important, but not user interaction. Due to its simplicity, it's often used as a baseline for comparison with other more complex scheduling algorithms. However, for interactive systems and environments with varying process lengths, other algorithms like Shortest Job First (SJF), Round Robin, or Priority Scheduling usually perform better.
