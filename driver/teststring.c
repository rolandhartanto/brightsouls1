#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include <ctype.h>

boolean IsKataSama(char * kata1, char * kata2){
    int i=0;
    boolean found=true;
    if(strlen(kata1)==strlen(kata2)){
        while((i<strlen(kata1))&&(found)){
            if(kata1[i]==kata2[i]){
                i++;
            }else{
                return(false);
            }
        }
        if(i==strlen(kata1)){
            return(true);
        }
    }else{
        return(false);
    }
}

int main(){
	char kata[10],kata1[10];
	printf("masukkan kata\n");
	scanf("%s",kata);
	int i;
	//kata1=toupper(kata);
	for(i=0;i<strlen(kata);i++){
		kata1[i]=toupper(kata[i]);
	}
	printf("hasil: %s\n",kata1);
    printf("panjang input adalah : %d\n",strlen(kata));
    printf("panjang input1 adalah : %d\n",strlen(kata1));
	if(IsKataSama(kata1,"D")){
		printf("benar\n");
	}else{
		printf("salah\n");
	}
	return 0;
}