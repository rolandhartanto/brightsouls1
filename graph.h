/*ADT Graph dengan representasi list of list*/

#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "listlinier.h"

#define Nil NULL

/* Definisi Type Data */
typedef List infotype;
typedef struct tElmtGraph *address;
typedef struct tElmtGraphP *addrPeta;
typedef struct tElmtGraph {
	infotype info;
	address next;
	address prev;
	addrPeta FirstJalur;/*titik pertama pada jalur peta*/
} ElmtGraph;
/*list yang berisi elemen jalur peta*/
typedef struct tElmtGraphP {
	infotype infoP;
	addrPeta nextP;
} ElmtGraphP;

typedef struct {
	address First;
	address Last;
} Graph;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define FirstJ(P) (P)->FirstJalur
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define NextP(E) (E)->nextP
#define InfoP(E) (E)->infoP


/****************** TEST LIST KOSONG ******************/
boolean IsEmptyGraph (Graph L)
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
address AlokasiGraph (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P;
	P = (address) malloc (sizeof(ElmtGraph));

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
void DealokasiGraph (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchGraph (Graph L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
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
void InsertJalurGraph(address *P, addrPeta LJ){
	FirstJ(*P) = LJ;
}

void DelJalurGraph(address *P, addrPeta LJ){
	FirstJ(*P) = Nil;
}

/*** PENAMBAHAN ELEMEN ***/
void InsVFirstGraph (Graph *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P;
	P = Alokasi(X);
	if(P!=Nil){
		if(IsEmpty(*L)){
			First(*L) = P;
			Last(*L) = P;
		}else{
			Next(P)=First(*L);
			Prev(First(*L)) = P;
			First(*L) = P;
		}
	}
}
void InsVLastGraph (Graph *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P;
	P = Alokasi(X);
	if(P!=Nil){
		if(IsEmpty(*L)){
			First(*L) = P;
			Last(*L) = P;
		}else{
			Next(Last(*L)) = P;
			Prev(P)=Last(*L);
			Last(*L) = P;
		}
	}
}
