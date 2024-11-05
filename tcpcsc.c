#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
# define port 5000
void main(){
struct sockaddr_in serveraddr;
int clisocket;
char buffer[100];
clisocket=socket(PF_INET,SOCK_STREAM,0);
if(clisocket>0){
printf("socket is created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=PF_INET;
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clisocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("Enter Data:\n");
scanf("%s",buffer);
send(clisocket,buffer,sizeof(buffer),0);
close(clisocket);
}
