/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MAPGEN_H
#define MAPGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listlinier.h"
#include "boolean.h"
#include "matriks.h"
#include "point.h"

#define MaxN 20
#define MinPath 80

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
