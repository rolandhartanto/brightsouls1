#include <stdio.h>
#include "matriks.h"

int main(){
	//cek makematriks
	MATRIKS M;
	int NB,NK,i,j,X;
	printf("masukkan jumlah elemen baris dan kolom\n");
	scanf("%d %d",&NB,&NK);
	MakeMATRIKS(NB,NK,&M);
	printf("jumlah elemen baris dan kolom: %d %d\n",NBrsEff(M), NKolEff(M));
	printf("indeks pertama baris: %d\n",GetFirstIdxBrs(M));
	printf("indeks pertama kolom: %d\n",GetFirstIdxKol(M));
	printf("indeks terakhir baris: %d\n",GetLastIdxBrs(M));
	printf("indeks terakhir kolom: %d\n",GetLastIdxKol(M));
	
	for(i=1;i<=NB;i++){
		for(j=1;j<=NK;j++){
			scanf("%d",&X);
			Elmt(M,i,j)=X;
		}
	}
	TulisMATRIKS(M);
	return 0;
}