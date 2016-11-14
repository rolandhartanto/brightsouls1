#include <stdio.h>
#include "boolean.h"
//#include "player.h"

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

void EnemyGen(Enemy * E, Player P, int MapCnt, int DropID, int DropProb, boolean Boss){
	int a;
	
	HP(*E) = BaseEHP + (3 * MapCnt);		// HP Setter
	DEF(*E) = BaseEDEF + (1 * MapCnt);		// DEF Setter
	STR(*E) = BaseESTR + (2 * MapCnt);		// STR Setter
	EXP(*E) = BaseEHP + (10 * MapCnt);		// EXP Setter
	
}