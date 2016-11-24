/*ADT Graph dengan representasi list of list*/

#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "listlinier.h"

#define Nil NULL

/* Definisi Type Data */
typedef List infotypeg;
typedef struct tElmtGraph *addressg;
typedef struct tElmtGraphP *addrPeta;
typedef struct tElmtGraph {
	infotypeg info;
	addressg next;
	addressg prev;
	addrPeta FirstJalur;/*titik pertama pada jalur peta*/
} ElmtGraph;
/*list yang berisi elemen jalur peta*/
typedef struct tElmtGraphP {
	infotypeg infoP;
	addrPeta nextP;
} ElmtGraphP;

typedef struct {
	addressg First;
	addressg Last;
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
boolean IsEmptyGraph (Graph L);
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyGraph (Graph *L);

/****************** Manajemen Memori ******************/
addressg AlokasiGraph (infotypeg X);

void DealokasiGraph (addressg P);

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressg SearchGraph (Graph L, infotypeg X);

/*** PENAMBAHAN ELEMEN ***/
void InsVFirstGraph (Graph *L, infotypeg X);

void InsVLastGraph (Graph *L, infotypeg X);
