#ifndef JURUSAN_H_INCLUDED
#define JURUSAN_H_INCLUDED
#define Nil NULL
#include "dosen.h"
#define next(P) P->next
#define First(L) L.First
#define info(P) P->info
#include <iostream>

using namespace std;

struct jurusan{
    int id;
    string nama_jurusan;
    string fakultas;
    int kapasitas;
    string alamat;
    string tipe;
};

typedef jurusan infotype_jurusan;
typedef struct elmlist_jurusan *address_jurusan;

struct elmlist_jurusan{
    infotype_jurusan info;
    address_jurusan next;
    List_dosen Ldosen;
};

struct List_jurusan{
    address_jurusan First;
};

void CreateList(List_jurusan &L);
void InsertFirst(List_jurusan &L, address_jurusan P);
void InsertAfter(List_jurusan &L, address_jurusan Prec, address_jurusan P);
void InsertLast(List_jurusan &L, address_jurusan P);
void DeleteFirst(List_jurusan &L, address_jurusan &P);
void DeleteLast(List_jurusan &L, address_jurusan &P);
void DeleteAfter(List_jurusan &L, address_jurusan Prec, address_jurusan &P);
address_jurusan FindElm(List_jurusan L, string tip, string namjur);
void PrintInfo(List_jurusan L);
address_jurusan Alokasi (infotype_jurusan x);

#endif // JURUSAN_H_INCLUDED
