/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef int infotype;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotype * T;   /* tabel penyimpan elemen */
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
                 int MaxEl;     /* Max elemen queue */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFullQ (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    int nb;
    if (IsEmpty(Q)){
        nb = 0;
    }
    else{
        if(Head(Q) > Tail(Q)){
            nb = (Tail(Q) + MaxEl(Q)) - Head(Q) + 1 ;
        }
        else{
            nb = Tail(Q) - Head(Q) + 1;
        }
    }



	return (MaxEl(Q) == nb);
}
int NBElmtQ (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    int nb;
    if (IsEmpty(Q)){
        nb = 0;
    }
    else{
        if(Head(Q) > Tail(Q)){
            nb = (Tail(Q) + MaxEl(Q)) - Head(Q) + 1 ;
        }
        else{
            nb = Tail(Q) - Head(Q) + 1;
        }
    }
    return nb;
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype *) malloc (Max+1 * sizeof(infotype));
	MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
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
void AddQ (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	if(IsEmpty(*Q)){
        Head(*Q) = 1;
    }
    Tail(*Q) += 1;
	if (Tail(*Q)>MaxEl(*Q)){
		Tail(*Q) = 1;
	}
	InfoTail(*Q) = X;
}
void DelQ (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	*X = InfoHead(*Q);
	Head(*Q) += 1;
	if (Head(*Q)>MaxEl(*Q)){
		Head(*Q) = 1;
	}
}
