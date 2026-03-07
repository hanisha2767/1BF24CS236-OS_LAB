#include <stdio.h>

int main() {
    int n,i,j;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int pid[n],at[n],bt[n];
    int ct[n],tat[n],wt[n],rt[n];
    int start[n];
    for(i=0;i<n;i++)
    {
        pid[i]=i;
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[pid[i]] > at[pid[j]])
            {
                int temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    int time = 0;
    for(i=0;i<n;i++)
    {
        int p = pid[i];

        if(time < at[p])
            time = at[p];

        start[p] = time;
        rt[p] = start[p] - at[p];

        time += bt[p];
        ct[p] = time;

        tat[p] = ct[p] - at[p];
        wt[p] = tat[p] - bt[p];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }
    return 0;
}
