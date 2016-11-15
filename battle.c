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
		if((P == 'F' && E == 'B') || (P == 'B' && E == 'A') || (P == 'A' && E == 'F')){
			Out = 1;
		}
	}

	return Out;
}

boolean isBattleEnd(int cntr, int maxTurn, Player P, Enemy E){
	return (cntr == maxTurn || HP(P) == 0 || HP(E) == 0);
}

//HP Player -= STR Musuh  - DEF * offset; offset tergantung aksi player&musuh (kalo block kena flank, offset 0; kalo flank kena attack, offset 0.7; kalo draw (attack-attack / flank-flank, 0.8)
int PDmgCntr(Player Pl, Enemy El, char P, char E, int rslt){
	if(rslt == 0 && ){
		HP(Pl)
	}
	if(P == 'B' && rslt == -1){
		//Block attacked by flank
		HP(Pl) -= 1 * STR(El);
	}

}

int EDmgCntr(Player Pl, Enemy El, char P, char E, int rslt){
	if(rslt == 0 && ){
		HP(Pl)
	}
	if(P == 'B' && rslt == -1){
		//Block attacked by flank
		HP(Pl) -= 1 * STR(El);
	}

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

	while(!isBattleEnd(turn,x,P,E)){
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

			}
			else if(x == 0){
				if(cmd[i] == 'B' && 
			}
			else if(x == -1){

			}

		}
		turn++;
}
