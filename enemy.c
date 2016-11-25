
#include "enemy.h"


void initEnemy(Enemy * E, int mapcount, boolean boss){
	if (!boss){
		HPE(*E) = BaseEHP + (mapcount * 4);
		STRE(*E) = BaseESTR + (mapcount * 4);
		DEFE(*E) = BaseEDEF + (mapcount * 4);
		EXP(*E) = rand() % (8+(mapcount * 2));
	}
	else{
		HPE(*E) = ((BaseEHP * 3) / 2) + (mapcount * 7);
		STRE(*E) = (BaseESTR * 2) + (mapcount * 5);
		DEFE(*E) = (BaseEDEF * 2) + (mapcount * 5);
		EXP(*E) = rand() % ((BaseEExp * 2)+(mapcount * 3));
	}

}
