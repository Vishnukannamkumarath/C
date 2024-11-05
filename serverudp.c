#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
# define port 4000
void main()
{
	time_t ticks;
	struct sockaddr_in serveraddr,newaddr;
	int sersocket,s,size;
	char buffer[100],str[100];
	sersocket=socket(AF_INET,SOCK_DGRAM,0);
	if(sersocket>0)
	{
		printf("socket created successfull\n");
	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(s==0)
	{
		printf("bind success\n");
	}
	size=sizeof(newaddr);
	recvfrom(sersocket,buffer,sizeof(buffer),0,(struct sockaddr*)&serveraddr,&size);
	printf("data received:%s\n",buffer);
	ticks=time(NULL);
	strcpy(str,ctime(&ticks));
	snprintf(buffer,sizeof(buffer),"%s",str);
	sendto(sersocket,buffer,sizeof(buffer),0,(struct sockaddr*)&newaddr,sizeof(newaddr));
	printf("\n");
	close(sersocket);
}
	

