#include <stdio.h>
#include "bintree.h"
#include "player.h"

void BuildTreeFromFile(BinTree *T){
	int i=0, val; char tkn;
	infotype info;
	*T=Nil;
	STARTTOKEN();
	if(EndToken){
		*T=Nil;
	}else{
		while(!EndToken){
			if(CToken.ID=='b'){
				val=CToken.val;
			}else{
				tkn=CToken.ID;
			}
			ADVTOKEN();
			i++;
			if((i>0)&&(i%2==0)){
				info.ID=i; info.val=val; info.tkn=tkn;
				BuildTree(T,info);
			}
		}
			
	}
}

int main(){
	BinTree T;
	TabInt TI;
	addrNode P1;
	infotype info;
	Player P;
	T=Nil;
	int ID;
	info.val=0; info.tkn='z';
	BuildTreeFromFile(&T);
	PrintTree(T,2);
	if(IsTreeEmpty(T)){
		printf("T kosong\n");
	}
	if(IsAllTaken(T)){
		printf("All skill has been gotten\n");
	}else{
		MakeEmpty(&TI);
		ToBeTaken(T,&TI);
		printf("Congratulations! You unlocked new skills\n");
		printf("Skill ID that can be achieved:\n");
		TulisIsi(TI);
		printf("Enter one of the ID:\n");
		scanf("%d",&ID);
		while(Search1(TI,ID)==IdxUndef){//jika input salah
			printf("Wrong ID input\nPlease input again!\n");
			scanf("%d",&ID);
		}
		//input sudah benar
		SearchNode(T,ID,&P1);
		if(ID==Akar(P1).ID){
			if(Akar(P1).tkn=='h'){
				HP(P)+=Akar(P1).val;
			}else if(Akar(P1).tkn=='s'){
				Str(P)+=Akar(P1).val;
			}else if(Akar(P1).tkn=='d'){
				Def(P)+=Akar(P1).val;
			}
			Akar(P1).val=0;
		}
		PrintTree(T,2);
	}
	return 0;
}