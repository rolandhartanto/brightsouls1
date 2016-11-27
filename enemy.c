
#include "enemy.h"
#include <stdlib.h>

#define BaseEHP 80
#define BaseESTR 999
#define BaseEDEF 10
#define BaseEEXP 8

void initEnemy(Enemy * E, int mapcount, boolean boss){
	if (!boss){
		HPE(*E) = BaseEHP + ((mapcount-1) * 4);
		STRE(*E) = BaseESTR + ((mapcount-1) * 4);
		DEFE(*E) = BaseEDEF + ((mapcount-1) * 4);
		EXPE(*E) = rand() % (BaseEEXP+((mapcount-1) * 2))+5;
	}
	else{
		HPE(*E) = ((BaseEHP * 3) / 2) + ((mapcount-1) * 7);
		STRE(*E) = (BaseESTR * 2) + ((mapcount-1) * 5);
		DEFE(*E) = (BaseEDEF * 2) + ((mapcount-1) * 5);
		EXPE(*E) = rand() % ((BaseEEXP * 2)+((mapcount-1) * 3))+5;
	}

}
