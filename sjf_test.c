#include<stdio.h>
struct node
{
	float burst_time;
	float wtime;
}p[10];
int main()
{
	float a[10],b[10],avgwtime,avgttime,s=0,f=0;
	int i,n,j;
	printf("enter no of process\n");
	scanf("%d",&n);
	printf("enter burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i].burst_time);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].burst_time>p[j+1].burst_time)
			{
				int temp=p[j].burst_time;
				p[j].burst_time=p[j+1].burst_time;
				p[j+1].burst_time=temp;
			}
		}
	}
	p[0].wtime=0;
	for(i=0;i<n;i++)
	{
		a[i]=p[0].wtime+p[i].burst_time+a[i-1];
	}
	for(i=0;i<n-1;i++)
	{
		s=s+a[i];
	}
	avgwtime=s/n;
	printf("average waiting time using sjf=%f\n",avgwtime);
	for(i=0;i<n;i++)
	{
		b[i]=p[i].burst_time+b[i-1];
	}
	for(i=0;i<n;i++)
	{
		f=f+b[i];
	}
	avgttime=f/n;
	printf("average turn around time using sjf=%f\n",avgttime);
}
