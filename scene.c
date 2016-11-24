#include <stdio.h>
#include "mapgen.h"
#include "movement.h"
#include "ADTgui.h"
#include "graph.h"

Graph Map;
List Seed;
POINT CurPos;

void Title(){
    char name[11]={0};

    char x;
    int b = 1, s = 0;//b status program jalan ato berhenti, s status start ato blm
    int lvl = 1,hp = 100,str = 2,def = 2,exp = 0;
    loadingBar();
    while(b){
        if(s==1){
            printGUIInGame(name,lvl,hp,str,def,exp);
        }else{
            printMainMenu();
            pilihOpsi(name,&b,&s);
        }
    }
}

void InitGame(){
    CreateEmptyGraph(&G)
    GenerateNewMap(&Seed, &x, &y);					//Initialize first map
    Absis(CurPos) = Info(First(Seed));				//Initialize starting X position
    Ordinat(CurPos) = Info(Next(First(Seed)));				//Initialize startiny Y position
}

void Overworld(){
    char input;
    int x,y,i;
    boolean stop;
    MATRIKS M;

    // Buat prosedur load to map;
    InitGame();
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
