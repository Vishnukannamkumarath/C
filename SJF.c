#include<stdio.h>
#include<stdlib.h>
struct job
{
	float burst_time;
	float waiting_time;
}p[10];
int main()
{
	int i,n,j,temp;
	float a[10];
	float avg=0;
	float avg_waiting_time;
	printf("enter number of processes\n");
	scanf("%d",&n);
	printf("enter burst time each proccess\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i].burst_time);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].burst_time>p[j+1].burst_time)
			{
				temp=p[j].burst_time;
				p[j].burst_time=p[j+1].burst_time;
				p[j+1].burst_time=temp;
			}
		}
	}
	p[0].waiting_time=0;
	for(i=0;i<n-1;i++)
	{
		a[i]=p[0].waiting_time+p[i].burst_time+a[i-1];
	}
	for(i=0;i<n-1;i++)
	{
		avg=a[i]+avg;
	}
	avg_waiting_time=avg/n;
	printf("average waiting time=%fms",avg_waiting_time);
}
	
	
	
