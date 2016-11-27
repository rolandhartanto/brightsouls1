/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#include "stackt.h"

/* Definisi stack S kosong : S.TOP = Nils */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxElSt] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS (Stack *S){
/* I.S. sembarang{} */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElSt */
/* jadi indeksnya antara 1.. MaxElSt+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nils */
	Top(*S)=Nils;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	if(Top(S)==Nils){
		return(true);
	}else{
		return(false);
	}
}
boolean IsFullS (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	if(Top(S)==MaxElSt){
		return(true);
	}else{
		return(false);
	}
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushS (Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	Top(*S)++;
	InfoTop(*S)=X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopS (Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	*X=InfoTop(*S);
	Top(*S)--;
}
