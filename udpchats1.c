#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#define port 5000
int main(){
struct sockaddr_in serveraddr,newaddr;
int sersocket,s,size;
char buffer[100];
sersocket=socket(AF_INET,SOCK_DGRAM,0);
if(sersocket>0){
printf("socket is created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
s=bind(sersocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(s==0){
printf("bind success\n");
}
size=sizeof(newaddr);
while(1){
recvfrom(sersocket,buffer,sizeof(buffer),0,(struct sockaddr*)&newaddr,&size);
printf("From client:%s\t",buffer);
if(strcmp(buffer,"bye\n")==0){
break;
}
fgets(buffer,sizeof(buffer),stdin);
sendto(sersocket,buffer,sizeof(buffer),0,(struct sockaddr*)&newaddr,sizeof(newaddr));
}
close(sersocket);
}

