#include<stdio.h>
int fifo()
{
	int i,j,n,pf=0,f,m[10],rs[25],count=0,ph=0;
	printf("enter length of rs\n");
	scanf("%d",&n);
	printf("enter rs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter no of frames\n");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		m[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				ph++;
				break;
			}
		}
		if(j==f)
		{
			m[count]=rs[i];
			count++;
			pf++;
		}
		if(j!=f)
		{
			ph++;
		}
		for(j=0;j<f;j++)
		{
			printf("%d\t",m[j]);
		}
		if(j==f)
		{
			printf("PF=%d\n",pf);
		}
		if(j!=f)
		{
			printf("PH=%d\n",ph);
		}
		if(count==f)
		{
			count=0;
		}
	}
	printf("PF=%d\n",pf);
	printf("PH=%d\n",n-pf);
	return 0;
}
int lru()
{
	int i,j,m[10],count[10],flag[25],rs[25],n,f,pf=0,next=0,min;
	printf("enter length of rs\n");
	scanf("%d",&n);
	printf("enter rs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
		flag[i]=0;
	}
	printf("enter no of frames\n");
	scanf("%d",&f);
	for(j=0;j<f;j++)
	{
		m[j]=-1;
		count[j]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				flag[i]=1;
				count[i]=next;
				next++;
			}
		}
		if(flag[i]==0)
		{
			if(i<f)
			{
				m[i]=rs[i];
				count[i]=next;
				next++;
			}
			else
			{
				min=0;
				for(j=0;j<f;j++)
				{
					if(count[min]>count[j])
					{
						min=j;
					}
					count[min]=next;
					next++;
				}
				pf++;
			}
		}
		for(j=0;j<f;j++)
		{
			printf("%d\t",m[j]);
		}
		if(flag[i]==0)
		{
			printf("%d\n",pf);
		}
		printf("\n");
	}
	printf("PF=%d\n",pf);
	printf("PH=%d\n",n-pf);
	return 0;
}
int optimal()
{
	int i,j,k,m[10],rs[25],n,f,pf=0,flag[25]={0};
	printf("enter length of rs\n");
	scanf("%d",&n);
	printf("enter rs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
	}
	printf("enter no of frames\n");
	scanf("%d",&f);
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[j]==rs[i])
			{
				flag[i]=1;
				break;
			}
		}
		if(flag[i]==0)
		{
			int replace=-1;
			int future=i+1;
			for(j=0;j<f;j++)
			{
				int pfl=0;
				for(k=i+1;k<n;k++)
				{
					if(m[j]==rs[k])
					{
						pfl=1;
						if(k>future)
						{
							replace=j;
							future=k;
						}
						break;
					}
				}
				if(!pfl)
				{
					replace=j;
					break;
				}
			}
			m[replace]=rs[i];
			pf++;
		}
		for(j=0;j<f;j++)
		{
			printf("%d\t",m[j]);
		}
		if(flag[i]==0)
		{
			printf("PF=%d\n",pf);
		}
		printf("\n");
	}
	printf("PF=%d\n",pf);
	printf("PH=%d\n",n-pf);
	return 0;
}
int main()
{
	int opt;
	do
	{
		printf("enter option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			fifo();
			break;
			case 2:
			lru();
			break;
			case 3:
			optimal();
			break;
		}
	}while(opt!=4);
}

				
