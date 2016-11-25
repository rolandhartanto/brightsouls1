/*ADT GUI*/
#ifndef ADTgui_H
#define ADTgui_H



void delay();
void ClearScreen();
void Back();

void printMainMenu();
/*I.S. sembarang
  F.S. menampilkan main menu pada saat program dijalankan
*/

void pilihOpsi(char a[],int *b,int *s);
/* untuk memilih opsi
*/

void NewGame(char a[]);
/*I.S. sembarang
  F.S. menampilkan kotak pengisian nama pemain pada saat pilihan menu New Game dipilih
*/

void printStartGame(char a[], int *s);
/*I.S. sembarang
  F.S. menampilkan cerita awal jika pemain sudah memasukkan nama pemain,
  jika belum ada nama pemain, tampilkan "nama pemain belum dimasukkan!" dan kembali ke
  tampilan main menu
*/

void loadingBar();
/*I.S. sembarang
  F.S. menampilkan loading bar sebelum main menu
  tidak penting, HANYA OPTIONAL!!
*/

void printGUIInGame(char nm[], int lvl, int hp, int str, int def, int exp);
/*I.S. sembarang
  F.S. menampilkan tabel dan peta setelah start game
*/

void printExit(int *b);
/*I.S. sembarang
  F.S. menampilkan "are you sure? Yes No" saat menu exit dipilih
*/

void printHelp();
/* untuk menampilkan panduan bermain
*/
#endif
