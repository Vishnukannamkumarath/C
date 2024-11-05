#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int disk_queue[10],i,n,j,seek_time[10],head,key,index,sum[10],s=0;
	printf("enter size of the queue\n");
	scanf("%d",&n);
	printf("enter elements into disk queue\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&disk_queue[i]);
	}
	printf("enter current head position\n");
	scanf("%d",&head);
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			seek_time[i]=abs(head-disk_queue[i]);
		}
		key=seek_time[0];
		for(i=0;i<n;i++)
		{
			if(seek_time[i]<=key)
			{
				key=seek_time[i];
				index=i;
			}
		}
		sum[j]=key;
		head=disk_queue[index];
		disk_queue[index]=100000;
		
	}
	for(i=0;i<n;i++)
	{
		s=s+sum[i];
	}
	printf("no of cylinders=%d",s);
}
	
		
			
