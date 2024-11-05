#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
# define port 5000
void main(){
	struct sockaddr_in serveraddr,newaddr;
	int sersocket,newsocket,s,size;
	char buffer[100];
	sersocket=socket(PF_INET,SOCK_STREAM,0);
	if(sersocket>0){
		printf("Socket created successfully\n");
	}
	serveraddr.sin_port=htons(port);
	serveraddr.sin_family=PF_INET;
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(s==0){
		printf("bind success\n");
	}
	listen(sersocket,1);
	size=sizeof(newaddr);
	printf("server ready\n");
	newsocket=accept(sersocket,(struct sockaddr*)&newaddr,&size);
	if(newsocket>0){
		printf("accept is done\n");
	}
	recv(newsocket,buffer,1024,0);
	printf("Data received:%s\n",buffer);
	close(sersocket);
}
