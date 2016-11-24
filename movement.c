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


void EncounterCheck(List * Seed,MATRIKS * M, int x, int y){
		if (Elmt(*M,x,y) == 1){
			// Inventory Add
			//DelList(Seed,x,y);
			printf("Kamu mendapatkan barang!");
		}
		else if (Elmt(*M,x,y) == 2){
			// Battle Proc
			//DelList(Seed,x,y);
			printf("Ada musuh muncul!");
		}
		else if (Elmt(*M,x,y) == 4){
			// Boss Battle Proc
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
