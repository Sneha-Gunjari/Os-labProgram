/*Write C program to simulate the following CPU Scheduling algorithm for Round Robin */
#include<stdio.h>
#include <stdbool.h>
int turn_around_time(int process[],int n,int bt[],int wt[],int tat[]){
for(int i=0;i<n;i++){
tat[i] = bt[i] + wt[i];
}
}
int waiting_time(int process[],int n,int bt[],int wt[],int q){
int rem_bt[n];
for(int i=0;i<n;i++)
rem_bt[i] = bt[i];
int t =0;
while(1)
{
bool done =true;
for(int i=0;i<n;i++)
{
if(rem_bt[i]>0)
{
done = false;
if(rem_bt[i] >q)
{
t+= q;
rem_bt[i] -= q;
}
else
{
t += rem_bt[i];
wt[i] = t - bt[i];
rem_bt[i] = 0;
}
}
}
if(done == true)
break;
}    

}
int find_avg_time(int process[],int n,int bt[],int q)
{
int wt[n],tat[n],total_wt = 0,total_tat = 0;
waiting_time(process,n,bt,wt,q);
turn_around_time(process,n,bt,wt,tat);
printf("Process\tBurstTime\tWaitingTime\tTurnAroundTime\n");
for(int i=0;i<n;i++)
{
total_wt += wt[i];
total_tat += tat[i];
printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
}
printf("Average waiting time = %f\n",(float)total_wt/(float)n);
printf("Average turn arounf time = %f\n",(float)total_tat/(float)n);
}
int main(){

int n ,i,q;
printf("enter no of processes");
scanf("%d",&n);
int bt[n],process[n];
for(int i=0;i<n;i++){
     printf("process=");
     scanf("%d",&process[i]);
     printf("burst time:");
     scanf("%d",&bt[i]);
     }
printf("quantum=");
scanf("%d",&q);
find_avg_time(process,n,bt,q);
return 0;
}

