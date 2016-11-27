#include <stdio.h>
#include "enemy.h"

int main(){
	Enemy E;
	int mapcount=1;
	boolean boss=false;
	initEnemy(&E,mapcount,boss);
	printf("HP: %d\n",HPE(E));
	printf("str: %d\n",STRE(E));
	printf("def: %d\n",DEFE(E));
	printf("exp: %d\n",EXPE(E));
	return 0;
}