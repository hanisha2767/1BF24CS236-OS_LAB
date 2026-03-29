#include <stdio.h>

int main() {
    int n, i, time = 0, tq, remain;
    int at[10], bt[10], rt[10];
    int ct[10], tat[10], wt[10], response[10];
    int first_exec[10];

    // Gantt Chart
    int gantt_p[100], gantt_t[100];
    int g_index = 0;

    float total_wt = 0, total_tat = 0, total_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
        first_exec[i] = -1;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);



    while(remain != 0) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                done = 0;

                // Response Time
                if(first_exec[i] == -1) {
                    first_exec[i] = time;
                    response[i] = time - at[i];
                }

                // Add to Gantt chart
                gantt_p[g_index] = i;
                gantt_t[g_index] = time;
                g_index++;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    remain--;
                }
            }
        }

        if(done) {
            time++;
        }
    }

    gantt_t[g_index] = time;

    // Calculations
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
        total_rt += response[i];
    }

     // Gantt Chart
    printf("\nGantt Chart:\n");

    printf("|");
    for(i = 0; i < g_index; i++) {
        printf(" P%d |", gantt_p[i] + 1);
    }

    printf("\n0");
    for(i = 0; i < g_index; i++) {
        printf("    %d", gantt_t[i + 1]);
    }

    printf("\n");

    // Output Table
    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i], response[i]);
    }

    printf("\nAverage TAT = %.2f", total_tat / n);
    printf("\nAverage WT = %.2f", total_wt / n);
    printf("\nAverage RT = %.2f\n", total_rt / n);

    return 0;
}
