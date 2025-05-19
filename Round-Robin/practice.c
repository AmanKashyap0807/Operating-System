#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int rt;
    int ct;
    int wt;
    int tat;
};

void roundRobin(struct process *p, int n, int q)
{
    int t = 0;
    int done = 0;

    while (done < n)
    {
        done = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].rt > 0)
            {
                if (p[i].rt > q)
                {
                    t += q;
                    p[i].rt -= q;
                }
                else
                {
                    t += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = t;
                }
            }
            else
            {
                done++;
            }
        }
    }
}

void computeTimes(struct process *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void displayAndAverage(struct process *p, int n)
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

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[100];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].ct = 0;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobin(p, n, quantum);
    computeTimes(p, n);
    displayAndAverage(p, n);
    return 0;
}