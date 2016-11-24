#include <stdio.h>
#include "movement.h"
/*
	NOTES
	0 = Empty Space
	1 = Item
	2 = Enemy
	3 = Wall
	4 = Boss

*/
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


void EncounterCheck(List * Seed,MATRIKS * M, int x, int y){
		if (Elmt(*M,x,y) == 1){
			// Inventory Add
			DelList(Seed,x,y);
			printf("Kamu mendapatkan barang!");
		}
		else if (Elmt(*M,x,y) == 2){
			// Battle Proc
			DelList(Seed,x,y);
			printf("Ada musuh muncul!");
		}
		else if (Elmt(*M,x,y) == 4){
			// Boss Battle Proc
			DelList(Seed,x,y);
			printf("Ada musuh muncul!");
		}
}

void GoUp(MATRIKS * M, POINT * CurPos, List * Seed)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i,j+1)!= 3){
		EncounterCheck(Seed,M,i,j+1);
		Ordinat(*CurPos)+=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}

void GoDown(MATRIKS * M, POINT * CurPos, List * Seed)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i,j-1)!= 3){
		EncounterCheck(Seed,M,i,j-1);
		Ordinat(*CurPos)-=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}

void GoLeft(MATRIKS * M, POINT * CurPos, List * Seed)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i-1,j)!= 3){
		EncounterCheck(Seed,M,i-1,j);
		Absis(*CurPos)-=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}

void GoRight(MATRIKS * M, POINT * CurPos, List * Seed)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i+1,j)!= 3){
		EncounterCheck(Seed, M,i+1,j);
		Absis(*CurPos)+=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}
