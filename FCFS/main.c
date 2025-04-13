#include <stdio.h>

void waitingTime(int *processes, int n, int *bt, int *wt)
{
    wt[0] = 0; // For ideal case first process will come at 0th time
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void turnAroundTime(int *processes, int n, int *bt, int *wt, int *tat)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void displayTime(int *processes, int n, int *bt, int *wt, int *tat)
{
    printf("Process \t Burst Time \t Waiting Time \t Turn Around Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d\n", processes[i], bt[i], wt[i], tat[i]);
    }
}

void averageTime(int *processes, int n, int *bt)
{
    int wt[n];
    int tat[n];
    waitingTime(processes, n, bt, wt);
    turnAroundTime(processes, n, bt, wt, tat);
    displayTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Average waiting time = %.2f\n", total_wt / n);
    printf("Average turn around time = %.2f\n", total_tat / n);
}

int main()
{
    // ask user for number of processes
    printf("Enter number of processes : ");
    int n;
    scanf("%d", &n);

    int processes[n];
    int bt[n];

    // ask user for burst time of each process
    for (int i = 0; i < n; i++)
    {
        processes[i] = i;
        printf("Enter the burst time for %d process : ", i);
        scanf("%d", &bt[i]);
    }
    averageTime(processes, n, bt);
    return 0;
}
