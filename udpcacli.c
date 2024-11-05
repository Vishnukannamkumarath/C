#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<arpa/inet.h>
#define port 5000
void main(){
struct sockaddr_in serveraddr,newaddr;
int clisocket,size;
char buffer[100];
clisocket=socket(AF_INET,SOCK_DGRAM,0);
if(clisocket>0){
printf("socket is created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
printf("Enter Data\n");
scanf("%s",buffer);
sendto(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
size=sizeof(newaddr);
recvfrom(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*)&newaddr,&size);
printf("Data received:%s\n",buffer);
close(clisocket);
}
