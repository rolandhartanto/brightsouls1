/*MODUL PLAYER*/
#include "player.h"
#include <math.h>
/* Berisi definisi dan semua primitif pemrosesan pada karakteristik (profile) pemain */


/*Selektor*/
#define Inventory(P,i) 		(P).Inventory[(i)]
#define NeffInventory(P)	(P).NeffInventory
#define NamaP(P)			(P).Nama
#define HP(P) 				(P).HP
#define Level(P) 			(P).Level
#define Exp(P)				(P).Exp
#define Str(P)				(P).Str
#define Def(P)				(P).Def
#define	NextEXP(P)			(P).Next
#define SkillPoint(P)		(P).SkillPoint
#define Nama(P)				(P).Nama



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
