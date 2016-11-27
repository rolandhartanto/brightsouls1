/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */
#include "boolean.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	
	Neff(*T)=0;
	
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
int NbElmtA (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
	return(Neff(T));
}

IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
	return(IdxMin);
}
IdxType GetLastIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
	return(NbElmtA(T)+GetFirstIdx(T)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyA (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return(NbElmtA(T)==0);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T){
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
	int i;
	if(IsEmptyA(T)){
		printf("Tabel kosong\n");//perhatikan disini..perlu \n atau ga
	}else{
		for(i=IdxMin;i<=GetLastIdx(T);i++){
			printf("[%d]%d\n",i,ElmtA(T,i));
		}
	}
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
	int i;
	i=IdxMin;
	if(IsEmptyA(T)){
		return(IdxUndef);
	}else{
		while((i<=NbElmtA(T))&&(X!=ElmtA(T,i))){
			if((X!=ElmtA(T,i))){
				i++;
			}
		}
		if(i>NbElmtA(T)){
			return(IdxUndef);
		}else{
			return(i);
		}
	}
}
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
	int idx;
	if(IsEmptyA(*T)){
		idx=0;
	}else{
		idx=GetLastIdx(*T);
	}
	ElmtA(*T,idx+1)=X;
	Neff(*T)++;
}
