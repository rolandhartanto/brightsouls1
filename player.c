/*MODUL PLAYER*/
#include "player.h"
#include "ADTgui.h"
#include <math.h>
#include <stdio.h>
#include "color.h"
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
	HPMax(*P) = HPMax(*P) + 10;
	HP(*P)=HPMax(*P);
}

boolean IsReadyGetSkill(int SkillPoint){
	return(SkillPoint>=1);
}


void TulisIsiST (TabInt T, BinTree Ph){
	/* Proses : Menuliskan isi tabel dengan traversal */
	/* I.S. T boleh kosong */
	/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
	/*      Jika T kosong : Hanya menulis "Tabel kosong" */
	/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
	   Maka tercetak di layar:
	   [1]1
	   [2]20
	   [3]30
	   [4]50
	*/
		int i,j,k;
		addrNode P;
		if(IsEmptyA(T)){
			printf("Tabel kosong\n");//perhatikan disini..perlu \n atau ga
		}else{
			for(i=IdxMin;i<=GetLastIdx(T);i++){
				SearchNode(Ph,ElmtA(T,i),&P);
				j = Tingkat(Ph,P);
				for(k=0;k<j-1;k++){
					printf(" ");
				}
				if(Akar(P).tkn=='h'){
					printf(col_blue_bg"[%d]"col_reset col_gray_bg"Health++\n"col_reset,ElmtA(T,i));
				}
				else if(Akar(P).tkn=='s'){
					printf(col_blue_bg"[%d]"col_reset col_gray_bg"STR++\n"col_reset,ElmtA(T,i));
				}
				else if(Akar(P).tkn=='d'){
					printf(col_blue_bg"[%d]"col_reset col_gray_bg"DEF++\n"col_reset,ElmtA(T,i));
				}

			}
		}
	}

void ChangeSkillTree(BinTree * T, TabInt * TI, Player * P,TabInt * Taken){
//Fungsi untuk mengubah skill tree karena
		int ID;
		addrNode P1;
		do{
		MakeEmpty(TI);
		ToBeTaken(*T,TI);

		PrintHeader(Nama(*P),HP(*P),Str(*P),Def(*P),Level(*P),Exp(*P),NextEXP(*P));
		if(IsEmptyA(*Taken)){
			printf("No skill has been achieved\n");
			printf("\n");
			//delay(500);
		}else{//sudah ada skill yang terambil
			printf("Skill that has been taken:\n");
			TulisIsiST(*Taken,*T);
			printf("\n");
		}
		printf("Achievable Skill List:\nAvailable Skill Points : %d\n\n",SkillPoint(*P));
		TulisIsiST(*TI,*T);
		printf("\n");
		printf(col_blue_bg"[0]"col_reset col_gray_bg"Back"col_reset"\n\n");
		printf(    "_________________________________________________________________________________________________\n\n");
		printf("\t\tID : ");
		scanf("%d",&ID);
		if(ID != 0){
		if(SkillPoint(*P)>0){
			while(Search1(*TI,ID)==IdxUndef){//jika input salah
				printf("Wrong ID input\nPlease input again!\n");
				scanf("%d",&ID);
			}
		//input sudah benar
			ClearScreen();
			PrintHeader(Nama(*P),HP(*P),Str(*P),Def(*P),Level(*P),Exp(*P),NextEXP(*P));
			SearchNode(*T,ID,&P1);
			if(ID==Akar(P1).ID){
				if(Akar(P1).tkn=='h'){
					HPMax  (*P)+=Akar(P1).val;
					HP(*P) =HPMax(*P);
					printf("HP increased by %d\n",Akar(P1).val);
				}else if(Akar(P1).tkn=='s'){
					Str(*P)+=Akar(P1).val;
					if(Str(*P)>100){Str(*P)=100;}
					printf("STR increased by %d\n",Akar(P1).val);
				}else if(Akar(P1).tkn=='d'){
					Def(*P)+=Akar(P1).val;
					if(Def(*P)>100){Def(*P)=100;}
					printf("DEF increased by %d\n",Akar(P1).val);
				}
				Akar(P1).val=0;
				SkillPoint(*P)--;//skill point pemain berkurang 1
							//setelah diambil skillnya
				AddAsLastEl(Taken,ID);
				printf(    "_________________________________________________________________________________________________\n\n");
			}
		}
		else{
			printf("Insufficient Skill Points\n");
			delay(500);
		}
		}
	}
		while(SkillPoint(*P) > 0 && ID != 0);
	}
