/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "boolean.h"
#include <stdio.h>

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
typedef int ElType;

typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
    ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    (*M).NBrsEff = NB;
    (*M).NKolEff = NK;
}

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return(i>= BrsMin && i<=BrsMax && j>=KolMin && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return(BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return(KolMin);
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return(GetFirstIdxBrs(M)+NBrsEff(M)-1);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return(GetFirstIdxKol(M)+NKolEff(M)-1);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return(i>= GetFirstIdxBrs(M) && i<=GetLastIdxBrs(M) && j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return(Elmt(M,i,i));
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    int i,j;
    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
    for(i =GetFirstIdxBrs(MIn); i<=GetLastIdxBrs(MIn);i++){
        for(j=GetFirstIdxKol(MIn); j<=GetLastIdxKol(MIn);j++){
            Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    MakeMATRIKS(NB,NK,M);
    ElType k;
    int i,j;
    for(i =GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M);i++){
        for(j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M);j++){
            scanf("%d",&k);
            Elmt(*M,i,j)=k;
        }
    }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    int i,j;
    for(i =GetFirstIdxBrs(M); i<GetLastIdxBrs(M);i++){
        for(j=GetFirstIdxKol(M); j<GetLastIdxKol(M); j++){
            printf("%d ",Elmt(M,i,j));
        }
        printf("%d\n",Elmt(M,i,j));
    }
    i = GetLastIdxBrs(M);
    for(j=GetFirstIdxKol(M); j<GetLastIdxKol(M); j++){
            printf("%d ",Elmt(M,i,j));
        }
    printf("%d",Elmt(M,i,j));
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    MATRIKS Hsl;
    int i,j;

    MakeMATRIKS(NBrsEff(M1),NKolEff(M1), &Hsl);

    for(i =GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1);i++){
        for(j=GetFirstIdxKol(M1); j<=GetLastIdxKol(M1);j++){
            Elmt(Hsl,i,j)=Elmt(M1,i,j)+Elmt(M2,i,j);
        }
    }
    return (Hsl);
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    MATRIKS Hsl;
    int i,j;

    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&Hsl);

    for(i =GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1);i++){
        for(j=GetFirstIdxKol(M1); j<=GetLastIdxKol(M1);j++){
            Elmt(Hsl,i,j)=Elmt(M1,i,j)-Elmt(M2,i,j);
        }
    }
    return(Hsl);
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    MATRIKS M3;
    int h,i,j,k;
    ElType l;

    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M3);

    for(h=GetFirstIdxBrs(M1);h<=GetLastIdxBrs(M1);h++){
        for(i=GetFirstIdxKol(M1);i<=GetLastIdxKol(M1);i++){
                l = 0;
                for(k = GetFirstIdxKol(M1); k<=GetLastIdxKol(M1);k++){
                    l += Elmt(M1,h,k) * Elmt(M2,k,i);
                }
                Elmt(M3,h,i) = l;
            }
    }

    return M3;

}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    MATRIKS Hsl;
    int i,j;

    MakeMATRIKS(NBrsEff(M),NKolEff(M),&Hsl);

    for(i =GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
        for(j=GetFirstIdxKol(M); j<=GetLastIdxKol(M);j++){
            Elmt(Hsl,i,j)=Elmt(M,i,j)*X;
        }
    }
    return(Hsl);
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    int i,j;

    for(i = GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M);i++){
        for(j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M);j++){
            Elmt(*M,i,j)=Elmt(*M,i,j)*K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQM (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    boolean same;
    int i,j;
    if (NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2)){
        same = true;
    }
    if (same==true){
        i=GetFirstIdxBrs(M1);
        while(i<=GetLastIdxBrs(M1) && same){
            j=GetFirstIdxKol(M1);
            while(j<=GetLastIdxKol(M1) && same){
                if(Elmt(M1,i,j)!=Elmt(M2,i,j)){
                    same=false;
                }
                j++;
            }
            i++;
        }
    }

    return(same);
}

boolean NEQM (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return(!EQM(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return (NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return(NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return(NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    boolean smtr;
    int i,j;

    smtr=false;
    i=GetFirstIdxBrs(M);
    if(IsBujurSangkar(M)){
        smtr=true;
        while(smtr && i<=GetLastIdxBrs(M)){
            j=GetFirstIdxKol(M);
            while(j<=GetLastIdxKol(M) && smtr){
                if(Elmt(M,i,j)!=Elmt(M,j,i)){
                    smtr=false;
                }
            j++;
            }
        i++;
        }
    }
    return(smtr);
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    int i,j;
    boolean same;
    i = GetFirstIdxBrs(M);
    same = false;
    if (IsBujurSangkar(M)){
        same = true;
        while(i<=GetLastIdxBrs(M) && same ){
            j=GetFirstIdxKol(M);
            while(j<=GetLastIdxKol(M) && same){
                if(i==j){
                    if (Elmt(M,i,j)!=1){
                        same = false;
                    }
                }
                else { //i!=j
                    if (Elmt(M,i,j)!=0){
                        same = false;
                    }
                }
            j++;
            }
        i++;
        }
    }

    return same;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int i,j;
    float f;
    float ct;
    ct = 0;
    for (i = GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
            if(Elmt(M,i,j)!=0){
                ct=ct+1;
            }
        }
    }

    f = ((ct/NBElmt(M))*100.0);
    return (f<=5.0);
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    MATRIKS matr;
    matr = KaliKons(M,-1);
    return matr;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    int i,j,k,l,m,a;
    float det,dtsmt,dettemp;
    MATRIKS sapi;

    if(NBrsEff(M)>2){
        //REKURSIF MEMOTONG MATRIKS SAPI EDISI IDUL ADHA
        det = 0;
        for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
            MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&sapi);
            l = 0;
            a = Elmt(M,GetFirstIdxBrs(M),i);
            for(j=GetFirstIdxBrs(M);j<=GetLastIdxBrs(M);j++){
                if(j!=GetFirstIdxBrs(M)){
                    l++;
                    m = 0;
                    for(k=GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++){
                        if(k!=i){
                            m++;
                            Elmt(sapi,l,m)=Elmt(M,j,k);
                        }
                    }
                }
            }
            dettemp = a * Determinan(sapi);

            if(i%2 == 0){
                det-=dettemp;
            }
            else{
                det+=dettemp;
            }
        }
    }
    else{ //NBrsEff(M)=2)
    //BASIS
        i = GetFirstIdxBrs(M);
        j = GetFirstIdxKol(M);
        k = GetLastIdxBrs(M);
        l = GetLastIdxKol(M);
        det = (Elmt(M,i,j) * Elmt(M,k,l))-(Elmt(M,i,l) * Elmt(M,k,j));
    }

    return det;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    PKaliKons(M,-1);
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    int i,j;
    MATRIKS Mhsl;
    CopyMATRIKS(*M, &Mhsl);
    for(i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M);i++){
        for(j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M);j++){
            Elmt(*M,i,j)=Elmt(Mhsl,j,i);
        }
    }
}
