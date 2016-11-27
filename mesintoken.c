
/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */

#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
Token CToken;


void IgnoreBlankTOKEN(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
	while((CC==BLANK)&&(CC!=MARK)){
		ADV();
	}
}
void STARTTOKEN(){
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
	STARTTREE();
	IgnoreBlankTOKEN();
	if(CC==MARK){
		EndToken=true;
	}else{
		EndToken=false;
		SalinToken();
	}
}
void ADVTOKEN(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	IgnoreBlankTOKEN();
	if(CC==MARK){
		EndToken=true;
	}else{
		SalinToken();
		IgnoreBlankTOKEN();
	}
}
void SalinToken(){
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	int bil=0,countAngka=0;
	while((CC!=MARK)&&(CC!=BLANK)){
		if(((CC-'0')>=0)&&((CC-'0')<=9)){
			CToken.ID='b';
			if(countAngka==0){
				bil+=CC-'0';
				countAngka++;
			}else{
				bil=bil*10+(CC-'0');
			}
			CToken.val=bil;
		}else{
			CToken.ID=CC;
			CToken.val=-1;
		}
		ADV();
	}
}
