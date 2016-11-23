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
void EncounterCheck(MATRIKS * M, int x, int y){
		if (Elmt(*M,x,y) == 1){
			// Inventory Add
			printf("Kamu mendapatkan barang!");
		}
		else if (Elmt(*M,x,y) == 2){
			// Battle Proc
			printf("Ada musuh muncul!");
		}
		else if (Elmt(*M,x,y) == 4){
			// Boss Battle Proc
		}
}

void GoUp(MATRIKS * M, POINT * CurPos)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i,j+1)!= 3){
		EncounterCheck(M,i,j+1);
		Ordinat(*CurPos)+=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}

void GoDown(MATRIKS * M, POINT * CurPos)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i,j-1)!= 3){
		EncounterCheck(M,i,j-1);
		Ordinat(*CurPos)-=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}

void GoLeft(MATRIKS * M, POINT * CurPos)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i-1,j)!= 3){
		EncounterCheck(M,i-1,j);
		Absis(*CurPos)-=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}

void GoRight(MATRIKS * M, POINT * CurPos)
{
	int i,j;
	i = Absis(*CurPos);
	j = Ordinat(*CurPos);
	if (Elmt(*M,i+1,j)!= 3){
		EncounterCheck(M,i+1,j);
		Absis(*CurPos)+=1;
	}
	else{
		printf("Kamu menabrak tembok");
	}
}
