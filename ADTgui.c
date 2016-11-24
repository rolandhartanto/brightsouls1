/*ADT GUI*/
#include "ADTgui.h"
#include "scene.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<windows.h>

//#define clear() printf("\033[2J")
//#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

#ifdef _WIN32

    #include <windows.h>
    void ClearScreen()
    {
        system("cls");
    }



#elif __linux__
    #include <unistd.h>
    void ClearScreen()
    {
        system("clear");
    }

#endif

void delay(int x)
{
   int c = 1, d = 1;

   for ( c = 1 ; c <= x*10 ; c++ )
       for ( d = 1 ; d <= x*10 ; d++ )
       {}


}

void Back()
{
	char x;
	do{
		scanf(" %c",&x);
		if(x!='B'){
			printf("Ketik 'B' untuk kembali ke menu utama\n");
		}
	}while(x!='B');
}
void printMainMenu()
/*I.S. sembarang
  F.S. menampilkan main menu pada saat program dijalankan
*/
{

	ClearScreen();
	//printf("%c==================================================================%c\n",201,187);
	printf("%c%c%c%c           ___             |   |                    |       %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c          |   \\            |   |     __             | __    %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c          |   /   __ o  __ |_--|--  /  \\  __        |/  \\   %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c          |---  |/   | /  ||  \\|    \\__  /  \\ |    ||\\__    %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c        A |   \\ |    ||   ||  ||       \\|    ||    ||   \\   %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c       <%c>|___/ |    | \\__||  |\\__/\\__/ \\__/  \\__/ |\\__/   %c%c%c%c\n",186,176,176,176,186,176,176,176,186);
	printf("%c%c%c%c        %c             \\___|                                 %c%c%c%c\n",186,176,176,176,186,176,176,176,186);
	printf("%c%c%c%c  /\\    %c%c%c%c%c\\\\\\\\\\%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c>>                    %c%c%c%c\n",186,176,176,176,186,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,176,176,176,186);
	printf("%c%c%c%c %c%c%c%c%c%c%c%c%c~OOOOOOOOOOO%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c>>                  %c%c%c%c\n",186,176,176,176,174,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,176,176,176,186);
	printf("%c%c%c%c  \\/    %c%c%c%c%c/////%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c>>                    %c%c%c%c\n",186,176,176,176,186,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,176,176,176,186);
	printf("%c%c%c%c        %c                                                   %c%c%c%c\n",186,176,176,176,186,176,176,176,186);
	printf("%c%c%c%c       <%c>                                                  %c%c%c%c\n",186,176,176,176,186,176,176,176,186);
	printf("%c%c%c%c        V                                                   %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                     %c(N)NEW GAME                           %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                                                            %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                     %c(S)START GAME                         %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                                                            %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                     %c(L)LOAD GAME                          %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                                                            %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                     %c(H)? HELP ?                           %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                                                            %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                     %c(E)EXIT                               %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                                                            %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("%c%c%c%c                                                            %c%c%c%c\n",186,176,176,176,176,176,176,186);
	printf("                           INPUT : ");
	//	printf("%c==================================================================%c\n",200,188);

	//pilihOpsi(a);

}

void pilihOpsi(char a[],int *b,int *s)
{
	char x;

	do{
		scanf(" %c",&x);
		switch (x){
			case 'N' : NewGame(a); break;
			case 'S' : printStartGame(a,s); break;
			case 'L' : loadingBar(); break;//buat sementara blm ada
			case 'H' : printHelp(); break;//buat sementara blm ada
			case 'E' : printExit(b); break;
			default : printf("Invalid input!\n");
		}

	}while(((x!='N')&&(x!='S')&&(x!='L')&&(x!='H')&&(x!='E'))&&(b!=0));

}

void NewGame(char a[])
/*I.S. sembarang
  F.S. menampilkan kotak pengisian nama pemain pada saat pilihan menu New Game dipilih
*/
{

	printf("                INSERT YOUR NAME : ");
	scanf("%s",a);

	printf("Tekan 'B' untuk kembali ke menu utama");
	Back();
	/*printf("                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                          INSERT YOUR NAME                            \n"
		   "                                                                      \n"
		   "                        ");
	*/
		   /*13*29*/

}
void printStartGame(char a[],int *s)
/*I.S. sembarang
  F.S. menampilkan cerita awal jika pemain sudah memasukkan nama pemain,
  jika belum ada nama pemain, tampilkan "nama pemain belum dimasukkan!" dan kembali ke
  tampilan main menu
*/
{

	if(strlen(a)==0){
		printf("> Pemain belum ada! Input nama terlebih dahulu dengan memilih menu New Game(N)!\n");
		printf("> (B)Back\n");
		Back();
	}else{
		printf("Selamat bermain %s!\n",a);
		*s = 1;
        Overworld();
	}

}
void loadingBar()
/*I.S. sembarang
  F.S. menampilkan loading bar sebelum main menu
  tidak penting, HANYA OPTIONAL!!
*/
{
	ClearScreen();
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  LOADING\n");
	for(int i=1;i<=10;i++){
		printf("%c",176);
		delay(1000);
	}
	for(int i=1;i<=20;i++){
		printf("%c",176);
		delay(500);
	}
	for(int i=1;i<=10;i++){
		printf("%c",176);
		delay(800);
	}
	for(int i=1;i<=10;i++){
		printf("%c",176);
		delay(350);
	}
	for(int i=1;i<=10;i++){
		printf("%c",176);
		delay(200);
	}
}
void printGUIInGame(char nm[], int lvl, int hp, int str, int def, int exp)
/*I.S. sembarang
  F.S. menampilkan tabel dan peta setelah start game
*/
{
	char x;
	ClearScreen();
	/*printf("|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
	");*/
	printf(" %s / LVL : %d / HP : %d / STR : %d / DEF : %d / EXP : %d \n",nm,lvl,hp,str,def,exp);
	printf("Command : ");
	scanf(" %c",&x);
	printf("\n");
}
void printExit(int *b)
/*I.S. sembarang
  F.S. menampilkan "are you sure? Yes No" saat menu exit dipilih
*/
{
	char x;
	printf("are you sure? Y/N ");

	do{
		scanf(" %c",&x);
		if(x=='Y'){
			printf("Good bye!\n");
			*b = 0;
		}else if(x=='N'){
			*b = 1;
		}else{
			printf("Invalid input!\n");
		}
	}while((x!='Y')&&(x!='N'));
}

void printHelp()
{

}
