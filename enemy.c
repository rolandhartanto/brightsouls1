#include <stdio.h>
#include "boolean.h"
#include "array.h"

typedef struct{
	int hp;
	int exp;
	int str;
	int def;
	int drop;
	int prob;
	boolean boss;
} Enemy;

#define HP(E) (E).hp
#define EXP(E) (E).exp
#define STR(E) (E).str
#define DEF(E) (E).def
#define Drop(E) (E).drop
#define Prob(E) (E).prob
#define Boss(E) (E).boss

#define BaseEHP 10
#define BaseESTR 3
#define BaseEDEF 2

void EnemyGen(Enemy * E, int MapCnt, int DropID, int DropProb, boolean BossS){
	int a;
	
	HP(*E) = BaseEHP + (3 * MapCnt);		// HP Setter
	DEF(*E) = BaseEDEF + (1 * MapCnt);		// DEF Setter
	STR(*E) = BaseESTR + (2 * MapCnt);		// STR Setter
	EXP(*E) = BaseEHP + (10 * MapCnt);		// EXP Setter
	Boss(*E) = BossS;
	Drop(*E) = DropID;
	Prob(*E) = DropProb;
}

void 