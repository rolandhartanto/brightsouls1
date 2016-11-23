#include <stdio.h>
#include "mapgen.h"
#include "listlinier.h"
#include "graph.h"
#include "movement.h"

void Overworld(){
    char input;
    List Seed;
    int x,y,i;
    POINT CurPos;
    boolean stop;
    MATRIKS M;

    // Buat prosedur load to map;
    GenerateNewMap(&Seed, &x, &y);					//Initialize first map

    Absis(CurPos) = Info(First(Seed));				//Initialize starting X position
    Ordinat(CurPos) = Info(Next(First(Seed)));				//Initialize startiny Y position

    PrintMap(Seed,CurPos,&M);
    while (!stop){

        printf("\n");
        scanf("%c",&input);
        if(input == 'W'){ //UP
            GoLeft(&M,&CurPos);
        }
        else if(input == 'S'){ //DOWN
            GoRight(&M,&CurPos);
        }
        else if(input == 'A'){ //LEFT
            GoDown(&M,&CurPos);
        }
        else if(input == 'D'){ //RIGHT
            GoUp(&M,&CurPos);
        }
        ClearScreen();
        if(Absis(CurPos) > MaxN || Absis(CurPos) < 1 || Ordinat(CurPos) > MaxN || Ordinat(CurPos) < 1){     // TRANSFER
            GenerateNextMap(&Seed,&x,&y);

            Absis(CurPos) = Info(First(Seed));				        //Initialize starting X position
            Ordinat(CurPos) = Info(Next(First(Seed)));				//Initialize startiny Y position
        }
        PrintMap(Seed,CurPos,&M);
    }
}
