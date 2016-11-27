#include "ADTgui.h"
#include "battle.h"
#include <stdlib.h>
#include <ctype.h>


#define Comd(P,i) (P).cmd[(i)]

void GameOver(){
	//SHOW GAME OVER SCREEN
}

int RPSComparator(char P, char E){
// Condition Output
// 0 = draw
// -1 = lose
// 1 = win

	int Out;

	if(P == E){
		Out = 0;
	}
	else if(P != E){
		if((P == 'B' && E == 'F') || (P == 'A' && E == 'B') || (P == 'F' && E == 'A')){
			Out = -1;
		}
		else if((P == 'F' && E == 'B') || (P == 'B' && E == 'A') || (P == 'A' && E == 'F')){
			Out = 1;
		}
	}

	return Out;
}

boolean isBattleEnd( int maxTurn, int cntr, Player P, Enemy E){

	return (cntr >= maxTurn || HP(P) <= 0 || HPE(E) <= 0);
}

//HP Player -= STR Musuh  - DEF * offset; offset tergantung aksi player&musuh (kalo block kena flank, offset 0; kalo flank kena attack, offset 0.7; kalo draw (attack-attack / flank-flank, 0.8)
int PDmgCntr(Player Pl, Enemy El, char P, int rslt){
	int dmg;
	if(rslt == 0){
		if (P == 'B'){ //BB
			dmg = 0;
		}
		else if (P == 'F' || P == 'A'){ //FF atau AA
			dmg = (8 * STRE(El))/10;
		}
	}
	else if(rslt == -1){
		if (P == 'B'){ //BF
			dmg = STRE(El);
		}
		else if (P == 'F'){
			dmg = (STRE(El) * 12)/10; //FA
		}
		else if (P == 'A'){ //AB
			dmg = 0;
		}
	}
	else if(rslt == 1){
		if (P == 'B'){
			dmg = 0; //BA
		}
		else if (P == 'F'){
			dmg = 0; //FB
		}
		else if (P == 'A'){
			dmg = (STRE(El)*8)/10; //AF
		}
	}

	if(dmg > 0){
		dmg -= Def(Pl);
	}
	if(dmg < 0){
		dmg = 0;
	}

	//printf("%d",dmg);
	return dmg;
}

int EDmgCntr(Player Pl, Enemy El, char P, int rslt){
	int dmg;
	if(rslt == 0){
		if (P == 'B'){ //BB
			dmg = 0;
		}
		else if (P == 'F' || P == 'A'){ //FF atau AA
			dmg = (Str(Pl)*8)/10;
		}
	}
	else if(rslt == -1){
		if (P == 'B'){ //BF
			dmg = 0;
		}
		else if (P == 'F'){

			//dmg = (ATK(Pl)) * 8/10; //FA

			dmg = (Str(Pl) * 8)/10; //FA

		}
		else if (P == 'A'){ //AB
			dmg = 0;
		}
	}
	else if(rslt == 1){
		if (P == 'B'){
			dmg = 0; //BA
		}
		else if (P == 'F'){
			dmg = Str(Pl); //FB
		}
		else if (P == 'A'){
			dmg = (Str(Pl)*12)/10; //AF
		}
	}

	if(dmg > 0){
		dmg -= DEFE(El);
	}
	if(dmg < 0){
		dmg = 0;
	}


	return dmg;
}
// Battle start
// file dibaca, masuk ke queue
// queue dipush ke stack

// stack di pop, jadi queue
// queue di del, masuk ke array

void ReadCmd(Queue * Q){
	//Baca huruf dari file, tiap 4 masuk ke queue lain,
	int i;
	CreateEmptyQ(Q,4);
	for(i=1;i<=4;i++){
		if (CKata.TabKata[1] == 'A'){
			AddQ(Q,'A');
		}
		else if(CKata.TabKata[1] =='B'){
			AddQ(Q,'B');
		}
		else if(CKata.TabKata[1] =='F'){
			AddQ(Q,'F');
		}
		//printf("%d : %c - ",i, CKata.TabKata[1]);
		ADVKATA();
	}
}

void RandomizeStack(StackQ * S,int x){
	Queue Q[30];
	int n,c;
	n = 0;
	STARTKATABTL();
	//CreateEmptySQ(S);
	while(!EndKata && n < 30){
		ReadCmd(&Q[n]);	//Read X Lines
		n++;
	}
	for(n=1;n<=x;n++){
		c = rand() % (30);
		PushSQ(S,Q[c]); //Push X Lines
		n++;
	}
}

void PrintCmd(Queue Q,char * cmd){
	int x,y,cnt;
	char e;
	Queue R;

	R = Q;
	do{
		x = rand() % 3 + 1;
		y = rand() % 3 + 1;
	}while(x==y);

	for (cnt = 1; cnt<= 4; cnt++){
			DelQ(&R,&e);
			cmd[cnt-1] = e;
			if (cnt == x || cnt == y){
				printf("# ");
			}
			else{
				printf("%c ",e);
			}
	}
}

void BattleProcessing(Player * P, Enemy * E){
	// Print Enemy / Player Status / Message
	int i,turn,maxt,x,n,temp;
	char plin,cmd[4],enemyin[4];
	Stack Input;
	StackQ En;
	Queue Q;

	CreateEmptySQ(&En);

	//Generate Stack
	if(Boss(*E)){
		maxt = 20;
	}
	else{
		maxt = 10;
	}

	RandomizeStack(&En,maxt);
	turn = 1;
	ClearScreen();
	while(!isBattleEnd(maxt,turn,*P,*E)){
		CreateEmptyQ(&Q,4);
		PopSQ(&En,&Q);
		//Print Enemy Command & Header
		PrintHeader(Nama(*P),HP(*P),Str(*P),Def(*P),Level(*P),Exp(*P),NextEXP(*P));
		PrintHeaderE(HPE(*E),STRE(*E),DEFE(*E));
		printf(    "_________________________________________________________________________________________________\n");
		printf("\n\n\t Enemy's Command : ");
		PrintCmd(Q,enemyin);
		printf("\n\n");
		printf(    "_________________________________________________________________________________________________\n");

		//debugger
		//printf("%c",enemyin[0]);
		//printf("%c",enemyin[1]);
		//printf("%c",enemyin[2]);
		//printf("%c",enemyin[3]);

		//Player Input
		printf("\n");
		printf("Input 4 Attack Commands : ");
		//Player Input
		CreateEmptyS(&Input);
		n = 0;
		while(n<4){
			scanf(" %c",&plin);
			plin = toupper(plin);
			if(plin != 'A' && plin != 'F' && plin != 'B' && plin != 'E'){
				printf("Command not detected\n");
			}
			else if(plin=='E'){
				PopS(&Input,&temp);
				n--;
			}
			else{
				PushS(&Input,plin);
				n++;
			}
		}

		for(i=3;i>=0;i--){
			PopS(&Input,&temp);
			cmd[i] = temp;
			printf("%d",cmd[i]);
		}

		printf("\n");
		ClearScreen();

		//Input Processing
		i = 0;
		while(i<=3 && HPE(*E)>0){
			PrintHeader(Nama(*P),HP(*P),Str(*P),Def(*P),Level(*P),Exp(*P),NextEXP(*P));
			PrintHeaderE(HPE(*E),STRE(*E),DEFE(*E));
			printf(    "_________________________________________________________________________________________________\n\n");
			x = RPSComparator(cmd[i-1],enemyin[i-1]);
			printf("\t\t\t\t\t -- Phase %d --\n",(i+1));
			if(x == 1){
				if(cmd[i] == 'B'){ //B v B
					printf("\t\t");
					printf("Foe tries to attack!\n");
					printf("\t\t");
					printf("But %s blocked foe's attack\n", NamaP(*P));
				}
				if(cmd[i] == 'F'){ //B v B
					printf("\t\t");
					printf("Foe tries to block!\n");
					printf("\t\t");
					printf("But %s flanked and break trough foe's defense\n", NamaP(*P));
				}
				if(cmd[i] == 'A'){ //B v B
					printf("\t\t");
					printf("Foe tries to flank!\n");
					printf("\t\t");
					printf("But %s attacked foe right trough\n", NamaP(*P));
				}
			}
			else if(x == 0){
				if(cmd[i] == 'B'){ //B v B
					printf("\t\t");
					printf("%s and foe blocked at the same time\n\n", NamaP(*P));
				}
				if(cmd[i] == 'F'){ //B v B
					printf("\t\t");
					printf("%s and foe flanked at the same time\n\n", NamaP(*P));
				}
				if(cmd[i] == 'A'){ //B v B
					printf("\t\t");
					printf("%s and foe attacked at the same time\n\n", NamaP(*P));
				}
			}
			else if(x == -1){
				if(cmd[i] == 'B'){ //B v B
					printf("\t\t");
					printf("%s tries to attack!\n",NamaP(*P));
					printf("\t\t");
					printf("But foe blocked %s's attack\n", NamaP(*P));
				}
				if(cmd[i] == 'F'){ //B v B
					printf("\t\t");
					printf("%s tries to block!\n",NamaP(*P));
					printf("\t\t");
					printf("But foe flanked and break trough %s's defense\n", NamaP(*P));
				}
				if(cmd[i]== 'A'){ //B v B
					printf("\t\t");
					printf("%s tries to flank!\n",NamaP(*P));
					printf("\t\t");
					printf("But foe attacked %s's right trough\n", NamaP(*P));
				}
			}
			printf("\n");
			HP(*P) -= PDmgCntr(*P,*E,cmd[i],x);
			if(HP(*P) < 0){
				HP(*P) = 0;
			}
			HPE(*E) -= EDmgCntr(*P,*E,cmd[i],x);
			if(HPE(*E) < 0){
				HPE(*E) = 0;

			i++;
			}

			printf(    "_________________________________________________________________________________________________\n");

			//debugger
			//printf("P %d E ",HP(*P));  system("usleep(%c)",x*1000);
			//printf("%d",HPE(*E));
			delay(1500);
			ClearScreen();
			if (HP(*P) <= 0){
				GameOver(); //GameOver Handler
			}
		}
		if(turn <= maxt && HP(*P) > 0){
			Exp(*P) += EXPE(*E);
			if(IsReadyNextLvl(Exp(*P),NextEXP(*P))){
				LevelUp(P);
			}
		}
		turn++;

	}
}
