#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
#include "listlinier.h"
#include "boolean.h"

#define MaxN 15
#define MinPath 25

void nextBlock(int * xa, int * ya, int x, int y, int c)
{
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

boolean PathOK(MATRIKS map, int xa, int ya, int x, int y, int c, int count)
{
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
    
    /*printf("xa = %d, ya = %d",xa,ya);
    if(oke){
        printf(" accept\n");   
    }
    else{
        printf(" reject\n");
    }*/
        
    return oke;
}

void GenerateStart(int * x, int * y){
    int c, a, b;
    
    srand(time(NULL));			//  Random Seed Init
    
    do{
       c =(rand() % 99)%2;					//	Init C
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

void GenerateSeed(List * Seed, int * xs, int * ys){
	int count;
	int xa,ya,x,y,a,b;
	int lc,llc,c;
	boolean exit,finish;
	MATRIKS map;
	
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

	count = count + 1;				//
	printf("%d, %d\n",*xs,*ys); // DEBUGGER
	x = *xs;						// Init xa
	y = *ys;						// Init ya
	do{
		exit = false;				// Init exit variable
		while(!exit){
			xa = x;					// Init xa based on last x position
			ya = y;					// Init ya based on last y position
			c = rand() % 4;
			
			nextBlock(&xa, &ya, x, y, c);
			//printf("%d : %d, %d",c,xa,ya); // DEBUGGER
			if(PathOK(map, xa, ya, x, y,c, count) && Elmt(map,xa,ya) == 3 && (xa<=MaxN && xa>=1) && (ya<=MaxN && ya>=1)){
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
	else if (*ys == 1){
		*ys = MaxN;
	}
	else if (*xs == MaxN){
		*xs = 1;
	}
	else if (*ys == MaxN){
		*ys = 1;
	}
}

void GenerateNewMap(List * Seed,int * xs,int * ys){
	
	CreateEmpty(Seed);			//  Init Seed
	
	srand(time(NULL));			//  Random Seed Init
	GenerateStart(xs,ys);		// 	Generate Starting Point
	GenerateSeed(Seed,xs,ys); //  Generate Map Seed
}

void GenerateNextMap(List * Seed,int * xs,int * ys){
	CreateEmpty(Seed);			//  Init Seed
	
	//srand(time(NULL));		//  Random Seed Init
	CountNextStart(xs,ys);		// 	Generate Starting Point
	GenerateSeed(Seed, xs, ys); //  Generate Map Seed
}

void PrintMap(List Seed){
	MATRIKS map;
	int xs,ys,x,y,c,a,b;
	address P;
	
	a = xs;
	b = ys;
	
	MakeMATRIKS(MaxN,MaxN,&map);// 
	for(a=1;a<=MaxN;a++){		//
		for(b=1;b<=MaxN;b++){	//  Map Init
			Elmt(map,a,b) = 3;	//
		}						//
	}							//
	
	xs = Info(First(Seed));
	ys = Info(Next(First(Seed)));
	Elmt(map,xs,ys) = 0;
	
	P = Next(Next(First(Seed)));
	
	while(P != Nil){
		c = Info(P);
		nextBlock(&x,&y,xs,ys,c);
		Elmt(map,x,y)=0;
		xs = x;
		ys = y;
		
		P = Next(P);
	}
	TulisMATRIKS(map);
}

int main(){
    List Seed;
	int xs,ys;
	
	GenerateNewMap(&Seed,&xs,&ys);
	PrintMap(Seed);printf("\n");
    PrintInfo(Seed);
    printf("\n\n");
	GenerateNextMap(&Seed,&xs,&ys);
    PrintMap(Seed);printf("\n");
    PrintInfo(Seed);
    printf("\n\n");
    GenerateNextMap(&Seed,&xs,&ys);
    PrintMap(Seed);printf("\n");
    PrintInfo(Seed);
    printf("\n\n");
	return 0;
}