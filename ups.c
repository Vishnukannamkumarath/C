#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#define port 4000
void main(){
struct sockaddr_in serveraddr,newaddr;
int sersocket,newsocket,s,size;
char buffer[100],buffer1[100],buffer2[100];
sersocket=socket(PF_INET,SOCK_STREAM,0);
if(sersocket>0){
printf("socket is created\n");
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
printf("accepted\n");
}
recv(newsocket,buffer,sizeof(buffer),0);
if(strcmp(buffer,"admin")==0){
recv(newsocket,buffer1,sizeof(buffer1),0);
if(strcmp(buffer1,"admin")==0){
strcpy(buffer2,"SUCCESS\n");
send(newsocket,buffer2,sizeof(buffer2),0);
}
else{
strcpy(buffer2,"PASSWORD NOT MATCH\n");
send(newsocket,buffer2,sizeof(buffer2),0);
}
}
else{
strcpy(buffer2,"USERNAME NOT MATCH\n");
send(newsocket,buffer2,sizeof(buffer2),0);
}

close(sersocket);
}
