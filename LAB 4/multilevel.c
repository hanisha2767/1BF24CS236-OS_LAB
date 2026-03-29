#include <stdio.h>
#include <string.h>

#define MAX 20

int main() {
    int n,i,j,time=0,comp=0,idx=0,cur=-1;
    int pid[MAX],at[MAX],bt[MAX],rt[MAX],ct[MAX],tat[MAX],wt[MAX],rtm[MAX],fe[MAX];
    char type[MAX][10];

    int sq[MAX],uq[MAX],sf=0,sr=-1,uf=0,ur=-1;
    int gp[200],gt[200],g=0;

    printf("Enter n: "); scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter  process ,at ,bt and type  :",i+1);
        scanf("%d%d%d%s",&pid[i],&at[i],&bt[i],type[i]);
        rt[i]=bt[i]; fe[i]=-1;
    }

    // sort by arrival time
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(at[i]>at[j]){
                int t;
                t=at[i];at[i]=at[j];at[j]=t;
                t=bt[i];bt[i]=bt[j];bt[j]=t;
                t=rt[i];rt[i]=rt[j];rt[j]=t;
                t=pid[i];pid[i]=pid[j];pid[j]=t;
                char tmp[10]; strcpy(tmp,type[i]); strcpy(type[i],type[j]); strcpy(type[j],tmp);
            }

    // ✅ MAIN LOOP (THIS WAS MISSING)
    while(comp < n){

        // add arrived processes
        while(idx<n && at[idx]<=time){
            if(strcmp(type[idx],"system")==0)
                sq[++sr] = idx;
            else
                uq[++ur] = idx;
            idx++;
        }

        // preemption
        if(cur!=-1 && strcmp(type[cur],"user")==0 && sf<=sr){
            uq[++ur] = cur;
            cur = -1;
        }

        // select process
        if(cur == -1){
            if(sf <= sr){
                cur = sq[sf++];
            }
            else if(uf <= ur){
                cur = uq[uf++];
            }
            else{
                time++;
                continue; // ✅ now valid (inside loop)
            }
        }

        // response time
        if(fe[cur]==-1){
            fe[cur]=time;
            rtm[cur]=time-at[cur];
        }

        // gantt
        gp[g]=cur;
        gt[g++]=time;

        // execute
        rt[cur]--;
        time++;

        // completion
        if(rt[cur]==0){
    ct[cur]=time;

    // ✅ Print completion message
    printf("\nProcess P%d completed at time %d\n", pid[cur], time);

    comp++;
    cur=-1;
}
    }

    gt[g]=time;

    float awt=0,atat=0,art=0;

    printf("\nP AT BT CT TAT WT RT\n");
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        awt+=wt[i]; atat+=tat[i]; art+=rtm[i];

        printf("P%d  %d  %d  %d  %d  %d  %d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rtm[i]);
    }

    printf("\nAvg TAT=%.2f\nAvg WT=%.2f\nAvg RT=%.2f\n",atat/n,awt/n,art/n);

    printf("\nGantt:\n|");
    for(i=0;i<g;i++) printf("P%d|",pid[gp[i]]);
    printf("\n %d",gt[0]);
    for(i=1;i<=g;i++) printf("  %d",gt[i]);

    return 0;
}
