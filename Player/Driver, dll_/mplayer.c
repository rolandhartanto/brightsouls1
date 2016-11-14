#include <stdio.h>
#include "player.h"
int main(){
	Player P;
	CreatePlayer(&P);
	InitPlayer(&P);
	printf("jumlah hp sekarang adalah %d\n",HP(P));
	printf("jumlah level sekarang adalah %d\n",Level(P));
	printf("jumlah Exp sekarang adalah %d\n",Exp(P));
	printf("jumlah Str sekarang adalah %d\n",Str(P));
	printf("jumlah Def sekarang adalah %d\n",Def(P));
	printf("jumlah Next sekarang adalah %d\n",Next(P));
	printf("jumlah Skillpoint sekarang adalah %d\n",SkillPoint(P));
	printf("masukkan penambahan EXP setelah menang battle\n");
	int EXP;
	scanf("%d",&EXP);
	Exp(P)+=EXP;
	if(IsReadyNextLvl(Exp(P),Next(P))){
		printf("level naik:\n");
		LevelUp(&P);
		
		printf("jumlah hp sekarang adalah %d\n",HP(P));
		printf("jumlah level sekarang adalah %d\n",Level(P));
		printf("jumlah Exp sekarang adalah %d\n",Exp(P));
		printf("jumlah Str sekarang adalah %d\n",Str(P));
		printf("jumlah Def sekarang adalah %d\n",Def(P));
		printf("jumlah Next sekarang adalah %d\n",Next(P));
		printf("jumlah Skillpoint sekarang adalah %d\n",SkillPoint(P));
	}else{
		printf("belum siap naik level\n");
		printf("namun EXP sekarang bertambah menjadi %d\n",Exp(P));
	}
	return 0;
}