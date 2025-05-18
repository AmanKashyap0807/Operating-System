#include <stdio.h>

struct processes
{
    int p_id;
    int bt;
    int wt;
    int tat;
};

void sortProcesses(struct processes *p, int n)
{
    struct processes temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].bt > p[j].bt)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void waitingTime(struct processes *p, int n)
{
    p[0].wt = 0;
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }
}

void turnAroundTime(struct processes *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].bt + p[i].wt;
    }
}

void displayTime(struct processes *p, int n)
{
    printf("Process \t Burst Time \t Waiting Time \t Turn Around Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d\n", p[i].p_id, p[i].bt, p[i].wt, p[i].tat);
    }
}

void averageTime(struct processes *p, int n)
{
    waitingTime(p, n);
    turnAroundTime(p, n);
    displayTime(p, n);
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    printf("Average waiting time = %.2f\n", total_wt / n);
    printf("Average turn around time = %.2f\n", total_tat / n);
}

int main()
{
    struct processes p[100];
    int n;
    printf("Enter number of processes : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        p[i].p_id = i + 1;
        printf("Enter burst time for the process %d :", i + 1);
        scanf("%d", &p[i].bt);
    }

    sortProcesses(p, n);
    averageTime(p, n);
    return 0;
}