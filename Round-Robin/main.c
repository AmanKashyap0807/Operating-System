#include <stdio.h>

#define MAX_PROCESSES 100

// Process structure
struct Process
{
    int pid; // Process ID
    int bt;  // Burst Time
    int rt;  // Remaining Time
    int ct;  // Completion Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

// Step 3: Read n, burst times, init fields, read quantum
void inputProcesses(struct Process p[], int *n, int *quantum)
{
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt; // remaining = burst
        p[i].ct = 0;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", quantum);
}

// Step 7: Round‑Robin simulation; record completion times
void roundRobin(struct Process p[], int n, int quantum)
{
    int t = 0;    // current time
    int done = 0; // count of finished processes

    while (done < n)
    {
        done = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].rt > 0)
            {
                // give CPU for quantum or remaining time
                if (p[i].rt > quantum)
                {
                    t += quantum;
                    p[i].rt -= quantum;
                }
                else
                {
                    t += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = t; // record finish time
                }
            }
            else
            {
                done++;
            }
        }
    }
}

// Step 7b: Compute TAT and WT from CT
void computeTimes(struct Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct; // arrival = 0
        p[i].wt = p[i].tat - p[i].bt;
    }
}

// Step 8: Display and average
void displayAndAverage(struct Process p[], int n)
{
    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    printf("\nAverage Waiting Time    = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

// Step 1 & 9: main driver
int main()
{
    struct Process p[MAX_PROCESSES];
    int n, quantum;

    inputProcesses(p, &n, &quantum);
    roundRobin(p, n, quantum);
    computeTimes(p, n);
    displayAndAverage(p, n);
    return 0;
}
