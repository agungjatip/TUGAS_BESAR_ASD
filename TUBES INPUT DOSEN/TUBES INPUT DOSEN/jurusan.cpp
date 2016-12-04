#include "jurusan.h"
void CreateList(List_jurusan &L)
{
    First (L)=NULL;
}
void InsertFirst(List_jurusan &L, address_jurusan P)
{
    if(First(L)==NULL)
    {
        First(L)=P;
    }
    else
    {
        next(P)=First(L);
        First(L)=P;
    }
}
void InsertAfter(List_jurusan &L, address_jurusan Prec, address_jurusan P)
{
    if (Prec!=NULL)
    {
        next (P)=next(Prec);
        next (Prec)=P;
    }
}
void InsertLast(List_jurusan &L, address_jurusan P)
{
    if (First(L) != NULL)
    {
        address_jurusan Q;
        Q=First(L);
        while(next(Q)!=NULL)
        {
            Q=next(P);

        }
        next(Q)=P;
    }
    else
        First(L)=P;
}
void DeleteFirst(List_jurusan &L, address_jurusan &P)
{
    if (First(L)!=NULL)
    {
        P=First (L);
        First(L)=next(P);
        next(P)=NULL;
    }
}
void DeleteLast(List_jurusan &L, address_jurusan &P)
{
    address_jurusan Q;
    Q=First(L);
    if (Q!=NULL)
    {
        while (next(next(Q))!=NULL)
        {
            Q=next(Q);
        }
        P=next(Q);
        next(Q)=NULL;
    }
}
void DeleteAfter(List_jurusan &L, address_jurusan Prec, address_jurusan &P)
{
    if(First(L)!=NULL)
    {
        P=next(Prec);
        next(Prec)=next(P);
        next(P)=NULL;
    }
}
address_jurusan FindElm(List_jurusan L, string tip, string namjur)
{
    if(First(L) != NULL)
    {
        address_jurusan P = First(L);
        while (P != NULL)
        {
            if((info(P).tipe == tip) && (info(P).nama_jurusan == namjur))
            {
                return P;
            }
            else P=next(P);
        }
    }
    return NULL;
}
void PrintInfo(List_jurusan L)
{
    if(First(L) != NULL)
    {
        address_jurusan P = First(L);
        while (P != NULL)
        {
            cout<<"ID Jurusan   : "<<info(P).id<<endl;
            cout<<"Nama Jurusan : "<<info(P).nama_jurusan<<endl;
            cout<<"Fakultas     : "<<info(P).fakultas<<endl;
            cout<<"Kapasitas    : "<<info(P).kapasitas<<endl;
            cout<<"Alamat       : "<<info(P).alamat<<endl;
            cout<<"Tipe         : "<<info(P).tipe<<endl;
            P=next(P);
        }
    }
}
address_jurusan Alokasi (infotype_jurusan x)
{
    address_jurusan P;
    P=new elmlist_jurusan;
    info(P)=x;
    next(P)=NULL;
    CreateList(P->Ldosen);
    return P;
}
