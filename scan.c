#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int d[25],n,move,i,j,head,index,size,thm=0;
	printf("enter length of disk queue\n");
	scanf("%d",&n);
	printf("enter disk queue\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("enter current head position\n");
	scanf("%d",&head);
	printf("enter size of the disk\n");
	scanf("%d",&size);
	printf("enter direction of movement for 1 right side & 0 for left side\n");
	scanf("%d",&move);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(d[j]>d[j+1])
			{
				int temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(head<d[i])
		{
			index=i;
			break;
		}
	}
	if(move==1)
	{
		for(i=index;i<n;i++)
		{
			thm=thm+abs(head-d[i]);
			head=d[i];
		}
		thm=thm+abs(size-d[i-1]-1);
		head=size-1;
		for(i=index-1;i>=0;i--)
		{
			thm=thm+abs(head-d[i]);
			head=d[i];
		}
	}
	else
	{
		for(i=index-1;i>=0;i--)
		{
			thm=thm+abs(head-d[i]);
			head=d[i];
		}
		thm=thm+abs(d[i+1]-0);
		head=0;
		for(i=index;i<n;i++)
		{
			thm=thm+abs(head-d[i]);
			head=d[i];
		}
	}
	printf("total head movement=%d\n",thm);
}
		
			
	
	
