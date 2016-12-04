#ifndef DOSEN_H_INCLUDED
#define DOSEN_H_INCLUDED
#include <iostream>

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define First(L) L.First
#define Last(L) L.Last
#define info(P) P->info
#define parent(P) P->parent

struct dosen{
    int id;
    string nama_jurusan;
    string fakultas;
    string alamat;
    string tipe;
};

typedef dosen infotype_dosen;
typedef struct elmlist_dosen *address_dosen;

struct elmlist_dosen{
    infotype_dosen info;
    address_dosen next;
    address_dosen prev;
};

struct List_dosen{
    address_dosen First;
    address_dosen Last;
};

void CreateList(List_dosen &L);
void InsertFirst(List_dosen &L, address_dosen P);
void InsertAfter(List_dosen &L,address_dosen Prec, address_dosen P);
void InsertLast(List_dosen &L, address_dosen P);
void DeleteFirst(List_dosen &L, address_dosen &P);
void DeleteLast(List_dosen &L, address_dosen &P);
void DeleteAfter(List_dosen &L,address_dosen Prec, address_dosen &P);
address_dosen FindElm(List_dosen L, int id);
void PrintInfo(List_dosen L);
address_dosen Alokasi (infotype_dosen x);


#endif // DOSEN_H_INCLUDED
