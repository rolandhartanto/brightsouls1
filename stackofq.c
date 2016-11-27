/* File : StackQt.c */
/* deklarasi StackQ yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "stackofq.h"
#include "boolean.h"
#include <stdio.h>


/* Nilsq adalah StackQ dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */



/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySQ (StackQ *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackQ S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri StackQ kosong : TOP bernilai Nilsq */
{
    Top(*S) = Nilsq;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySQ (StackQ S)
/* Mengirim true jika StackQ kosong: lihat definisi di atas */
{
    return (Top(S) == Nilsq);
}
boolean IsFullSQ (StackQ S)
/* Mengirim true jika tabel penampung nilai elemen StackQ penuh */
{
    return (Top(S) == MaxElSQ);
}

/* ************ Menambahkan sebuah elemen ke StackQ ************ */
void PushSQ (StackQ * S, infotypesq X)
/* Menambahkan X sebagai elemen StackQ S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackQ TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen StackQ ************ */
void PopSQ (StackQ * S, infotypesq * X)
/* Menghapus X dari StackQ S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}
