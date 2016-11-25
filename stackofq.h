/* File : StackQt.c */
/* deklarasi StackQ yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "boolean.h"
#include <stdio.h>
#include "queue.h"

typedef Queue infotypesq;
typedef int addresssq;   /* indeks tabel */

#define Nilsq 0
#define MaxEl 100

/* Contoh deklarasi variabel bertype StackQ dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	infotypesq T[MaxEl+1]; /* tabel penyimpan elemen */
	addresssq TOP;  /* alamat TOP: elemen puncak */
} StackQ;
/* Definisi StackQ S kosong : S.TOP = Nilsq */
/* Elemen yang dipakai menyimpan nilai StackQ T[1]..T[MaxEl] */
/* Jika S adalah StackQ maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySQ (StackQ *S);

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySQ (StackQ S);

boolean IsFullSQ (StackQ S);

/* ************ Menambahkan sebuah elemen ke StackQ ************ */
void PushSQ (StackQ * S, infotypesq X);


/* ************ Menghapus sebuah elemen StackQ ************ */
void PopSQ (StackQ * S, infotypesq * X);
