/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MAPGEN_H
#define MAPGEN_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

void MakeMATRIKS (int NB, int NK, MATRIKS * M);

void nextBlock(int * xa, int * ya, int x, int y, int c);

boolean PathOK(MATRIKS map, int xa, int ya, int x, int y, int c, int count, int prev);

void GenerateStart(int * x, int * y);

void GenerateSeed(List * Seed, int * xs, int * ys,boolean * fail);

void CountNextStart(int * xs, int * ys);

void GenerateNewMap(List * Seed,int * xs,int * ys);

void GenerateNextMap(List * Seed,int * xs,int * ys);

void TulisMap (MATRIKS M, POINT Pos);

void PrintMap(List Seed, POINT Pos, MATRIKS * map);


#endif
