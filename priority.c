//non-premptive

#include <stdio.h>

int main()
{
    int bt[20], p[20], wt[20],pr[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("\nEnter number of process:");
    scanf("%d", &n);

    printf("\nEnter Burst Time and priority:\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d:", i + 1);
        printf(" Burst time : ");
        scanf("%d", &bt[i]);
        printf(" Priority: ");
        scanf("%d",&pr[i]);

        p[i] = i + 1;
    }

    // sorting of priority
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = (float)total / n;
    total = 0;

    printf("\nProcesst    Burst Time    tWaiting TimetTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = (float)total / n;
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f\n", avg_tat);
}