#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#define port 5000
void chat(int newsocket)
{
	char buffer[100];
	while(1)
	{
		recv(newsocket,buffer,sizeof(buffer),0);
		printf("From client:%s\n",buffer);
		if(strcmp(buffer,"bye\n")==0)
		break;
		printf("To client:\n");
		fgets(buffer,sizeof(buffer),stdin);
		send(newsocket,buffer,sizeof(buffer),0);
	}
}
int main()
{
	struct sockaddr_in serveraddr,newaddr;
	int sersocket,newsocket,size,s;
	sersocket=socket(PF_INET,SOCK_STREAM,0);
	if(sersocket>0)
	{
		printf("socket is created\n");
	}
	serveraddr.sin_family=PF_INET;
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(s==0)
	{
		printf("bind success\n");
	}
	listen(sersocket,1);
	size=sizeof(newaddr);
	printf("server ready\n");
	newsocket=accept(sersocket,(struct sockaddr*)&serveraddr,&size);
	if(newsocket>0)
	{
		printf("accepted\n");
	}
	chat(newsocket);
	close(newsocket);
}
