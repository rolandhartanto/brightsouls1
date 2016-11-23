#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listlinier.h"
#include "boolean.h"
#include "movement.h"
#include "ADTgui.h" 			// Delete in use

#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

#define MaxN 20
#define MinPath 100

typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    (*M).NBrsEff = NB;
    (*M).NKolEff = NK;
}

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

void nextBlock(int * xa, int * ya, int x, int y, int c) {
	if (c == 0){
		*xa = x + 1;
		*ya = y;
	}
	else if (c == 1){
		*xa = x;
		*ya = y + 1;
	}
	else if(c == 2){
		*xa = x - 1;
		*ya = y;
	}
	else if(c == 3){
		*xa = x;
		*ya = y - 1;
	}
}

boolean PathOK(MATRIKS map, int xa, int ya, int x, int y, int c, int count, int prev) {
    boolean oke;
    int xd, yd;

    oke = true;
    if (count < MinPath){
        if((xa != 1 && xa != MaxN) && (ya != 1 && ya != MaxN)){
			oke = true;
        }
        else{
            oke = false;
        }
	}
	return oke;
}

void GenerateStart(int * x, int * y){
    int c, a, b;

    srand(time(NULL));			//  Random Seed Init

    do{
       c =(rand() % 2);					//	Init C
	   //a = (rand() % 2);					//  Randomize Edge
	   a = ((rand() % MaxN) + 1);		//  Randomize Number
	   b = ((rand() % MaxN) + 1);		//  Randomize Number

	   //if (a == 0){							//
		 // a = MaxN;							//
	   //}									//
	}
    while(a == b);


	if (c == 0){				//
		*x = a;					//
		*y = b;					//
	}							//	Set starting point
	else if(c == 1){			//  based on c
		*x = b;					//
		*y = a;					//
	}							//


}

void GenerateSeed(List * Seed, int * xs, int * ys,boolean * fail){
	int count,prev,prev2,prevc;
	int xa,ya,x,y,a,b;
	int lc,llc,c;
	double start,end;
	boolean exit,finish;
	MATRIKS map;

	*fail = false;
	MakeMATRIKS(MaxN,MaxN,&map);//
	for(a=1;a<=MaxN;a++){		//
		for(b=1;b<=MaxN;b++){	//  Map Init
			Elmt(map,a,b) = 3;	//
		}						//
	}							//

	Elmt(map,*xs,*ys) = 0;



	count = 0;
	lc = 0;							// Init lc
	llc = 0;						// Init llc
	finish = false;					// Init Finish variable

	InsVLast(Seed,*xs);				// Insert X and Y
	InsVLast(Seed,*ys);				// into Seed

	prev2 = -1;						// Init Prev2 & Prev
	prev = -1;						//

	count = count + 1;				//
	//printf("%d, %d\n",*xs,*ys); // DEBUGGER
	x = *xs;						// Init xa
	y = *ys;						// Init ya
	start = clock();
	do{
		exit = false;				// Init exit variable
		while(!exit){
			xa = x;					// Init xa based on last x position
			ya = y;					// Init ya based on last y position
			c = rand() % 4;

			nextBlock(&xa, &ya, x, y, c);
			//printf("%d : %d, %d",c,xa,ya); // DEBUGGER
			end = clock();
			if ((end-start)>=0.01){
				*fail = true;
				break;
			}
			if(PathOK(map, xa, ya, x, y, c, count,prev2) && Elmt(map,xa,ya) == 3 && (xa<=MaxN && xa>=1) && (ya<=MaxN && ya>=1)){
				//printf("%d : %d, %d",c,xa,ya); // DEBUGGER
				//printf(" accept V\n"); // DEBUGGER
				exit = true;
			}

			else{
				xa = x;				// Reset xa
				ya = y;				// Reset ya
				//printf(" reject\n"); // DEBUGGER
			}
		}

		count++;
		Elmt(map,xa,ya)=0;
		InsVLast(Seed,c);
		x = xa;
		y = ya;

		if ((x == 1 || x == MaxN || y== 1 || y == MaxN) && count >= MinPath){
			*xs = x;
			*ys = y;
			finish = true;
		}
	} while(!finish);
}

void CountNextStart(int * xs, int * ys){
	if (*xs == 1){
		*xs = MaxN;
	}
	else if (*xs == MaxN){
		*xs = 1;
	}
	if (*ys == 1){
		*ys = MaxN;
	}
	else if (*ys == MaxN){
		*ys = 1;
	}
}

void GenerateNewMap(List * Seed,int * xs,int * ys){
	boolean fail;
	int a,b;

	srand(time(NULL));			//  Random Seed Init
	GenerateStart(xs,ys);		// 	Generate Starting Point
	//printf("start %d %d\n",*xs,*ys);
	do{
		a = *xs;
		b = *ys;
		fail = false;
		CreateEmpty(Seed);			//  Init Seed
		GenerateSeed(Seed,&a,&b,&fail); //  Generate Map Seed
	}while(fail);
	*xs = a;
	*ys = b;
}

void GenerateNextMap(List * Seed,int * xs,int * ys){
	int a,b;
	boolean fail;


	//srand(time(NULL));		//  Random Seed Init
	CountNextStart(xs,ys);		// 	Generate Starting Point

	do{
		fail = false;
		a = *xs;
		b = *ys;
		CreateEmpty(Seed);			//  Init Seed
		GenerateSeed(Seed,&a,&b,&fail); //  Generate Map Seed
	}while(fail);
	//printf("in   x:%d y:%d\n",*ys,*xs);
	*xs = a;
	*ys = b;
	//printf("exit x:%d y:%d\n",b,a);
}

void TulisMap (MATRIKS M, POINT Pos){
    int i,j;
    for(i =GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
        for(j=GetFirstIdxKol(M); j<GetLastIdxKol(M); j++){
			if (i == Absis(Pos) && j == Ordinat(Pos)){
				printf("P");
			}
			else{
				if(Elmt(M,i,j)==0){
					printf(" ");
        		}
				else if(Elmt(M,i,j)==1){
					printf("I");
				}
				else if(Elmt(M,i,j)==2){
					printf("E");
				}
				else if(Elmt(M,i,j)==3){
					printf("#");
        		}
			}
		}
		if (i == Absis(Pos) && j == Ordinat(Pos)){
			printf("P\n");
		}
		else{
			if(Elmt(M,i,j)==0){
				printf(" \n");
			}
			else if(Elmt(M,i,j)==1){
				printf("I\n");
			}
			else if(Elmt(M,i,j)==2){
				printf("E\n");
			}
			else if(Elmt(M,i,j)==3){
				printf("#\n");
			}
		}
    }
}

void PrintMap(List Seed, POINT Pos, MATRIKS * map){
	int xs,ys,x,y,c,a,b;
	address P;

	a = xs;
	b = ys;

	MakeMATRIKS(MaxN,MaxN,map);//
	for(a=1;a<=MaxN;a++){		//
		for(b=1;b<=MaxN;b++){	//  Map Init
			Elmt(*map,a,b) = 3;	//
		}						//
	}							//

	xs = Info(First(Seed));
	ys = Info(Next(First(Seed)));
	Elmt(*map,xs,ys) = 0;

	P = Next(Next(First(Seed)));

	while(P != Nil){
		c = Info(P);
		nextBlock(&x,&y,xs,ys,c);
		Elmt(*map,x,y)=0;
		xs = x;
		ys = y;

		P = Next(P);
	}
	TulisMap(*map,Pos);
}
