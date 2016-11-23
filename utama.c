#include "ADTgui.h"
#include "mapgen.h"
//#include "player.h"
//#include "enemy.h"
#include<stdio.h>

int main(){
	char name[11]={0};

	char x;
	int b = 1, s = 0;//b status program jalan ato berhenti, s status start ato blm
	int lvl = 1,hp = 100,str = 2,def = 2,exp = 0;
	loadingBar();
	while(b){
		if(s==1){
			printGUIInGame(name,lvl,hp,str,def,exp);
		}else{
			printMainMenu();
			pilihOpsi(name,&b,&s);
		}
	}

	return 0;
}
