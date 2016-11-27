#include <stdio.h>
#include "listlinier.h"
#include "mesintoken.h"

void BuildListFromFile(List *L){
	int i=0; char tkn;
	infotype info,val;
	CreateEmpty(L);
	STARTTOKENMAP();
	if(EndToken){
		CreateEmpty(L);
	}else{
		while(!EndToken){
			val=CToken.val;
			InsVLast(L,val);
			ADVTOKEN();
		}
	}
}


int main(){
	List L;
	BuildListFromFile(&L);
	PrintInfo(L);
	return 0;
}