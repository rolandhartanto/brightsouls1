#include "queue.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include "mesinkar.h"
#include "stackofq.h"

typedef struct{
	char cmd[2];
	boolean hide;
} Command;


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

boolean isBattleEnd(int cntr, int maxTurn, Player P, Enemy E){
	return (cntr >= maxTurn || HP(P) <= 0 || HP(E) <= 0);
}

//HP Player -= STR Musuh  - DEF * offset; offset tergantung aksi player&musuh (kalo block kena flank, offset 0; kalo flank kena attack, offset 0.7; kalo draw (attack-attack / flank-flank, 0.8)
int PDmgCntr(Player Pl, Enemy El, char P, int rslt){
	int dmg;
	if(rslt == 0){
		if (P == 'B'){ //BB
			dmg = 0;
		}
		else if (P == 'F' || P == 'A'){ //FF atau AA
			dmg = 0.8 * ATKE(El);
		}
	}
	else if(rslt == -1){
		if (P == 'B'){ //BF
			dmg = ATKE(El);
		}
		else if (P == 'F'){
			dmg = (ATKE(El) * 12)/10; //FA
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
			dmg = 0 //FB
		}
		else if (P == 'A'){
			dmg = (ATKE(El)*8)/10; //AF
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

int EDmgCntr(Player Pl, Enemy El, char P, int rslt){
	int dmg;
	if(rslt == 0){
		if (P == 'B'){ //BB
			dmg = 0;
		}
		else if (P == 'F' || P == 'A'){ //FF atau AA
			dmg = (ATK(Pl)*8)/10;
		}
	}
	else if(rslt == -1){
		if (P == 'B'){ //BF
			dmg = 0;
		}
		else if (P == 'F'){
			dmg = (ATK(Pl)) * 8)/10; //FA
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
			dmg = ATK(Pl) //FB
		}
		else if (P == 'A'){
			dmg = (ATK(Pl)*12)/10; //AF
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
	for(i=1;i<=4;i++){
		SalinKata();
		if (CKata == 'A'){
			Add(Q,'A');
		}
		else if(CKata =='B'){
			Add(Q,'B');
		}
		else if(CKata =='F'){
			Add(Q,'F');
		}
	}
	SalinKata(); //in case ada enter tiap line
}

void RandomizeStack(StackQ * S,int x){
	Queue Q[20]
	int n,c;

	n = 0;
	while(!EndKata){
		ReadCmd(&Q[n]);	//Read X Lines
		n++;
	}

	for(n=1;n<=x;n++){
		c = rand() % (n-1);
		PushSQ(*S,Q[c]); //Push X Lines
		n++;
	}
}

void PrintCmd(Queue Q){
	int x,y,cnt;
	int e;
	Queue R;

	R = Q;
	x = rand() % 3 + 1;
	y = rand() % 3 + 1;

	for (cnt = 1; cnt<= 4; c++){
			DelQ(&R,&e);
			if (cnt == x || cnt == y){
				printf("# ");
			}
			else{
				printf("%c ",e);
			}
		}
	}
}

void BattleProcessing(Player * P, Enemy * E){
	// Print Enemy / Player Status / Message
	int i,turn,x;
	char cmd[4],enemyin;
	StackQ En;
	Queue Q;

	CreateEmptySQ(&En);
	CreateEmptyQ(&Q);

	//Generate Stack
	if(Boss(E)){
		x = 20;
	}
	else{
		x = 10;
	}
	RandomizeStack(&En,x);
	turn = 1;

	while(!isBattleEnd(turn,x,*P,*E)){
		PopSQ(&En,&Q);
		//Print Enemy Command
		PrintCmd(Q);

		//Player Input
		printf("Input 4 Attack Commands : ")
		for(i = 1; i<=4; i++){
			scanf("%c ",cmd[i]);
		}


		//Input Processing
		for(i = 1; i<=4; i++){
			Del(&Q,&enemyin);
			x = RPSComparator(cmd[i],enemyin);
			if(x == 1){
				if(cmd[i] == 'B'){ //B v B
					printf("%s tries to attack!",NamaE(*E));
					printf("But %s blocked foe %s's attack", NamaP(*P), NamaE(*E));
				}
				if(cmd[i] == 'F'){ //B v B
					printf("%s tries to block!",NamaE(*E));
					printf("But %s flanked and break trough foe %s's defense", NamaP(*P), NamaE(*E));
				}
				if(cmd[i] == 'A'){ //B v B
					printf("%s tries to flank!",NamaE(*E));
					printf("But %s attacked foe %s's right trough", NamaP(*P), NamaE(*E));
				}
			}
			else if(x == 0){
				if(cmd[i] == 'B'){ //B v B
					printf("%s and %s blocked at the same time", NamaP(*P), NamaE(*E));
				}
				if(cmd[i] == 'F'){ //B v B
					printf("%s and %s flanked at the same time", NamaP(*P), NamaE(*E));
				}
				if(cmd[i] == 'A'){ //B v B
					printf("%s and %s flanked at the same time", NamaP(*P), NamaE(*E));
				}
			}
			else if(x == -1){
				if(cmd[i] == 'B'){ //B v B
					printf("%s tries to attack!",NamaP(*P));
					printf("But foe %s blocked %s's attack", NamaE(*E), NamaP(*P));
				}
				if(cmd[i] == 'F'){ //B v B
					printf("%s tries to block!",NamaP(*P));
					printf("But foe %s flanked and break trough %s's defense", NamaE(*E), NamaP(*P));
				}
				if(cmd[i] == 'A'){ //B v B
					printf("%s tries to flank!",NamaP(*P));
					printf("But foe %s attacked %s's right trough", NamaE(*E), NamaP(*P));
				}
			}
			HP(*P) -= PDmgCntr(P,E,cmd[i],x);
			HPE(*E) -= EDmgCntr(P,E,cmd[i],x);

		}
		turn++;
		if (HP(P) <= 0){
			GameOver(); //GameOver Handler
		}
}
