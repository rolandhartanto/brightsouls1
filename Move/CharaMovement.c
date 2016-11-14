#include "matriks.h"
#include "boolean.h"
#include <stdio.h>
#include "point.h"

void Swap(char X, char Y)
{
	char temp;
	
	temp = X;
	X = Y;
	Y = temp;
}
/*Menukar isi matriks*/

POINT CekPosisi(MATRIKS M)
{
	
	int i, j;
	boolean found = false;
	
	i = 1;
	j = 1;
	
	while ((i <= NBrsEff(M)) && (!found))
	{
		while((j <= NKolEff(M)) && (!found))
		{
			if(Elmt(M,i,j) == 'P')/*P = Player*/
			{
				Absis(P) = i;
				Ordinat(P) = j;
				return P;
			}
			else 
				j++;
		}
		i++;
	}
	
}
/*Mengecek posisi karakter*/

void GoUp(MATRIKS M, char X)
{
	int i, j;
	POINT P = CekPosisi(M);
	
	i = Absis(P);
	j = Ordinat(P);
	if(Elmt(M,i,j-1) != '#') /* # = tidak dapat dilewati */
	{
		X = Elmt(M,i,j-1);
		if(Elmt(M,i,j-1) != '-') /* - = bisa dilewati tapi tidak mengandung apapun */
		{
			Elmt(M,i,j-1) = '-';
		}
		Swap(Elmt(M,i,j-1),Elmt(M,i,j));
		
	}
}
/*	Gunakan X untuk mempermudah mendeteksi apa yang ditemui diatas
	karakter tersebut */
	
void GoDown(MATRIKS M, char X)
{
	int i, j;
	POINT P = CekPosisi(M);
	
	i = Absis(P);
	j = Ordinat(P);
	if(Elmt(M,i,j+1) != '#') /* # = tidak dapat dilewati */
	{
		X = Elmt(M,i,j+1);
		if(Elmt(M,i,j+1) != '-') /* - = bisa dilewati tapi tidak mengandung apapun */
		{
			Elmt(M,i,j+1) = '-';
		}
		Swap(Elmt(M,i,j+1),Elmt(M,i,j));
		
	}
}

void GoLeft(MATRIKS M, char X)
{
	int i, j;
	POINT P = CekPosisi(M);
	
	i = Absis(P);
	j = Ordinat(P);
	if(Elmt(M,i-1,j) != '#') /* # = tidak dapat dilewati */
	{
		X = Elmt(M,i-1,j);
		if(Elmt(M,i-1,j) != '-') /* - = bisa dilewati tapi tidak mengandung apapun */
		{
			Elmt(M,i-1,j) = '-';
		}
		Swap(Elmt(M,i-1,j),Elmt(M,i,j));
		
	}
}

void GoRight(MATRIKS M, char X)
{
	int i, j;
	POINT P = CekPosisi(M);
	
	i = Absis(P);
	j = Ordinat(P);
	if(Elmt(M,i+1,j) != '#') /* # = tidak dapat dilewati */
	{
		X = Elmt(M,i+1,j);
		if(Elmt(M,i+1,j) != '-') /* - = bisa dilewati tapi tidak mengandung apapun */
		{
			Elmt(M,i+1,j) = '-';
		}
		Swap(Elmt(M,i+1,j),Elmt(M,i,j));
		
	}
}
