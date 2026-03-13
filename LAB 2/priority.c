#include<stdio.h>

int main()
{
    int n,i,time=0,completed=0,choice;
    int at[10],bt[10],pr[10],rt[10];
    int ct[10],tat[10],wt[10],res[10];
    int start[10]={0};
    int visited[10]={0};
    float avg_tat,avg_wt,avg_rt;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT BT Priority for P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
        start[i]=-1;
    }

    printf("\n1. Priority Non-Preemptive\n");
    printf("2. Priority Preemptive\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    printf("\nGantt Chart:\n|");

    if(choice==1)
    {
        while(completed<n)
        {
            int idx=-1;
            int high=999;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && visited[i]==0)
                {
                    if(pr[i]<high)
                    {
                        high=pr[i];
                        idx=i;
                    }
                }
            }

            if(idx!=-1)
            {
                start[idx]=time;
                res[idx]=start[idx]-at[idx];

                printf(" P%d |",idx+1);

                time+=bt[idx];
                ct[idx]=time;

                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];

                visited[idx]=1;
                completed++;
            }
            else
            time++;
        }
    }

    else
    {
        while(completed<n)
        {
            int idx=-1;
            int high=999;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && rt[i]>0)
                {
                    if(pr[i]<high)
                    {
                        high=pr[i];
                        idx=i;
                    }
                }
            }

            if(idx!=-1)
            {
                if(start[idx]==-1)
                {
                    start[idx]=time;
                    res[idx]=start[idx]-at[idx];
                }

                printf(" P%d |",idx+1);

                rt[idx]--;
                time++;

                if(rt[idx]==0)
                {
                    ct[idx]=time;
                    tat[idx]=ct[idx]-at[idx];
                    wt[idx]=tat[idx]-bt[idx];
                    completed++;
                }
            }
            else
            time++;
        }
    }

    printf("\n\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

for(i=0;i<n;i++)
{
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i],res[i]);

    avg_tat += tat[i];
    avg_wt += wt[i];
    avg_rt += res[i];
}

avg_tat /= n;
avg_wt /= n;
avg_rt /= n;

printf("\nAverage Turnaround Time = %.2f", avg_tat);
printf("\nAverage Waiting Time = %.2f", avg_wt);
printf("\nAverage Response Time = %.2f\n", avg_rt);
}
