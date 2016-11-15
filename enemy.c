#include <stdio.h>
#include "boolean.h"
#include "array.h"

typedef struct{
	char name[20];
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

