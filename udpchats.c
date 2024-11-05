#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#define port 5000
void chat(int sersocket,struct serveraddr,struct newaddr){
char buffer[100];
while(1){
recvfrom(sersocket,buffer,sizeof(buffer),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("From Client:%s",buffer);
if(strcmp(buffer,"bye\n")==0){
break;
}
fgets(buffer,sizeof(buffer),stdin);
sendto(sersocket,buffer,sizeof(buffer),0,(struct sockaddr*)&newaddr,sizeof(newaddr));
}
}
int main(){
struct sockaddr_in serveraddr,newaddr;
int sersocket,s,size;
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
chat(sersocket,serveraddr,newaddr);
close(sersocket);
}
