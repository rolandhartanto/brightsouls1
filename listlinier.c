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

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    address Q;
    boolean found;
    found = false;
    if (!IsEmpty(L)){
        Q = First(L);
        while(Q != Nil && !found){
            if(Q == P){
                found = true;
            }
            else{
                Q = Next(Q);
            }
        }
    }

    return found;
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    address P,Q;
    boolean found;

    found = false;
    if (!IsEmpty(L)){
        P = First(L);
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
        if (!found){
            Q = Nil;
        }
    }
    else{
        Q = Nil;
    }
    return Q;
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

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    address P,Q;
    infotype max;

    if (!IsEmpty(L)){
        P = First(L);
        Q = First(L);
        max = Info(P);

        P = Next(P);
        while(P!=Nil){
            if(max<Info(P)){
                max = Info(P);
                Q = P;
            }
            P = Next(P);
        }
    }
    return Q;

}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address P;
    infotype min;

    if (!IsEmpty(L)){
        P = First(L);
        min = Info(P);

        P = Next(P);
        while(P!=Nil){
            if(min>Info(P)){
                min = Info(P);
            }
            P = Next(P);
        }
    }
    return min;
}


address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    address P,Q;
    infotype min;

    if (!IsEmpty(L)){
        P = First(L);
        Q = First(L);
        min = Info(P);

        P = Next(P);
        while(P!=Nil){
            if(min>Info(P)){
                min = Info(P);
                Q = P;
            }
            P = Next(P);
        }
    }
    return Q;
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    int sum,cnt;
    float avg;
    address P;
    sum = 0;
    avg = 0;
    cnt = 0;

    P = First(L);
    while(P!=Nil){
        sum += Info(P);
        cnt += 1;
        P = Next(P);
    }

    avg = (float) sum / (float) cnt;
    return avg;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    address P, Q;
    P = First(*L);
    Q = Nil;
    while(P!= Nil){
        Q = P;
        P = Next(P);
        Dealokasi(&Q);
    }
    First(*L) = Nil;
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P,Q,R,S;
    P = Next(First(*L));
    Q = First(*L);
    R = Nil;
    S = Nil;

    while(Q != Nil)
    {
        S = Q;
        Next(Q) = R;

        if(P == Nil){
            First(*L) = Q;
        }

        Q = P;

        if (P != Nil){
            P = Next(P);
        }

        R = S;
    }

}
// P Q R S
// 0 0 4 4
// 0 0 0 0

// 1 2 3 4
// 0 1 2 3

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L2;
    address P,Q,R;
    CreateEmpty(&L2);
    if(!IsEmpty(L)){
        P = First(L);
        Q = Nil;
        while(P != Nil){
            InsVFirst(&L2,Info(P));
            P = Next(P);
            //P = Nil;
        }
    }


    return L2;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L2;
    address P,Q,R;
    CreateEmpty(&L2);
    if(!IsEmpty(L)){
        P = First(L);
        Q = Nil;
        while(P != Nil){
            InsVLast(&L2,Info(P));
            P = Next(P);
            //P = Nil;
        }
    }


    return L2;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
    *Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    List L4;
    address P;
    CreateEmpty(&L4);
    if(IsEmpty(L1)){
        *L3 = FCopyList(L2);
    }
    else{
        *L3 = FCopyList(L1);
        L4 = FCopyList(L2);

        P = First(*L3);
        while(Next(P) != Nil){
                P = Next(P);
        }
	Next(P) = First(L4);
    }
}

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

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
    address P;
    int cnt,half,i;
    P = First(L);

    cnt = NbElmt(L);
    half = cnt / 2;
        for (i = 1; i <= half; i++){
            InsVLast(L1,Info(P));
            P = Next(P);
        }
        for (i = half + 1; i <= cnt; i++){
            InsVLast(L2,Info(P));
            P = Next(P);
        }

}


/*
               _______________________________________
   (\___(\   ||                                       ||
  \(   '^')/ || Congratulations, you have leveled up! ||
   o(")==(") || You have reached Lv. X                ||
             ||_______________________________________||
*/
