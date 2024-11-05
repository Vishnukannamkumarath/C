#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#define port 5000
void chat(int clisocket){
char buffer[100];
while(1){
printf("To server:\t");
fgets(buffer,sizeof(buffer),stdin);
send(clisocket,buffer,sizeof(buffer),0);
recv(clisocket,buffer,sizeof(buffer),0);
printf("From server:%s\t",buffer);
if(strcmp(buffer,"bye\n")==0){
break;
}
}
}
int main(){
struct sockaddr_in serveraddr;
int clisocket;
clisocket=socket(AF_INET,SOCK_DGRAM,0);
if(clisocket>0){
printf("socket is created\n");
}
serveraddr.sin_port=htons(port);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
chat(clisocket);
close(clisocket);
}


