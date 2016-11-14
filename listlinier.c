/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhsil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    
    P = (address) malloc (sizeof(ElmtList));
    if (P != NULL){
        Info(P) = X;
        Next(P) = Nil;
    }
    
    return P;
    
}


void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);   
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P;
    boolean found;
    found = false;
    P = Nil;
    if (!IsEmpty(L)){
        P = First(L);
        while(P != Nil && !found){
            if(Info(P) == X){   
                found = true;
            }
            else{
                P = Next(P);   
            }
        }
		if (!found){
            P = Nil;   
        }
    }
    
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;
    P = Alokasi(X);
    
    Next(P) = First(*L);
    First(*L) = P;
    
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address Q,P;   
    
    if(!IsEmpty(*L)){   
        P = First(*L);
        
        while(Next(P) != Nil){
            P = Next(P);
        }
        Q = Alokasi(X);
        Next(P) = Q;
    }
    else{
        InsVFirst(L,X);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    P = First(*L);
    
    *X = Info(P);
    First(*L) = Next(P);
    
    Dealokasi(&P);
    
}
void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P,Q;
    
    P = First(*L);
    Q = Nil;
	
    while(Next(P) != Nil){
        Q = P;
		P = Next(P);    
    }
    if (P != First(*L)){
	   Next(Q) = Nil;
       *X = Info(P);
    }
    else{
        First(*L) = Nil;
        *X = Info(P);
    }
    
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Q;
    
    
    if (!IsEmpty(*L)){
        Q = First(*L);
        
        while(Next(Q) != Nil){
            Q = Next(Q);    
        }
    
        Next(Q) = P;
        Next(P) = Nil; /* just to make sure lol */
    }
    else{
        InsertFirst(L,P);
    }
    
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P)=Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P,Q;
    boolean found;
    
    found = false;
    if (!IsEmpty(*L)){
        P = First(*L);
        Q = Nil;
        while(P != Nil && !found){
            if(Info(P) == X){   
                found = true;
            }
            else{
                Q = P;
                P = Next(P);   
            }
        }
		if(found){
			if(First(*L) != P){
				Next(Q) = Next(P);
				Dealokasi(&P);
			}
			else{
				if (Next(P) != Nil){
                    First(*L) = Next(P);
                }
                else{
                    First(*L) = Nil;
                }
				Dealokasi(&P);
			}
		}
    }
    
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address Q;
    Q = Nil;
    *P = First(*L);
    while (Next(*P) != Nil){   
        Q = *P;
        *P = Next(*P);
    }
    
    if(First(*L)!=*P){
        Next(Q) = Nil;
    }
    else{
        First(*L) = Nil;
    }
    
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;
    
    printf("[");
    if(!IsEmpty(L)){
        P = First(L);
        while (Next(P) != Nil){
            printf("%d,",Info(P));
            P = Next(P);
        }
        printf("%d",Info(P));
    }
    printf("]");
    
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    address P;
    int cnt;
    
    cnt = 0;
    
    P = First(L);
    while(P!=Nil){
        cnt++;
        P = Next(P);
    }
    return cnt;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    address P;
    infotype max;
    
    if (!IsEmpty(L)){
        P = First(L);
        max = Info(P);
        
        P = Next(P);
        while(P!=Nil){
            if(max<Info(P)){
                max = Info(P);   
            }
            P = Next(P);
        }
    }
    return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address P,Q;
    CreateEmpty(L3);
	
    //pindah data dari L1
    First(*L3) = First(*L1);
    
	if(!IsEmpty(*L1)){
		P = First(*L1);
		while(Next(P) != Nil){
			P = Next(P);
		}
		Next(P) = First(*L2);
	}
	else{
		First(*L3) = First(*L2);
	}
	
	First(*L2) = Nil;
	First(*L1) = Nil;
}


/*
               _______________________________________
   (\___(\   ||                                       ||
  \(   '^')/ || Congratulations, you have leveled up! ||
   o(")==(") || You have reached Lv. X                ||
             ||_______________________________________||
*/