/*ADT Graph dengan representasi list of list*/


#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyGraphGraph (Graph L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return((First(L)==Nil)&&(Last(L)==Nil));
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyGraph (Graph *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L)=Nil;
	Last(*L)=Nil;
}
/****************** Manajemen Memori ******************/
addressg AlokasiGraph (infotypeg X)
/* Mengirimkan addressg hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressg tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	addressg P;
	P = (addressg) malloc (sizeof(ElmtGraph));

	if(P!=Nil){
		Info(P) = X;
		Prev(P) = Nil;
		Next(P) = Nil;
		FirstJ(P) = Nil;
		return P;
	}else{
		return Nil;
	}
}
void DealokasiGraph (addressg P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressg P */
{
	free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressg SearchGraph (Graph L, infotypeg X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressg elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	addressg P;
	P = First(L);
	boolean found = false;
	while((P!=Nil)&&(!found)){
		if(Info(P)==X){
			found = true;
		}else{
			P = Next(P);
		}
	}

	if(found){
		return P;
	}else{
		return Nil;
	}
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN JALUR ***/
void InsertJalurGraph(addressg *P, addrPeta LJ){
	FirstJ(*P) = LJ;
}

void DelJalurGraph(addressg *P, addrPeta LJ){
	FirstJ(*P) = Nil;
}

/*** PENAMBAHAN ELEMEN ***/
void InsVFirstGraph (Graph *L, infotypeg X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	addressg P;
	P = Alokasi(X);
	if(P!=Nil){
		if(IsEmptyGraph(*L)){
			First(*L) = P;
			Last(*L) = P;
		}else{
			Next(P)=First(*L);
			Prev(First(*L)) = P;
			First(*L) = P;
		}
	}
}
void InsVLastGraph (Graph *L, infotypeg X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	addressg P;
	P = Alokasi(X);
	if(P!=Nil){
		if(IsEmptyGraph(*L)){
			First(*L) = P;
			Last(*L) = P;
		}else{
			Next(Last(*L)) = P;
			Prev(P)=Last(*L);
			Last(*L) = P;
		}
	}
}
