#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdio.h>
#include "mapgen.h"
#include "matriks.h"
#include "point.h"
#include "boolean.h"
/*
	NOTES
	0 = Empty Space
	1 = Item
	2 = Enemy
	3 = Wall
	4 = Boss

*/

extern boolean ItemFlag;
extern boolean EnemyFlag;
extern boolean BossFlag;
extern boolean WallFlag;

void DelList(List * L,int x, int y);

void EncounterCheck(List * Seed, MATRIKS * M, int x, int y);

void GoUp(MATRIKS * M, POINT * CurPos, List * Seed);

void GoDown(MATRIKS * M, POINT * CurPos, List * Seed);

void GoLeft(MATRIKS * M, POINT * CurPos, List * Seed);

void GoRight(MATRIKS * M, POINT * CurPos, List * Seed);


#endif
