/* File : driverListCircular.h */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 16 November 2021*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listCircular.h"

int main(){
    /*Kamus main*/
    List A;
    address P,Q,R;
    infotype Y;

    /*Algoritma*/
    CreateList(&A);
    if(ListEmpty(A)){
        printf("List kosong\n");
    }
    else{
        printf("List tidak kosong\n");
    }
    printf("\n");

    R=Alokasi(1);
    InsertFirst(&A,R);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    Q=Alokasi(2);
    InsertFirst(&A,Q);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("Alamat first = %x\n",First(A));
    printf("Alamat setelah last = %x\n",next(R));
    printf("\n");

    P=Alokasi(5);
    InsertAfter(&A,P,Q);
    printf("=====Insert After=====\n");
    PrintInfo(A);
    printf("\n");

    Q=Alokasi(3);
    InsertLast(&A,Q);
    printf("=====Insert Last=====\n");
    PrintInfo(A);
    printf("Alamat first = %x\n",First(A));
    printf("Alamat setelah last = %x\n",next(Q));
    printf("\n");

    DelFirst(&A,&P);
    printf("=====Del First=====\n");
    PrintInfo(A);
    printf("P=%d\n",info(P));
    printf("Alamat first = %x\n",First(A));
    printf("Alamat setelah last = %x\n",next(Q));
    printf("\n");

    DelFirst(&A,&P);
    printf("=====Del First=====\n");
    PrintInfo(A);
    printf("\n");

    DelFirst(&A,&P);
    printf("=====Del First=====\n");
    PrintInfo(A);
    printf("\n");

    DelFirst(&A,&P);
    printf("=====Del First=====\n");
    PrintInfo(A);
    printf("\n");

    R=Alokasi(1);
    InsertFirst(&A,R);
    Q=Alokasi(2);
    InsertFirst(&A,Q);
    R=Alokasi(3);
    InsertFirst(&A,R);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    DelLast(&A,&P);
    printf("=====Del Last=====\n");
    PrintInfo(A);
    printf("Alamat first = %x\n",First(A));
    printf("Alamat setelah last = %x\n",next(Q));
    printf("\n");

    DelLast(&A,&P);
    printf("=====Del Last=====\n");
    PrintInfo(A);
    printf("\n");

    DelLast(&A,&P);
    printf("=====Del Last=====\n");
    PrintInfo(A);
    printf("\n");

    R=Alokasi(1);
    InsertFirst(&A,R);
    Q=Alokasi(2);
    InsertFirst(&A,Q);
    P=Alokasi(3);
    InsertFirst(&A,P);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    DelAfter(&A,&P,First(A));
    printf("=====Del After=====\n");
    PrintInfo(A);
    printf("\n");

    InsVFirst(&A,5);
    printf("=====Ins V First=====\n");
    PrintInfo(A);
    printf("\n");

    InsVLast(&A,3);
    printf("=====Ins V Last=====\n");
    PrintInfo(A);
    printf("\n");

    InsVAfter(&A,4);
    printf("=====Ins V After=====\n");
    PrintInfo(A);
    printf("\n");

    DelVFirst(&A,&Y);
    printf("=====Del V First=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVLast(&A,&Y);
    printf("=====Del V Last=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVAfter(&A,&Y);
    printf("=====Del V After=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    printf("jumlah elemen list = %d\n", NbElmt(A));
    printf("\n");

    return 0;
}
