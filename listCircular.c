/* File : listCircular.c */
/* ADT list Circular dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 16 November 2021*/

#include <stdio.h>
#include <stdlib.h>
#include "listCircular.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */
    /*Kamus lokal*/

    /*Algoritma*/
    return First(L)==Nil;
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L){
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
    /*Kamus lokal*/

    /*Algoritma*/
    First(*L)=Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil )
    {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
    /*Kamus lokal*/

    /*Algoritma*/
    info(*P)=0;
    next(*P)=Nil;
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P){
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
    /*Kamus lokal*/
    address last;

    /*Algoritma*/
    if(ListEmpty(*L)){
        First(*L)=P;
        next(P)=First(*L);
    }
    else{
        last=First(*L);
        while(next(last)!=First(*L)){
            last=next(last);
        }
        next(P)=First(*L);
        First(*L)=P;
        next(last)=P;
    }
}

void InsertAfter (List *L, address P, address Prec){
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
    /*Kamus lokal*/

    /*Algoritma*/
    next(P)=next(Prec);
    next(Prec)=P;
}

void InsertLast (List *L, address P){
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
    /*Kamus lokal*/
    address last;

    /*Algroitma*/
    if(First(*L)==Nil){
        InsertFirst(&(*L),P);
    }
    else{
        last=First(*L);
        while(next(last)!=First(*L)){
            last=next(last);
        }
        InsertAfter(&(*L),P,last);
    }
}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
    /*Kamus lokal*/
    address last;

    /*Algoritma*/
    last=First(*L);
    while(next(last)!=First(*L)){
        last=next(last);
    }
    *P=First(*L);
    if(First(*L)==next(First(*L))){
        First(*L)=Nil;
    }
    else{
        First(*L)=next(First(*L));
        next(last)=First(*L);
    }
    next(*P)=Nil;
}

void DelLast (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
    /*kamus lokal*/
    address last, precLast;

    /*Algoritma*/
    last=First(*L);
    precLast=Nil;
    while(next(last)!=First(*L)){
        precLast=last;
        last=next(last);
    }
    *P=last;
    if(last==First(*L)){
        First(*L)=Nil;
    }
    else{
        next(precLast)=First(*L);
    }
    next(*P)=Nil;
}

void DelAfter (List *L, address * Pdel, address Prec){
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/
    /*Kamus lokal*/

    /*Algoritma*/
    *Pdel=next(Prec);
    next(Prec)=next(next(Prec));
    next(*Pdel)=Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X){
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        InsertFirst(&(*L),P);
    }
}

void InsVLast (List *L, infotype X){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        InsertLast(&(*L),P);
    }
}

void InsVAfter (List *L, infotype X){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
    /*Kamus lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    if(!ListEmpty(*L)){
        AdrLast(&(*L),&Prec,&Last);
        P=Alokasi(X);
        if(P!=Nil){
            InsertAfter(&(*L),P,Prec);
        }
    }
    else{
        InsVFirst(&(*L),X);
    }
}

void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/
    /*Kamus lokal*/

    /*Algoritma*/
    *Last=First(*L);
    *Prec=Nil;
    while(next(*Last)!=First(*L)){
        *Prec=*Last;
        *Last=next(*Last);
    }
}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    *X=info(First(*L));
    DelFirst(&(*L),&P);
    Dealokasi(&P);
}


void DelVLast (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */
    /*Kamus  lokal*/
    address P;

    /*Algoritma*/
    DelLast(&(*L),&P);
    *X=info(P);
    Dealokasi(&P);
}

void DelVAfter (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
    /*Kamus lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    AdrLast(&(*L),&Prec,&Last);
    DelAfter(&(*L),&P,Prec);
    *X=info(P);
    Dealokasi(&P);
}

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L){
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    if(ListEmpty(L)){
        printf("list kosong\n");
    }
    else{
        P=First(L);
        while(next(P)!=First(L)){
            printf("%d ", info(P));
            P=next(P);
        }
        printf("%d ", info(P));
        printf("\n");
    }
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /*Kamus lokal*/
    address P;
    int num;

    /*Algoritma*/
    if(ListEmpty(L)){
        return 0;
    }
    else{
        num = 1;
        P = First(L);
        while(next(P)!=First(L)){
            num++;
            P = next(P);
        }
        return num;
    }
}


