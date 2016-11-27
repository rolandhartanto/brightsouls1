/*MODUL PLAYER*/
#include "player.h"
#include <math.h>
#include <stdio.h>
/* Berisi definisi dan semua primitif pemrosesan pada karakteristik (profile) pemain */


/*Selektor*/


/*Konstruktor*/
void CreatePlayer(Player * P){
/*I.S. P sembarang*/
/*F.S. Terbentuk Player dengan NeffInventory = 0*/
/*Membentuk Player dengan NeffInventory = 0*/
/*Terbentuk Player dengan awalnya tidak memiliki inventory apapun*/
	NeffInventory(*P) = 0;
}

void InitPlayer(Player * P){
/*I.S. P sembarang*/
/*F.S. Terbentuk Player yang memiliki value Base masing-masing*/
/*mengatur nilai koleksi object dari player dengan Base masing-masing*/
	CreatePlayer(P);
	HP(*P)=BaseHP;
	Level(*P)=BaseLevel;
	Exp(*P)=BaseExp;
	Str(*P)=BaseStr;
	Def(*P)=BaseDef;
	NextEXP(*P)=BaseNext;
	SkillPoint(*P)=BaseSkillPoint;
	HPMax(*P) = MaxHP;
}
boolean IsReadyNextLvl(int Exp, int Next){
/*menghasilkan true jika Exp>=Next*/
	return(Exp>=Next);
}

void LevelUp(Player * P){
/*I.S. P siap untuk naik level*/
/*F.S. Terbentuk Player dengan Level yang meningkat dengan update value
	   dari tipe data player juga terupdate*/
/*procedure untuk menaikkan level Player dengan:
	perubahan nilai Next dengan :
	Level(P) bertambah 1;
	Next(P)=10*pow(Level(P),2)+BaseLevel;
	SkillPoint(P) bertambah 10;
	Str dan Def bertambah 10;
	HP penuh kembali;
	Exp menjadi Exp-next sebelum;
*/
	Level(*P)++;
	Exp(*P)=Exp(*P)-NextEXP(*P);
	NextEXP(*P)=10* pow(Level(*P),2)+BaseLevel;
	SkillPoint(*P)+=1;
	Str(*P)+=10;
	Def(*P)+=10;
	HP(*P)=BaseHP;
}

boolean IsReadyGetSkill(int SkillPoint){
	return(SkillPoint>=1);
}

void ChangeSkillTree(BinTree * T){
//Fungsi untuk mengubah skill tree karena
		TabInt TI;
		Player P;
		int ID;
		addrNode P1;
		MakeEmpty(&TI);
		ToBeTaken(*T,&TI);
		printf("Congratulations! You unlocked new skills\n");
		printf("Skill ID that can be achieved:\n");
		TulisIsi(TI);
		printf("Enter one of the ID:\n");
		scanf("%d",&ID);
		while(Search1(TI,ID)==IdxUndef){//jika input salah
			printf("Wrong ID input\nPlease input again!\n");
			scanf("%d",&ID);
		}
		//input sudah benar
		SearchNode(*T,ID,&P1);
		if(ID==Akar(P1).ID){
			if(Akar(P1).tkn=='h'){
				HP(P)+=Akar(P1).val;
				printf("HP pemain bertambah sebanyak: %d\n",Akar(P1).val);
			}else if(Akar(P1).tkn=='s'){
				Str(P)+=Akar(P1).val;
				printf("STR pemain bertambah sebanyak: %d\n",Akar(P1).val);
			}else if(Akar(P1).tkn=='d'){
				Def(P)+=Akar(P1).val;
				printf("DEF pemain bertambah sebanyak: %d\n",Akar(P1).val);
			}
			Akar(P1).val=0;
		}
		PrintTree(*T,2);
	}
