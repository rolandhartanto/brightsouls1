/* File: point.c */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "boolean.h"
#include <stdio.h>
#include <math.h>

typedef struct {
	float X; /* absis   */
	float Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;
    Absis(P) = X;
    Ordinat(P)= Y;
    return P;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    float x,y;
    scanf("%f",&x);
    scanf("%f",&y);

    *P = MakePOINT(x,y);

    //return 0 ;

}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
{
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return (Absis(P1)==Absis(P2)&& Ordinat(P1)==Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return (!(Absis(P1)==Absis(P2)&& Ordinat(P1)==Ordinat(P2)));
}


/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return (Absis(P)==0 && Ordinat(P)==0);
}


boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return (Ordinat(P)==0);
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return (Absis(P)==0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    float x = Absis(P);
    float y = Ordinat(P);
    int kuad;
    if(x>0&&y>0)
    {
        kuad = 1;
    }
    else if(x<0&&y>0)
    {
        kuad = 2;
    }
    else if(x<0&&y<0)
    {
        kuad = 3;
    }
    else if(x>0&&y<0)
    {
        kuad = 4;
    }

    return kuad;
}



/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
    Absis(P) = Absis(P)+1.0;
    return P;
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    Ordinat(P) = Ordinat(P)+1.0;
    return P;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    Absis(P) = Absis(P)+deltaX;
    Ordinat(P) = Ordinat(P)+deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    if (SbX == false){
    Absis(P) = Absis(P)* -1.0;
    }
    else{
    Ordinat(P) = Ordinat(P)*-1.0;
    }

    return P;
}

float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    float jrk;
    float x,y;
    x = Absis(P);
    y = Ordinat(P);
    jrk = sqrt((x*x)+(y*y));

    return jrk;
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
    float x1,x2,y1,y2,dx,dy,jrk;
    x1 = Absis(P1);
    y1 = Ordinat(P1);
    x2 = Absis(P2);
    y2 = Ordinat(P2);
    dx = x2-x1;
    dy = y2-y1;

    jrk = sqrt((dx*dx)+(dy*dy));
    return jrk;
}


void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    float x,y;

    x = Absis(*P)+deltaX;
    y = Ordinat(*P)+deltaY;

    *P = MakePOINT(x,y);
}

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{

    float x,y;

    x = Absis(*P);
    //y = Ordinat(*P)+deltaY;

    *P = MakePOINT(x,0);

}

void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    float x,y;

    //x = Absis(*P)+deltaX;
    y = Ordinat(*P);

    *P = MakePOINT(0,y);
}

void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    float x,y;

    if (SbX == false){
    x = Absis(*P)* -1.0;
    y = Ordinat(*P);
    }
    else{
    x = Absis(*P);
    y = Ordinat(*P)*-1.0;
    }

    *P = MakePOINT(x,y);
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    float x,y,xa,ya,degre;
    const float phiiii = acos(-1);
    xa = Absis(*P);
    ya = Ordinat(*P);
    degre = -1 * (Sudut / 360.0) * 2* phiiii;
    x = xa * cos(degre) - ya * sin(degre);
    y = xa * sin(degre) + ya * cos(degre);

    *P = MakePOINT(x,y);
}


/*
    (\__(\
    (  ._.)
    o(")=(")



*/
