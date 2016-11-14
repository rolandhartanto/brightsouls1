#include "queue.h"
#include "boolean.h"
#include <stdio.h>

int RPSComparator(char P, char E);
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
int PDmgCntr(Player P, Enemy E, char P, char E, int rslt){
	if(rslt == 0 && ){
		HP(P) 
	}
	if(P == 'B' && rslt == -1){
		//Block attacked by flank
		HP(P) -= 1 * STR(E);
	}
	
}