#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define port 4000
void chat(int newsocket){
char buffer[100];
while(1){
recv(newsocket,buffer,sizeof(buffer),0);
printf("From Client:%s",buffer);
if(strcmp(buffer,"bye\n")==0){
break;
}
fgets(buffer,sizeof(buffer),stdin);
send(newsocket,buffer,sizeof(buffer),0);
}
}
int main(){
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
sersocket=socket(PF_INET,SOCK_STREAM,0);
if(sersocket>0){
printf("server socket is created\n");
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
printf("accepted successfully\n");
}
chat(newsocket);
close(newsocket);
return 0;
}
