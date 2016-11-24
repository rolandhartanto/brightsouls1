#include <stdio.h>
#include "point.h"
#include "listlinier.h"

void DelList(List * L,int x, int y){
	address P;
	boolean found=false;
	P=First(*L);
	while((P!=Nil)&&(!found)){
		if((Info(P)==99)||(Info(P)==98)){
			if((Info(Next(P))==x)&&((Info(Next(Next(P)))==y))){
				found=true;
				DelP(L,Info(P));
				DelP(L,Info(Next(P)));
				DelP(L,Info(Next(Next(P))));
			}
		}
		if(!found&&(P!=Nil)){
			P=Next(P);
		}
	}
}

int main(){
	List L;
	int count, elmt;
	CreateEmpty(&L);
	printf("masukkan berapa banyak elemen yang mau diinputkan\n");
	scanf("%d",&count);
	printf("masukkan elemen list:\n");
	while(count--){
		scanf("%d",&elmt);
		InsVLast(&L,elmt);
	}
	int x=1; int y=2;
	DelList(&L,x,y);
	if(IsEmpty(L)){
		printf("List Kosong\n");
	}else{
		printf("List:\n");
		PrintInfo(L);
	}
	return 0;
}
