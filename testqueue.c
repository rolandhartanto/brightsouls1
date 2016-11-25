#include <stdio.h>
#include "queue.h"

int main(){
	Queue Q,Q1;
	CreateEmptyQ(&Q,30);
	CreateEmptyQ(&Q1,30);
	printf("masukkan banyak elemen\n");
	int cnt,X;
	scanf("%d",&cnt);
	printf("masukkan elemennya\n");
	while(cnt--){
		printf("cnt sekarang adalah: %d\n",cnt);
		scanf("%d",&X);
		AddQ(&Q,X);
	}
	printf("test\n");
	CopyQueue(Q,&Q1);
	printf("test\n");
	printf("elemen Q sekarang adalah\n");
	printf("test\n");
	while(!IsEmptyQ(Q)){
		DelQ(&Q,&X);
		printf("%d\n",X);
	}
	printf("elemen Q1 sekarang adalah\n");
	while(!IsEmptyQ(Q1)){
		DelQ(&Q1,&X);
		printf("%d\n",X);
	}
	
	return 0;
}