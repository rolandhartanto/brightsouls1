/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype{} */ /* type infotype sesuai pada modul listrek */
/* *** Konstruktor *** */

void BuildTree (BinTree *P,infotypeB info){
	if(IsTreeEmpty(*P)){
		*P=AlokNode(info);
	}else if(IsTreeOneElmt(*P)){
		Left(*P)=AlokNode(info);
	}else if(IsUnerLeft(*P)){
		Right(*P)=AlokNode(info);
	}else if(IsBiner(*P)){
		BuildTree(&Left(*P),info);
	}
}

void BuildTreeFromFile(BinTree *T){
	int i=0, val; char tkn;
	infotypeB info;
	*T=Nil;
	STARTTOKEN();
	if(EndToken){
		*T=Nil;
	}else{
		while(!EndToken){
			if(CToken.ID=='b'){
				val=CToken.val;
			}else{
				tkn=CToken.ID;
			}
			ADVTOKEN();
			i++;
			if((i>0)&&(i%2==0)){
				info.ID=i; info.val=val; info.tkn=tkn;
				BuildTree(T,info);
			}
		}

	}
}


addrNode AlokNode (infotypeB X){
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	addrNode P;
	P=(addrNode)malloc(sizeof(Node));
	if(P!=Nil){//alokasi berhasil
		Akar(P)=X;
		Left(P)=Nil;
		Right(P)=Nil;
	}
	return(P);
}
void DealokNode (addrNode P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
	free(P);
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P){
/* Mengirimkan true jika P adalah pohon biner kosong */
	return(P==Nil);
}
boolean IsTreeOneElmt (BinTree P){
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
	if(IsTreeEmpty(P)){
		return(false);
	}else{//tidak kosong
		return((Left(P)==Nil)&&(Right(P)==Nil));
	}
}
boolean IsUnerLeft (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
	if(IsTreeEmpty(P)){
		return(false);
	}else{
		return((Left(P)!=Nil)&&(Right(P)==Nil));
	}
}
boolean IsUnerRight (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
	if(IsTreeEmpty(P)){
		return(false);
	}else{
		return((Left(P)==Nil)&&(Right(P)!=Nil));
	}
}
boolean IsBiner (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
	if(IsTreeEmpty(P)){
		return(false);
	}else{
		return((Left(P)!=Nil)&&(Right(P)!=Nil));
	}
}
/* *** Traversal *** */

boolean IsAllTaken(BinTree P){
	if(Akar(P).val==0){
		if(IsTreeOneElmt(P)){
			return(true);
		}else if(IsUnerLeft(P)){
			return(IsAllTaken(Left(P)));
		}else if(IsUnerRight(P)){
			return(IsAllTaken(Right(P)));
		}else if(IsBiner(P)){
			return((IsAllTaken(Right(P))&&(IsAllTaken(Left(P)))));
		}

	}else{
		return(false);
	}
}

void ToBeTaken(BinTree P,TabInt * T){
/*I.S: IsAllTaken=false */
	if(Akar(P).val!=0){
		AddAsLastEl(T,Akar(P).ID);
	}else{//kalau valnya = 0
		if(IsUnerLeft(P)){
			ToBeTaken(Left(P),T);
		}else{
			if(!IsTreeOneElmt(P)){
				ToBeTaken(Left(P),T);
				ToBeTaken(Right(P),T);
			}
		}
	}
}

void SearchNode(BinTree P, int ID,addrNode *P1){
	if(Akar(P).ID==ID){
		*P1=P;
	}else{
		if(IsUnerLeft(P)){
			(SearchNode(Left(P),ID,P1));
		}else{
			if(!IsTreeOneElmt(P)){
				SearchNode(Left(P),ID,P1);
				SearchNode(Right(P),ID,P1);
			}
		}
	}
}

void PrintTree1 (BinTree P, int h,int level){
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
int i;
BinTree temp=P;
	if(!IsTreeEmpty(P)){
		//print indentasi
		printf("%d:%c:%d\n",Akar(P).ID,Akar(P).tkn,Akar(P).val);
		if(!IsTreeEmpty(Left(P))){
			for(i=1;i<=h*level;i++){
				printf(" ");
			}
			PrintTree1(Left(P),h,level+1);
		}

		if(!IsTreeEmpty(Right(P))){
			for(i=1;i<=h*level;i++){
				printf(" ");
			}
			PrintTree1(Right(P),h,level+1);
		}

	}
}
void PrintTree (BinTree P, int h){
	PrintTree1(P,h,1);
}

boolean SearchIsi(BinTree P, int ID){
	if(IsTreeEmpty(P)){
		return false;
	}
	else{
		if(Akar(P).ID == ID){
			return true;
		}
		else{
			return (SearchIsi(Left(P),ID) || SearchIsi(Right(P),ID));
		}
	}
}

int Tingkat(BinTree P,addrNode A){
	if(IsTreeEmpty(P)){
		return 0;
	}
	else{
		if(Akar(P).ID == Akar(A).ID){
			return 1;
		}
		else{
			if(SearchIsi(Left(P),Akar(A).ID)){
				return (1 + Tingkat(Left(P),A));
			}
			else if(SearchIsi(Right(P),Akar(A).ID)){
				return (1 + Tingkat(Right(P),A));
			}
		}
	}
}
