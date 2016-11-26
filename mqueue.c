#include <stdio.h>
#include "queue.h"

int main(){
	int max;
	Queue Q,Q1;
	printf("masukkan jumlah maks elemen queue\n");
	scanf("%d",&max);
	//cek create empty, is empty, is full, dan AddQ
	CreateEmptyQ(&Q,max);
	CreateEmptyQ(&Q1,max);
	if(IsEmptyQ(Q)){
		printf("queue kosong\n");
	}else{
		printf("queue tidak kosong\n");
	}
	int i;
	char X;

	printf("masukkan elemen sebanyak max\n");
	for(i=1;i<=max;i++){
		scanf(" %c",&X);
		printf("karakter yang dibaca adalah : %c\n",X);
		AddQ(&Q,X);
	}
	if(IsEmptyQ(Q)){
		printf("queue kosong\n");
	}else{
		printf("queue tidak kosong\n");
	}
	if(IsFullQ(Q)){
		printf("queue penuh\n");
	}else{
		printf("queue tidak penuh\n");
	}

	//cek copyqueue dan delQ

	CopyQueue(Q,&Q1);
	printf("elemen Q adalah: \n");
	while(!IsEmptyQ(Q)){
		DelQ(&Q,&X);
		printf("%c\n",X);
	}
	
	printf("elemen Q1 adalah: \n");
	while(!IsEmptyQ(Q1)){
		DelQ(&Q1,&X);
		printf("%c\n",X);
	}
	DeAlokasiQ(&Q);
	return 0;
}