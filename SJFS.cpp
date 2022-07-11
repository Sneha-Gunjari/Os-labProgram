#include <stdio.h>
int main()
{
    int i,j;
    int pass,f,wt[10],bt[10],n,twt,tat[10],ttat,temp;
    float avgwt,avgtat;
    printf("Enter the No.of Processors : ");
    scanf("%d",&n);
    printf("Enter the Brust Time : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    for(pass = 0;pass < n-1;pass++)
    {
        f=0;
        for(j=0;j<n-pass-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                temp=bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                f=1;
            }
        }
        if(f==0)
        break;
    }
    printf("Sorted Brust Times are \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",bt[i]);
    }
    wt[0] = 0;
    for(i=1;i<n;i++)

    {
        wt[i] = bt[i-1]+wt[i-1];
        twt+=wt[i];
    }
    printf("Waiting time for the processor : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",wt[i]);
    }
    for(i=0;i<n;i++)
    {
        tat[i] = wt[i]+bt[i];
        ttat+=tat[i];
    }
    printf("Turn Around time \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",tat[i]);
    }
    printf("Average waiting time :%f\n" ,twt/(float)n);
    printf("Averaget turn around time :%f\n",ttat/(float)n);
    return 0;
    
    
}

