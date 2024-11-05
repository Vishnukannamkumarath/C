#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define port 4000
int main(){
struct sockaddr_in serveraddr;
int clisocket,size;
char buffer[100];
clisocket=socket(AF_INET,SOCK_DGRAM,0);
if(clisocket>0){
printf("socket created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
while(1){
fgets(buffer,sizeof(buffer),stdin);
sendto(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
size=sizeof(serveraddr);
recvfrom(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*)&serveraddr,&size);
printf("From server:%s\t",buffer);
if(strcmp(buffer,"bye\n")==0){
break;
}
}
close(clisocket);
}
