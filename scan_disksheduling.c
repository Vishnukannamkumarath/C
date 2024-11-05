#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int rs[10],i,j,n,head,da[10],temp,key,k,s=0;
	printf("enter size of reference string\n");
	scanf("%d",&n);
	printf("enter elements in the reference string:\t");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter current head position:\t");
	scanf("%d",&head);
for(k=0;k<n;k++)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(rs[j]>rs[j+1])
			{
				temp=rs[j];
				rs[j]=rs[j+1];
				rs[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(rs[i]<head)
		{
			key=rs[i];
		}
		else if(rs[i]>head)
		{
			key=rs[i];
		}
		else
		{
			key=0;
		}
		
	}
	da[k]=abs(head-key);
	head=key;
}
for(i=0;i<n;i++)
{
	s=s+da[i];
}
printf("no of cylinders=%d",s);
}
