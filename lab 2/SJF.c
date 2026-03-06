#include<stdio.h>
int main()
{
    int n,i,choice;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int at[n],bt[n];
    int ct[n],tat[n],wt[n],rt[n];
    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    printf("\n 1.SJF Non Preemptive");
    printf("\n 2.SJF Preemptive");
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    if(choice==1)
    {
        int time=0,completed=0;
        int visited[10]={0};
        while(completed<n)
        {
            int idx=-1,min=9999;
            for(i=0;i<n;i++)
            {
                if(at[i]<=time && visited[i]==0 && bt[i]<min)
                {
                    min=bt[i];
                    idx=i;
                }
            }
            if(idx!=-1)
            {
                rt[idx]=time-at[idx];
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
    else if(choice==2)
    {
        int time=0,completed=0;
        int rbt[10];
        int first[10]={0};
        for(i=0;i<n;i++)
            rbt[i]=bt[i];
        while(completed<n)
        {
            int idx=-1,min=9999;
            for(i=0;i<n;i++)
            {
                if(at[i]<=time && rbt[i]>0 && rbt[i]<min)
                {
                    min=rbt[i];
                    idx=i;
                }
            }
            if(idx!=-1)
            {
                if(first[idx]==0)
                {
                    rt[idx]=time-at[idx];
                    first[idx]=1;
                }
                rbt[idx]--;
                time++;
                if(rbt[idx]==0)
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
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }
    return 0;
}
