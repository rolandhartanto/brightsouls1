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

#define NamaE(E) (E).name
#define HPE(E) (E).hp
#define EXPE(E) (E).exp
#define STRE(E) (E).str
#define DEFE(E) (E).def
#define DropE(E) (E).drop
#define ProbE(E) (E).prob
#define Boss(E) (E).boss

#define BaseEHP 10
#define BaseESTR 3
#define BaseEDEF 2
