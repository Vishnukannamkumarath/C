#include<stdio.h>
#include<stdlib.h>
int main(){
	int s,choice,pi,i,n,ack,noack,ws;
	printf("enter no of packets\n");
	scanf("%d",&n);
	printf("enter window size\n");
	scanf("%d",&ws);
	while(1){
		printf("\n1.go-back\n2.selective repeate\n3.stop-wait\n4.exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			s=0;
			while(1){
				for(i=0;i<ws;i++){
					printf("Transmitted packet=%d\n",s+1);
					s++;
					if(s==ws)break;
				}
				ack=rand()%ws+1;
				if(ack==ws)break;
				else s=ack;
			}
			break;
			case 2:
			i=1;
			printf("Transmission start from:%d\n",n);
			while(i<=n){
				printf("Transmit packets from %d to%d\n",i,ws+i-1);
			for(pi=i;pi<ws+i;pi++){
				printf("transmitted packet:%d\n",pi);
			}
			noack=i+rand()%ws;
			if(noack==i){
				printf("transmitted packets=%d\n",ws+i);
				i=i+ws;
				continue;
			}
			printf("ack=%d\n",noack);
			printf("send packet:%d\n",noack);
			printf("ack=%d\n",noack+1);
			printf("ack=%d\n",ws+i);
			i=i+ws;
		}
		break;
		case 3:
		for(i=1;i<=n;i++){
			printf("Transmitted packets=%d\n",i);
			if(rand()%2==1){
				ack=rand()%2;
				if(ack==1){
					printf("ack no=%d\n",i+1);
				}
				else{
					printf("noack=%d\n",i+1);
				}
			}
			else{
				printf("time out\n");
				i--;
			}
		}
		break;
		case 4:
		break;
	}
	}
}
