/*MODUL PLAYER*/
/* Berisi definisi dan semua primitif pemrosesan pada karakteristik (profile) pemain */
#ifndef _PLAYER_h
#define _PLAYER_h

#include "boolean.h"

/*Kamus umum*/
#define NMax 100 // definisi untuk jumlah inventory maksimal = 100
#define HPMax 100 //definisi HPMax adalah HP yang bernilai 100
#define HPMin 0 //definisi HPMin adalah HP yang bernilai 0
#define BaseHP 100
#define BaseLevel 1
#define BaseExp 0
#define BaseStr 10
#define BaseDef 10
#define BaseNext 10
#define BaseSkillPoint 10

/*Definisi koleksi elemen dan objek dari player*/
typedef int ItemID;
typedef struct{
	ItemID Inventory[NMax+1];
	char Nama[20];
	int NeffInventory;
	int HP;
	int Level;
	int Exp;
	int Str;
	int Def;
	int Next;
	int SkillPoint;
}Player;

/*Selektor*/
#define Inventory(P,i) 		(P).Inventory[(i)]
#define NeffInventory(P)	(P).NeffInventory
#define NamaP(P)			(P).Nama
#define HP(P) 				(P).HP
#define Level(P) 			(P).Level
#define Exp(P)				(P).Exp
#define Str(P)				(P).Str
#define Def(P)				(P).Def
#define	Next(P)				(P).Next
#define SkillPoint(P)		(P).SkillPoint
#define Nama(P)				(P).Nama
/*Konstruktor*/
void CreatePlayer(Player * P);
/*I.S. P sembarang*/
/*F.S. Terbentuk Player dengan NeffInventory = 0*/
/*Membentuk Player dengan NeffInventory = 0*/
/*Terbentuk Player dengan awalnya tidak memiliki inventory apapun*/

void InitPlayer(Player * P);
/*I.S. P sembarang*/
/*F.S. Terbentuk Player yang memiliki value Base masing-masing*/
/*mengatur nilai koleksi object dari player dengan Base masing-masing*/

boolean IsReadyNextLvl(int Exp, int Next);
/*menghasilkan true jika Exp>=Next*/


void LevelUp(Player * P);
/*I.S. P siap untuk naik level*/
/*F.S. Terbentuk Player dengan Level yang meningkat dengan update value
	   dari tipe data player juga terupdate*/
/*procedure untuk menaikkan level Player dengan:
	perubahan nilai Next dengan :
	Next(P)=10*pow(Level(P),2)+BaseLevel;
	Level(P) bertambah 1;
	SkillPoint(P) bertambah 10;
	Str dan Def bertambah 10;
	HP penuh kembali
	Exp menjadi Exp-next sebelum
*/
#endif
