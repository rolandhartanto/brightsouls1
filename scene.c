#include <stdio.h>
#include "mapgen.h"
#include "movement.h"
#include "ADTgui.h"
#include "graph.h"

Graph G;
List Seed;
POINT CurPos;
addressg CurMap;
int xfirst,yfirst;



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
    int x,y;
    CreateEmptyGraph(&G);
    GenerateNewMap(&Seed, &x, &y);					//Initialize first map
    Absis(CurPos) = Info(First(Seed));				//Initialize starting X position
    Ordinat(CurPos) = Info(Next(First(Seed)));				//Initialize startiny Y position
    InsVFirstGraph(&G,Seed);
    CurMap = First(G);
    xfirst = x;
    yfirst = y;
}


void Overworld(){
    char input;
    int x,y,i,xs,ys,xe,ye;
    boolean stop;
    MATRIKS M;
	
    // Buat prosedur load to map;
    InitGame();
	ClearScreen();
    PrintMap(Seed,CurPos,&M);
    x = xfirst;
    y = yfirst;
	i = 0;
	printf("_____________________________________________\n");
	printf("                                         \n");
	printf("_____________________________________________\n");
    while (!stop){		
		printf("\n");
        scanf(" %c",&input);
        if(input == 'W'){ //UP
            GoLeft(&M,&CurPos,&Seed);
        }
        else if(input == 'S'){ //DOWN
            GoRight(&M,&CurPos,&Seed);
        }
        else if(input == 'A'){ //LEFT
            GoDown(&M,&CurPos,&Seed);
        }
        else if(input == 'D'){ //RIGHT
            GoUp(&M,&CurPos,&Seed);
        }
        
        ClearScreen();
        if(Absis(CurPos) > MaxN || Absis(CurPos) < 1 || Ordinat(CurPos) > MaxN || Ordinat(CurPos) < 1){     // TRANSFER
            xs = Info(First(Seed));
    		ys = Info(Next(First(Seed)));

            //Find Exit Point
            if(Absis(CurPos) < 1){
                ye = Ordinat(CurPos);
                xe = Absis(CurPos)+1;
            }
            else if(Absis(CurPos) > MaxN){
                ye = Ordinat(CurPos);
                xe = Absis(CurPos)-1;
            }
            else if(Ordinat(CurPos) < 1){
                ye = Ordinat(CurPos)+ 1;
                xe = Absis(CurPos);
            }
            else if(Ordinat(CurPos) > MaxN){
                ye = Ordinat(CurPos)- 1;
                xe = Absis(CurPos);
            }


			if (xe == Info(First(Seed)) && ye == Info(Next(First(Seed)))){ //Back to prev map
				CurMap = Prev(CurMap);
				Seed = Info(CurMap);
                CountNextStart(&xe,&ye);
                Absis(CurPos) = xe;
                Ordinat(CurPos) = ye;
			}
			else{
				if(Next(CurMap) == Nil){ //Generate next map
	        	    GenerateNextMap(&Seed,&x,&y);
    	    	    Absis(CurPos) = Info(First(Seed));				        //Initialize starting X position
    	    	    Ordinat(CurPos) = Info(Next(First(Seed)));				//Initialize startiny Y position
    	    	    InsVLastGraph(&G,Seed);
    	    	    CurMap = Next(CurMap);
    	    	}
                else{ //Goto next
                    CurMap = Next(CurMap);
    				Seed = Info(CurMap);

                    CountNextStart(&xe,&ye);
                    Absis(CurPos) = xe;
                    Ordinat(CurPos) = ye;
                }
        	}
        }
        PrintMap(Seed,CurPos,&M);
		printf(    "______________________________________________\n");
		if (ItemFlag){
			printf("        Kamu mendapatkan barang!         \n");
			ItemFlag = false;
		}
		else if(EnemyFlag){	
			printf("        Ada musuh muncul!                \n");
			EnemyFlag = false;
		}
		else if(BossFlag){
			printf("        Ada boss muncul!                 \n");
			BossFlag = false;
		}
		else if(WallFlag){
			printf("        Kamu menabrak tembok             \n");			
			WallFlag = false;
		}
		else{
			printf("                                         \n");
		}
		printf(    "______________________________________________\n");
    }
	
	
	
}
