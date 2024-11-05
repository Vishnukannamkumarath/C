#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int d[25],i,j,seek[25],index,key,n,head,sum[25],s=0;
	printf("enter length of disk queue\n");
	scanf("%d",&n);
	printf("enter disk queue\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("enter current head position\n");
	scanf("%d",&head);
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			seek[i]=abs(head-d[i]);
		}
		key=seek[0];
		for(i=0;i<n;i++)
		{
			if(seek[i]<=key)
			{
				key=seek[i];
				index=i;
			}
		}
		sum[j]=key;
		head=d[index];
		d[index]=100000;
	}
	for(i=0;i<n;i++)
	{
		s=s+sum[i];
	}
	printf("no of head movement=%d\n",s);
}
		
