#include <stdio.h>
#include "point.h"
#include "listlinier.h"

void DelList(List * L,int x, int y){
	address P;
	int i=1;
	address temp;
	boolean found=false;
	P=First(*L);
	while((!found)&&(Next(P)!=Nil)){
		if((Info(Next(P))==99)||(Info(Next(P))==98)||(Info(Next(P))==97)){
			if((Info(Next(Next(P)))==x)&&((Info(Next(Next(Next(P))))==y))){
				found=true;
				while(i<=3){
					
						DelAfter(L,&temp,P);

						i++;
					
					
					
						//next P=x
						DelAfter(L,&temp,P);
						
						i++;
					
						DelAfter(L,&temp,P);
						i=5;
					
				}
				
			}
		}
		if(!found){
			P=Next(P);
		}
	}
}

int main(){
	List L;
	address P;
	int count, elmt;
	CreateEmpty(&L);
	printf("masukkan berapa banyak elemen yang mau diinputkan\n");
	scanf("%d",&count);
	printf("masukkan elemen list:\n");
	while(count--){
		scanf("%d",&elmt);
		InsVLast(&L,elmt);
	}
	PrintInfo(L); printf("\n");
	int x=1; int y=2;
	P=First(L);
	DelList(&L,x,y);
	if(IsEmpty(L)){
		printf("List Kosong\n");
	}else{
		printf("List:\n");
		PrintInfo(L);
	}
	return 0;
}