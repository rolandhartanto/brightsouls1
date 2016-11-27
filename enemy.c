
#include "enemy.h"
#include <stdlib.h>

#define BaseEHP 80
#define BaseESTR 999
#define BaseEDEF 10
#define BaseEEXP 8

Enemy initEnemy(Enemy E, int mapcount, boolean boss){
	Enemy En
	if (!boss){
		HPE(En) = HPE(*E) + ((mapcount-1) * 4);
		STRE(En) = STRE(*E) + ((mapcount-1) * 4);
		DEFE(En) = DEFE(*E) + ((mapcount-1) * 4);
		EXPE(En) = rand() % (EXPE(*E)+((mapcount-1) * 2))+5;
	}
	else{
		HPE(En) = ((HPE(*E) * 3) / 2) + ((mapcount-1) * 7);
		STRE(En) = (STRE(*E) * 2) + ((mapcount-1) * 5);
		DEFE(En) = (DEFE(*E) * 2) + ((mapcount-1) * 5);
		EXPE(En) = rand() % ((EXPE(*E) * 2)+((mapcount-1) * 3))+5;
	}
	return En;
}


void makeEnemy(Enemy * E, int HP, int STR, int DEF, int EXP){
		HPE(*E) = HP;
		STRE(*E) = STR;
		DEFE(*E) = DEF;
		EXPE(*E) = EXP;
}
