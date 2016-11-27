
/*ADT GUI*/
#include "ADTgui.h"
#include "scene.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "color.h"
#include <ctype.h>
//#include<windows.h>

//#define clear() printf("\033[2J")
//#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

//extern Player P;

#ifdef _WIN32

    #include <windows.h>
    void ClearScreen()
    {
        system("cls");
    }

    void delay(int x)
    {
       int c = 1, d = 1;

       for ( c = 1 ; c <= x*10 ; c++ )
           for ( d = 1 ; d <= x*10 ; d++ )
           {}
    }



#elif __linux__
    #include <unistd.h>
    void ClearScreen()
    {
        system("clear");
    }
    void delay(int x)
    {
        usleep(x*1000);
        fflush(stdout);
    }

#endif



void Back()
{
	char x;
	do{
		printf("\t\t\tINPUT : ");
		scanf(" %c",&x);
    x = toupper(x);
		if(x!='B'){
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"           ___             |   |                   |        "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"          |   \\            |   |    __             | __     "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"          |   /   __ o  __ |_--|-- /  \\  __        |/  \\    "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"          |---  |/   | /  ||  \\|   \\__  /  \\ |    ||\\__     "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"        A |   \\ |    ||   ||  ||      \\|    ||    ||   \\    "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"       <[>|___/ |    | \\__||  |\\__/\\__/ \\__/  \\__/ |\\__/    "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"        [             \\___|                                 "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"  /\\    [****\\\\\\\\\\*************************>>               "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset" <*******[000000000000***********************>>             "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"  \\/    [****/////*************************>>               "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"        [                                                   "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"       <[>                                                  "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"        V                                                   "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                         (B) Back                           "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
      printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
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
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"           ___             |   |                   |        "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"          |   \\            |   |    __             | __     "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"          |   /   __ o  __ |_--|-- /  \\  __        |/  \\    "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"          |---  |/   | /  ||  \\|   \\__  /  \\ |    ||\\__     "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"        A |   \\ |    ||   ||  ||      \\|    ||    ||   \\    "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"       <[>|___/ |    | \\__||  |\\__/\\__/ \\__/  \\__/ |\\__/    "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"        [             \\___|                                 "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"  /\\    [****\\\\\\\\\\*************************>>               "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset" <*******[000000000000***********************>>             "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"  \\/    [****/////*************************>>               "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"        [                                                   "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"       <[>                                                  "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"        V                                                   "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                      (N)NEW GAME                           "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                      (S)START GAME                         "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                      (H)HELP                               "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                      (E)EXIT                               "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
	//printf("                           INPUT : ");
	//	printf("%c==================================================================%c\n",200,188);

	//pilihOpsi(a);

}

void pilihOpsi(char a[],int *b,int *s)
{
	char x;

	do{
		printf("\t\t\tINPUT : ");
		scanf(" %c",&x);
    x = toupper(x);
		switch (x){
			case 'N' : NewGame(a); break;
			case 'S' : printStartGame(a,s); break;
			//case 'L' : loadingBar(); break;//buat sementara blm ada
			case 'H' : printHelp(); break;//buat sementara blm ada
			case 'E' : *b=0; break;
			default : printf("\t\t\tInvalid input!\n");
		}

	}while(((x!='N')&&(x!='S')&&(x!='L')&&(x!='H')&&(x!='E'))&&(b!=0));

}

void NewGame(char a[])
/*I.S. sembarang
  F.S. menampilkan kotak pengisian nama pemain pada saat pilihan menu New Game dipilih
*/
{

	printf("\t\t\tINSERT YOUR NAME : ");
  do{
	   scanf("%s",a);
  }while(strlen(a)>=12);

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
  ClearScreen();
	if(strlen(a)==0){
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"           ___             |   |                   |        "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"          |   \\            |   |    __             | __     "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"          |   /   __ o  __ |_--|-- /  \\  __        |/  \\    "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"          |---  |/   | /  ||  \\|   \\__  /  \\ |    ||\\__     "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        A |   \\ |    ||   ||  ||      \\|    ||    ||   \\    "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"       <[>|___/ |    | \\__||  |\\__/\\__/ \\__/  \\__/ |\\__/    "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        [             \\___|                                 "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"  /\\    [****\\\\\\\\\\*************************>>               "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset" <*******[000000000000***********************>>             "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"  \\/    [****/////*************************>>               "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        [                                                   "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"       <[>                                                  "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        V                                                   "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        No profile existed please create a new profile      "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                         (B) Back                           "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
		Back();
	}else{
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"           ___             |   |                   |        "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"          |   \\            |   |    __             | __     "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"          |   /   __ o  __ |_--|-- /  \\  __        |/  \\    "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"          |---  |/   | /  ||  \\|   \\__  /  \\ |    ||\\__     "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        A |   \\ |    ||   ||  ||      \\|    ||    ||   \\    "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"       <[>|___/ |    | \\__||  |\\__/\\__/ \\__/  \\__/ |\\__/    "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        [             \\___|                                 "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"  /\\    [****\\\\\\\\\\*************************>>               "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset" <*******[000000000000***********************>>             "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"  \\/    [****/////*************************>>               "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        [                                                   "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"       <[>                                                  "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"        V                                                   "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                   "bold"Have Fun In The Dungeon~"bold"                 "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");
    printf(blbox"****"col_reset"                                                            "blbox"****"col_reset"\n");

		*s = 1;
		delay(1000);
        //Overworld();
	}

}
void loadingBar()
/*I.S. sembarang
  F.S. menampilkan loading bar sebelum main menu
  tidak penting, HANYA OPTIONAL!!
*/
{
	ClearScreen();
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("----------------------------------------------------------- "bold"[LOADING]"col_reset"\n");
	for(int i=1;i<=10;i++){
		printf(blbox">"col_reset);
		fflush(stdout);
		usleep(18000);
	}
	for(int i=1;i<=20;i++){
		printf(blbox">"col_reset);
		fflush(stdout);
		usleep(10000);
	}
	for(int i=1;i<=10;i++){
		printf(blbox">"col_reset);
		fflush(stdout);
		usleep(15000);
	}
	for(int i=1;i<=10;i++){
		printf(blbox">"col_reset);
		fflush(stdout);
		usleep(6000);
	}
	for(int i=1;i<=10;i++){
		printf(blbox">"col_reset);
		fflush(stdout);
		usleep(4000);
	}
	printf("\n");
}
void printGUIInGame(char nm[], int lvl, int hp, int str, int def, int exp)
/*I.S. sembarang
  F.S. menampilkan tabel dan peta setelah start game
*/
{
	char x;
	ClearScreen();
}
void printExit(int *b)
/*I.S. sembarang
  F.S. menampilkan "are you sure? Yes No" saat menu exit dipilih
*/
{
	char x;
	printf("\t\tare you sure? Y/N ");

	do{
		scanf(" %c",&x);
		if(x=='Y'){
			printf("\t\tGood bye!\n");
			*b = 0;
		}else if(x=='N'){
			*b = 1;
		}else{
			printf("\t\tInvalid input!\n");
		}
	}while((x!='Y')&&(x!='N'));
}

void printHelp()
{
  ClearScreen();
	printf("\t\t+-------------------------------+\n");
	printf("\t\t|                               |\n");
	printf("\t\t| +Welcome to Brightsouls v1.0+ |\n");
	printf("\t\t| +Game control :               |\n");
	printf("\t\t|   - 'GU' - go up              |\n");
	printf("\t\t|   - 'GD' - go down            |\n");
	printf("\t\t|   - 'GL' - go left            |\n");
	printf("\t\t|   - 'GR' - go right           |\n");
	printf("\t\t|                               |\n");
	printf("\t\t| +Battle guide :               |\n");
	printf("\t\t|   - 'A' - Attack              |\n");
	printf("\t\t|   - 'B' - Block               |\n");
	printf("\t\t|   - 'F' - Flank               |\n");
	printf("\t\t|                               |\n");
	printf("\t\t| +The Cycle                    |\n");
	printf("\t\t|  (A defeats F, F defeats B,   |\n");
	printf("\t\t|  B defeats A)                 |\n");
	printf("\t\t|                               |\n");
	printf("\t\t|         A -------> F          |\n");
	printf("\t\t|         ^          |          |\n");
	printf("\t\t|         |          |          |\n");
	printf("\t\t|         |          |          |\n");
	printf("\t\t|         +---- B <--+          |\n");
	printf("\t\t|                               |\n");
	printf("\t\t+-------------------------------+\n");
	printf("\t\t ~ Press B to back to Main Menu ~\n");
	Back();
}


void PrintHeader(char * Nama, int HP, int STR, int DEF, int Level, int EXP, int Next ){
    printf(    "_________________________________________________________________________________________________\n\n");
    printf(    "\n\t\t\t\t\t\t\x1b[1m-%s-\x1b[0m\n\n",Nama);
    printf(    "_________________________________________________________________________________________________\n\n");
    printf(    " | HP : %d\t| STR : %d\t| DEF : %d\t| Lv : %d\t| EXP : %d\t| Next : %d\t|\n",HP,STR,DEF,Level,EXP,Next);
    printf(    "_________________________________________________________________________________________________\n\n");
}


void PrintHeaderE(int HP, int STR, int DEF){
    printf(    "_________________________________________________________________________________________________\n\n");
    printf(    "|\t Enemy \t\t| \tHP : %d\t\t| \tSTR : %d\t| \tDEF : %d\t|\n",HP,STR,DEF);
    printf(    "_________________________________________________________________________________________________\n\n");
}

void printGameOver(){
  printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****         ___   ___   _  _  ___      __       ___ __         ****\n");
	printf("****        /   \\ /   \\ / \\/ \\|        /  \\ |  ||   |  \\        ****\n");
	printf("****       | ___  |___||  |  ||___    |    ||  ||___|__/        ****\n");
	printf("****       |    | |   ||  |  ||       |    ||  ||   |  \\        ****\n");
	printf("****        \\___/ |   ||  |  ||___     \\__/  \\/ |___|  |        ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
}

void printCredits(){
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                          "underlineb"CREDITS"col_reset"                           ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                  Vincent Hendryanto Halim                  ****\n");
	printf("****                                                            ****\n");
	printf("****                       Roland Hartanto                      ****\n");
	printf("****                                                            ****\n");
	printf("****                        Dicky Novanto                       ****\n");
	printf("****                                                            ****\n");
	printf("****                       Alif Ijlal Wafi                      ****\n");
	printf("****                                                            ****\n");
	printf("****              Daniel Christian Pradipta Basoeki             ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");

}

void printWin(){
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                      _____                                 ****\n");
  printf("****            \\\\   //  //    \\\\   ||    ||                    ****\n");
  printf("****             \\\\ //  ||      ||  ||    ||                    ****\n");
  printf("****              |||   ||      ||  ||    ||                    ****\n");
  printf("****              |||    \\\\____//    \\\\__//                     ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                 \\    / /\\    / / ======  ||\\   |        ****\n");
  printf("****                  \\  / /  \\  / /    ||    || \\  |        ****\n");
  printf("****                   \\/ /    \\/ /     ||    ||  \\ |        ****\n");
  printf("****                    \\/      \\/    ======  ||   \\|        ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
  printf("****                                                            ****\n");
}
