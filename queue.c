/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "queue.h"


/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q) == Nila && Tail(Q) == Nila);
}
int NBElmtQ (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    int total;
	if(IsEmptyQ(Q)){
		total=0;
	}else{
		if(Tail(Q)>Head(Q)){
			total=Tail(Q)-Head(Q)+1;
		}else if(Tail(Q)==Head(Q)){//sama dengan 1
			total=1;
		}else{
			total=MaxEl(Q)-Head(Q)+1+Tail(Q);
		}
	}
	return(total);
}
boolean IsFullQ (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{

    return(NBElmtQ(Q)==MaxEl(Q));
}



/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotypeq *) malloc (Max+1 * sizeof(infotypeq));
	MaxEl(*Q) = Max;
    Head(*Q) = Nila;
    Tail(*Q) = Nila;
}

/* *** Destruktor *** */
void DeAlokasiQ(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	free((*Q).T);
	MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, infotypeq X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	if(IsEmptyQ(*Q)){
		Head(*Q)=1;Tail(*Q)=1;
		InfoHead(*Q)=X;
	}else{//tidak kosong
		if(Tail(*Q)<MaxEl(*Q)){
			Tail(*Q)++;
		}else{//tail =maxEl
			Tail(*Q)=1;
		}
		InfoTail(*Q)=X;
	}
}
void DelQ (Queue * Q, infotypeq * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	int jumlahElemen;
	jumlahElemen=NBElmtQ(*Q);
	*X=InfoHead(*Q);
	if(jumlahElemen==1){
		Head(*Q)=Nila;
		Tail(*Q)=Nila;
	}else{//tidak kosong
		if((Head(*Q)<MaxEl(*Q))){
			Head(*Q)++;
		}else{
			Head(*Q)=1;
		}
	}
}

void CopyQueue(Queue Qin, Queue * Qout){
	infotypeq X;
	Queue temp;
	CreateEmptyQ(Qout,30);
	while(!IsEmptyQ(Qin)){
		//printf("head: %d, tail: %d\n",InfoHead(Qin),InfoTail(Qin));
		DelQ(&Qin,&X);
		AddQ(Qout,X);
	}
}
