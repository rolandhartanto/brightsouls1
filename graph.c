/*ADT Graph dengan representasi list of list*/

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return((First(L)==Nil)&&(Last(L)==Nil));
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L)=Nil;
	Last(*L)=Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P;
	P = (address) malloc (sizeof(ElmtList));
	
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
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
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
void InsertJalur(address *P, addrPeta LJ){
	FirstJ(*P) = LJ;
}

void DelJalur(address *P, addrPeta LJ){
	FirstJ(*P) = Nil;
}

/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
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
void InsVLast (List *L, infotype X)
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
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//assert(!IsEmpty(*L));
	address P;
	P = First(*L);
	*X = Info(P);
	if((First(*L)==Last(*L))&&(First(*L)!=Nil)){
		Last(*L) = Nil;
		First(*L) = Nil;
	}else{
		First(*L)=Next(P);
		Next(P) = Nil;
		Prev(First(*L)) = Nil;
	}
	Dealokasi(P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//assert(!IsEmpty(*L));
	address P;
	*X = Info(Last(*L));
	
	P = Last(*L);
	if((First(*L)==Last(*L))&&(First(*L)!=Nil)){
		Last(*L) = Nil;
		First(*L) = Nil;
	}else{
		Last(*L) = Prev(P);
		Prev(P) = Nil;
		Next(Last(*L)) = Nil;
	}
	Dealokasi(P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if(IsEmpty(*L)){
		First(*L) = P;
		Last(*L) = P;
	}else{
		Next(P) = First(*L);
		Prev(First(*L)) = P;
		First(*L) = P;
	}
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if(IsEmpty(*L)){
		InsertFirst(L,P);
	}else{
		Prev(P) = Last(*L);
		Next(Last(*L)) = P;
		Last(*L) = P;
	}
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if(Prec == Last(*L)){
		InsertLast(L,P);
	}else{
		Next(P) = Next(Prec);
		Prev(Next(Prec)) = P;
		Prev(P) = Prec;
		Next(Prec) = P;
	}
	
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	if(Succ == First(*L)){
		InsertFirst(L,P);
	}else{
		Prev(P) = Prev(Succ);
		Next(Prev(Succ)) = P;
		Next(P) = Succ;
		Prev(Succ) = P;
	}
	
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	//assert(!IsEmpty(*L));
	*P = First(*L);
	if((First(*L)==Last(*L))&&(First(*L)!=Nil)){
		Last(*L) = Nil;
		First(*L) = Nil;
	}else{
		First(*L) = Next(First(*L));
		Prev(First(*L)) = Nil;
	}
	Next(*P)= Nil;
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	//assert(!IsEmpty(*L));
	*P = Last(*L);
	if((First(*L)==Last(*L))&&(First(*L)!=Nil)){
		Last(*L) = Nil;
		First(*L) = Nil;
	}else{
		Last(*L) = Prev(Last(*L));
		Next(Last(*L)) = Nil;
	}
	Prev(*P)= Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	//assert(!IsEmpty(*L));
	address P,Q;
	P = Search(*L,X);
	if(P!=Nil){
		if((First(*L)==Last(*L))&&(First(*L)!=Nil)){
			Last(*L) = Nil;
			First(*L) = Nil;
		}else{
			if(P == First(*L)){
				DelFirst(L,&P);
			}else if(P == Last(*L)){
				DelLast(L,&P);
			}else{
				address Q = Prev(P);
				DelAfter(L,&P,Q);
			}
			
		}
		Dealokasi(P);
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	//assert(!IsEmpty(*L));
	*Pdel = Next(Prec);
	address Q;
	if(*Pdel == Last(*L)){
		DelLast(L,Pdel);
	}else{
		Next(Prec)=Next(Next(Prec));
		Q = Next(Prec);
		Prev(Q) = Prec;
	}
	Next(*Pdel)=Nil;
	Prev(*Pdel)=Nil;
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	//assert(!IsEmpty(*L));
	*Pdel = Prev(Succ);
	address Q;
	if(*Pdel == First(*L)){
		DelFirst(L,Pdel);
	}else{
		Prev(Succ)=Prev(Prev(Succ));
		Q = Prev(Succ);
		Next(Q) = Succ;
	}
	Next(*Pdel)= Nil;
	Prev(*Pdel)= Nil;
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	if(IsEmpty(L)){
		printf("[]");
	}else{
		address P;
		P = First(L);
		printf("[");
		while(P!=Nil){
			printf("%d",Info(P));
			if(P!=Last(L)){
				printf(",");
			}
			P = Next(P);
		}
		printf("]");
	}
}
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	if(IsEmpty(L)){
		printf("[]");
	}else{
		address P;
		P = Last(L);
		printf("[");
		while(P!=Nil){
			printf("%d",Info(P));
			if(P!=First(L)){
				printf(",");
			}
			P = Prev(P);
		}
		printf("]");
	}
}