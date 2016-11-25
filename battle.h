//#include "array.h"
#include "queue.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include "mesinkata.h"
#include "stackofq.h"
#include "enemy.h"
#include "player.h"

typedef struct{
	char cmd[5];
} Command;

#define Comd(P,i) (P).cmd[(i)]


int RPSComparator(char P, char E);

int PDmgCntr(Player Pl, Enemy El, char P, int rslt);

int EDmgCntr(Player Pl, Enemy El, char P, int rslt);

void ReadCmd(Queue * Q);

void RandomizeStack(StackQ * S,int x);

void PrintCmd(Queue Q,char * cmd);

void BattleProcessing(Player * P, Enemy * E);
