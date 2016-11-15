#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdio.h>
#include "point.h"
#include "matriks.h"
#include "boolean.h"

/*
	NOTES
	0 = Empty Space
	1 = Item
	2 = Enemy
	3 = Wall
	4 = Boss
	
*/
void EncounterCheck(int x, int y);

void GoUp(MATRIKS * M, POINT * CurPos);

void GoDown(MATRIKS * M, POINT * CurPos);

void GoLeft(MATRIKS * M, POINT * CurPos);

void GoRight(MATRIKS * M, POINT * CurPos);


#endif