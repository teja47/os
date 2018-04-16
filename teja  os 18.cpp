#include<stdio.h>
 
int main()
{
    int a[20],p[20],wt[20],tat[20],pr[20],i,j,n,t=0,po,temp,avg_wt,avg_tat,f;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 	printf("PRESS 0 FOR THE CONTINUOUS TO PRIORITY PRESS 1 FOR EXIT FROM THE PROGRAMM \n");
 	scanf("%d",&f);
 	if(f==0)
 	{
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&a[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;         
    }
 

    for(i=0;i<n;i++)
    {
        po=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[po])
                po=j;
        }
 
        temp=pr[i];
        pr[i]=pr[po];
        pr[po]=temp;
 
        temp=a[i];
        a[i]=a[po];
        a[po]=temp;
 
        temp=p[i];
        p[i]=p[po];
        p[po]=temp;
    }
 
    wt[0]=0;    
 
  
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=a[j];
 
        t+=wt[i];
    }
 
    avg_wt=t/n;      
    t=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=a[i]+wt[i];     
        t+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],a[i],wt[i],tat[i]);
    }
 
    avg_tat=t/n;     
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
}
else
{
	printf("You have selected exit from the programm \n");
}
    return 0;
}
