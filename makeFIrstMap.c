#include <stdio.h>
#include "listlinier.h"
#include "mesintoken.h"




int main(){
	List L;
	BuildListFromFile(&L);
	PrintInfo(L);
	return 0;
}
