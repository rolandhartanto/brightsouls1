/* File : StackQt.c */
/* deklarasi StackQ yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "boolean.h"
#include <stdio.h>
#include "queue.h"

#define Nil 0
#define MaxEl 100
/* Nil adalah StackQ dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef Queue infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype StackQ dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
	infotype T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} StackQ;
/* Definisi StackQ S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai StackQ T[1]..T[MaxEl] */
/* Jika S adalah StackQ maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySQ (StackQ *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackQ S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri StackQ kosong : TOP bernilai Nil */
{
    Top(*S) = Nil; 
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySQ (StackQ S)
/* Mengirim true jika StackQ kosong: lihat definisi di atas */
{
    return (Top(S) == Nil);
}
boolean IsFullSQ (StackQ S)
/* Mengirim true jika tabel penampung nilai elemen StackQ penuh */
{
    return (Top(S) == MaxEl);
}

/* ************ Menambahkan sebuah elemen ke StackQ ************ */
void PushSQ (StackQ * S, infotype X)
/* Menambahkan X sebagai elemen StackQ S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackQ TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen StackQ ************ */
void PopSQ (StackQ * S, infotype * X)
/* Menghapus X dari StackQ S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}
