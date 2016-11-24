#include <stdio.h>
#include "mesintoken.h"

int main(){
	STARTTOKEN();
	if(EndToken){
		printf("ekspresi kosong\n");
	}else{
		while(!EndToken){
			if(CToken.ID=='b'){
				printf("%d\n",CToken.val);
			}else{
				printf("%c\n",CToken.ID);
			}
		ADVTOKEN();
		}
			
	}
	return 0;
}
