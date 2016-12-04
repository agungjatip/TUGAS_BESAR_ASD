#include "dosen.h"

void CreateList(List_dosen &L){
    First (L)=NULL;
    Last (L)=NULL;
}
void InsertFirst(List_dosen &L, address_dosen P){
    if(First(L)==NULL)
    {
        First(L)=P;
        Last(L)=P;
    }
    else
    {
        next(P)=First(L);
        prev(First(L))=P;
        First(L)=P;
    }
}
void InsertAfter(List_dosen &L, address_dosen Prec, address_dosen P){
    if (First (L)!=NULL)
        {
            prev(P)=Prec;
            next(P)=(next(Prec));
            next(Prec)=P;
            prev(next(P))=P;
        }
}
void InsertLast(List_dosen &L, address_dosen P){
    if(First(L)!=NULL)
        {
            First(L)=P;
            Last(L)=P;
        }
        else
        {
            prev(P)=Last(L);
            next(Last(L))=P;
            Last(L)=P;
        }
    }
void DeleteFirst(List_dosen &L, address_dosen &P){
    P=First(L);
    if(next(First(L))==NULL)
    {
    First(L)= NULL;
    }
    else
    {
        First(L)=next(P);
        next(P)=NULL;
        prev(First(L))=NULL;
    }
}
void DeleteLast(List_dosen &L, address_dosen &P){
    if(First(L)!=NULL)
    {
    P=Last(L);
    Last(L)=prev(P);
    prev(P)=NULL;
    next(Last(L))=NULL;
    }

}
void DeleteAfter(List_dosen &L,address_dosen Prec, address_dosen &P){
    if(First(L)!=NULL)
    {
    P=next(Prec);
    next(Prec)=(next(P));
    prev(next(P))=(Prec);
    prev(P)=NULL;
    next(P)=NULL;
    }
}
address_dosen FindElm(List_dosen L, int id){
if(First(L) != NULL)
    {
        address_dosen P = First(L);
        while (P != NULL)
        {
            if(((info(P).id == id)))
            {
                return P;
            }
            else P=next(P);
        }
    }
    return NULL;
}

void PrintInfo(List_dosen L){
    if(First(L) != NULL)
    {
        address_dosen P = First(L);
        while (P != NULL)
        {
            cout<<"ID Jurusan : "<<info(P).id;
            cout<<"Nama Jurusan : "<<info(P).nama_jurusan;
            cout<<"Fakultas : "<<info(P).fakultas;
            cout<<"Alamat : "<<info(P).alamat;
            cout<<"Tipe : "<<info(P).tipe;
            P=next(P);
        }
    }
}

address_dosen Alokasi (infotype_dosen x){
    address_dosen P;
    P=new elmlist_dosen;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
