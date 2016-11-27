#include "scene.h"


Graph G;
List Seed;
POINT CurPos;
addressg CurMap;
int xfirst,yfirst;


Player P;

void Title(){
    char name[11]={0};

    char x;
    int b = 1, s = 0;//b status program jalan ato berhenti, s status start ato blm
    int lvl = 1,hp = 100,str = 2,def = 2,exp = 0;
    loadingBar();
    while(b){
        if(s==1){
            Overworld();
        }else{
            printMainMenu();
            pilihOpsi(name,&b,&s);
            strcpy(Nama(P),name);
        }
    }
}

void InitGame(){
    int x,y;

    CreateEmptyGraph(&G);                                   //Initialize Graph for map teleportation
    GenerateNewMap(&Seed, &x, &y);					        //Initialize first map
    Absis(CurPos) = Info(First(Seed));				        //Initialize starting X position
    Ordinat(CurPos) = Info(Next(First(Seed)));				//Initialize startiny Y position
    InsVFirstGraph(&G,Seed);                                //Add First map to Graph

    CreatePlayer(&P);                                       //Initialize player
    InitPlayer(&P);                                         //


    CurMap = First(G);
    xfirst = x;
    yfirst = y;
}


void Overworld(){
  char input;
  int x,y,i,xs,ys,xe,ye;
  boolean stop;
  MATRIKS M;
  int mapcount,gameover;
  Enemy E;

  // Buat prosedur load to map;
  stop = false;
  InitGame();
  mapcount = 1;
	ClearScreen();
  // Controls GUI Generation for first print
  PrintHeader(Nama(P),HP(P),Str(P),Def(P),Level(P),Exp(P),NextEXP(P));
  PrintMap(Seed,CurPos,&M);
  x = xfirst;
  y = yfirst;
	i = 0;
	printf(    "_________________________________________________________________________________________________\n\n");
	printf("                                         \n");
	printf(    "_________________________________________________________________________________________________\n");
    while (!stop){
		    printf("\n\tInput : ");
        scanf(" %c",&input);
        printf("\n\n\n");
        input = toupper(input);
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
                    mapcount++;
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

        // Controls GUI Generation on map update
        PrintHeader(Nama(P),HP(P),Str(P),Def(P),Level(P),Exp(P),NextEXP(P));
        PrintMap(Seed,CurPos,&M);
		printf(    "_________________________________________________________________________________________________\n\n");
		if (ItemFlag){
			printf("\t\t  > Kamu mendapatkan Obat! " col_lgreen "HP+10" col_reset"\n");
            HP(P) += 10;
            //printf("%d",HPMax(P));
            if(HP(P) >= HPMax(P)){      //Case HP > HPMax
                HP(P) = HPMax(P);
            }
			ItemFlag = false;
		}
		else if(EnemyFlag){
			printf("\t\t  > Ada " col_red "musuh" col_reset" muncul!\n");
      printf(    "_________________________________________________________________________________________________\n");
      initEnemy(&E, mapcount, false);
      delay(1500);
      BattleProcessing(&P, &E, &gameover);
			EnemyFlag = false;
      PrintHeader(Nama(P),HP(P),Str(P),Def(P),Level(P),Exp(P),NextEXP(P));
      PrintMap(Seed,CurPos,&M);
      printf(    "\n\n_________________________________________________________________________________________________\n\n\n\n");
		}
		else if(BossFlag){
			printf("\t\t  > Ada "col_purple"boss"col_reset " muncul!\n");
      printf(    "_________________________________________________________________________________________________\n");
      initEnemy(&E, mapcount, true);
      delay(1500);
      BattleProcessing(&P,&E,&gameover);
			BossFlag = false;
      PrintHeader(Nama(P),HP(P),Str(P),Def(P),Level(P),Exp(P),NextEXP(P));
      PrintMap(Seed,CurPos,&M);
      printf(    "\n\n_________________________________________________________________________________________________\n\n\n\n");

		}
		else if(WallFlag){
			printf("\t\t  > Kamu menabrak tembok             \n");
			WallFlag = false;
		}
		else{
			printf("                                         \n");
		}
		printf(    "_________________________________________________________________________________________________\n");

    if(gameover == 1){
      ClearScreen();
      printGameOver();
      delay(3500);
      ClearScreen();
      printCredits();
      delay(3500);
      ClearScreen();
      stop = true;
    }
    }

}
