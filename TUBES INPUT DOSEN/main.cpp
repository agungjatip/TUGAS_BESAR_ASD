#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "jurusan.h"


using namespace std;

int main()
{
    List_jurusan jus;
    infotype_dosen d;
    infotype_jurusan j;
    CreateList(jus);
    int mainmenu = 0;
    while (mainmenu != 9)
    {
        system("cls");
        cout <<" ============================ "<<endl;
        cout <<"|      PROGRAM FAKULTAS      |"<<endl;
        cout <<" ============MENU============ "<<endl;
        cout <<"|1. INPUT DATA DOSEN         |"<<endl;
        cout <<"|2. INPUT DATA JURUSAN       |"<<endl;
        cout <<"|3. HAPUS DATA DOSEN         |"<<endl;
        cout <<"|4. HAPUS DATA JURUSAN       |"<<endl;
        cout <<"|5. CARI DATA DOSEN          |"<<endl;
        cout <<"|6. CARI DATA JURUSAN        |"<<endl;
        cout <<"|7. LIHAT DATA DOSEN         |"<<endl;
        cout <<"|8. LIHAT DATA JURUSAN       |"<<endl;
        cout <<"|9. KELUAR                   |"<<endl;
        cout <<" ============================ "<<endl;
        cout <<"MASUKKAN PILIHAN ANDA : ";
        cin>>mainmenu;
        cout<<endl;
        switch (mainmenu)
        {
        case 1:
        {
            system("cls");
            address_jurusan carjus;
            address_dosen cardos;
            cout<<"INPUTKAN DATA DOSEN"<<endl;
            cout<<"ID DOSEN : ";
            cin>>d.id;
            cout<<endl;
            cout<<"JURUSAN DOSEN : ";
            cin>>d.nama_jurusan;
            cout<<endl;
            cout<<"FAKULTAS DOSEN : ";
            cin>>d.fakultas;
            cout<<endl;
            cout<<"ALAMAT DOSEN : ";
            cin>>d.alamat;
            cout<<endl;
            cout<<"TIPE DOSEN : ";
            cin>>d.tipe;
            cout<<endl;
            carjus = FindElm(jus,d.tipe,d.nama_jurusan);
            if(carjus != NULL)
            {
                if (FindElm(carjus->Ldosen,d.id) == NULL)
                {
                    InsertFirst(carjus->Ldosen,Alokasi(d));
                }
                else
                {
                    cout<<"DOSEN DUPLIKAT"<<endl;
                }
            }
            else
            {
                cout<<"TIDAK ADA JURUSAN YANG SESUAI"<<endl;
            }
            break;
        }
        case 2:
        {
            system("cls");
            cout<<"INPUT NAMA JURUSAN"<<endl;
            cout<<"ID JURUSAN : ";
            cin>>j.id;
            cout<<endl;
            cout<<"JURUSAN : ";
            cin>>j.nama_jurusan;
            cout<<endl;
            cout<<"FAKULTAS : ";
            cin>>j.fakultas;
            cout<<endl;
            cout<<"KAPASITAS JURUSAN : ";
            cin>>j.kapasitas;
            cout<<endl;
            cout<<"ALAMAT JURUSAN : ";
            cin>>j.alamat;
            cout<<endl;
            cout<<"TIPE JURUSAN : ";
            cin>>j.tipe;
            cout<<endl;
            if(FindElm(jus,j.tipe,j.nama_jurusan) == NULL)
            {
                int opin=0;
                while (opin !=4)
                {
                    cout<<"1.Insert First"<<endl;
                    cout<<"2.Insert After"<<endl;
                    cout<<"3.Insert Last"<<endl;
                    cout<<"4.Main Menu"<<endl;
                    cout<<"Masukan Opsi : ";
                    cin>>opin;
                    if (opin==1)
                    {
                        InsertFirst(jus,Alokasi(j));
                        break;
                    }
                    else if (opin==2)
                    {
                        address_jurusan carjus;
                        infotype_jurusan ops;
                        cout<<"ALAMAT JURUSAN : ";
                        cin>>ops.alamat;
                        cout<<endl;
                        cout<<"TIPE JURUSAN : ";
                        cin>>ops.tipe;
                        cout<<endl;
                        cout<<"JURUSAN : ";
                        cin>>ops.nama_jurusan;
                        cout<<endl;
                        carjus = FindElm(jus,ops.tipe, ops.nama_jurusan);
                        if(carjus != NULL)
                        {
                            InsertAfter(jus, carjus, Alokasi(j));
                            cout<<"DATA MASUK!!!"<<endl;
                            Sleep(1598);
                            break;
                        }
                        else
                        {
                            cout<<"JURUSAN YANG DICARI TIDAK ADA"<<endl;
                            Sleep(1244);
                        }
                    }
                    else if (opin == 3)
                    {
                        InsertLast(jus,Alokasi(j));
                        cout<<"DATA MASUK!!!"<<endl;
                        Sleep(1287);
                        break;
                    }
                    else if (opin == 4)
                    {
                        break;
                    }
                    else
                    {
                        cout<<"OPSI YANG ANDA IMPUTKAN SALAH!!!!!!"<<endl;
                        Sleep(967);
                    }
                }
            }
            else
            {
                cout<<"DATA DUPLIKAT"<<endl;
                Sleep(1976);
            }

            break;
        }
        case 3 :
        {
            system("cls");
            cout<<"HAPUS DATA DOSEN"<<endl;
            cout<<"ID DOSEN : ";
            cin>>d.id;
            cout<<endl;
            cout<<"ALAMAT JURUSAN : ";
            cin>>j.alamat;
            cout<<endl;
            cout<<"TIPE JURUSAN : ";
            cin>>j.tipe;
            cout<<endl;
            cout<<"NAMA JURUSAN : ";
            cin>>j.nama_jurusan;
            cout<<endl;
            address_jurusan carjus = FindElm(jus,j.tipe,j.nama_jurusan);
            if (carjus != NULL)
            {
                address_dosen cardos = FindElm(carjus->Ldosen,d.id);
                if (cardos != NULL)
                {
                    if(cardos == First(carjus->Ldosen))
                    {
                        DeleteFirst(carjus->Ldosen,cardos);
                    }
                    else if (next(First(carjus->Ldosen)) != NULL)
                    {
                        address_dosen prec = First(carjus->Ldosen);
                        while(next(prec) != cardos)
                        {
                            prec = next(prec);
                        }
                        DeleteAfter(carjus->Ldosen,prec,cardos);
                    }
                    else
                    {
                        DeleteLast(carjus->Ldosen,cardos);
                    }
                }
            }
            {
                system("cls");
            }

            break;
        }
        case 4 :
        {
            system("cls");
            address_jurusan carjus;
            cout<<"HAPUS DATA JURUSAN"<<endl;
            cout<<"ALAMAT JURUSAN : ";
            cin>>j.alamat;
            cout<<endl;
            cout<<"TIPE JURUSAN : ";
            cin>>j.tipe;
            cout<<endl;
            cout<<"JURUSAN : ";
            cin>>j.nama_jurusan;
            cout<<endl;
            carjus = FindElm(jus, j.tipe, j.nama_jurusan);
            if(carjus != NULL)
            {
                if(carjus == First(jus))
                {
                    DeleteFirst(jus,carjus);
                }
                else if(next(carjus) != NULL)
                {
                    address_jurusan Prec = First(jus);
                    while(next(Prec) != carjus)
                    {
                        Prec = next(Prec);
                    }
                    DeleteAfter(jus, Prec, carjus);
                }
                else
                {
                    DeleteLast(jus, carjus);
                }
            }
            break;
        }
        case 5 :
        {
            cout<<"CARI DATA DOSEN"<<endl;
            {
                system("cls");
                cout<<"CARI DATA DOSEN "<<endl;
                cout<<"ID DOSEN : ";
                cin>>d.id;
                cout<<endl;
                cout<<"TIPE JURUSAN : ";
                cin>>j.tipe;
                cout<<endl;
                cout<<"NAMA JURUSAN : ";
                cin>>j.nama_jurusan;
                cout<<endl;
                address_jurusan carjus = FindElm(jus,d.tipe,d.nama_jurusan);
                if (carjus != NULL)
                {
                    address_dosen cardos = FindElm(carjus->Ldosen,d.id);
                    if (cardos != NULL)
                    {
                        cout<<"ID DOSEN             : "<<info(cardos).id<<endl;
                        cout<<"JURUSAN DOSEN        : "<<info(cardos).nama_jurusan<<endl;
                        cout<<"FAKULTAS DOSEN       : "<<info(cardos).fakultas<<endl;
                        cout<<"ALAMAT DOSEN         : "<<info(cardos).alamat<<endl;
                        cout<<"TIPE MENGAJAR DOSEN  : "<<info(cardos).tipe<<endl;
                        Sleep(2000);
                    }
                }
                else
                {
                    cout<<"DOSEN YANG DICARI TIDAK DITEMUKAN"<<endl;
                }
                break;
            }
        }
        case 6 :
        {
            system("cls");
            address_jurusan carjus;
            cout<<"CARI DATA JURUSAN"<<endl;
            cout<<endl;
            cout<<"TIPE JURUSAN : ";
            cin>>j.tipe;
            cout<<endl;
            cout<<"JURUSAN : ";
            cin>>j.nama_jurusan;
            cout<<endl;
            carjus = FindElm(jus, j.tipe, j.nama_jurusan);
            if(carjus != NULL)
            {
                cout<<"ID JURUSAN       : "<<info(carjus).id<<endl;
                cout<<"NAMA JURUSAN     : "<<info(carjus).nama_jurusan<<endl;
                cout<<"NAMA FAKULTAS    : "<<info(carjus).fakultas<<endl;
                cout<<"KAPASITAS JURUSAN: "<<info(carjus).kapasitas<<endl;
                cout<<"ALAMAT JURUSAN   : "<<info(carjus).alamat<<endl;
                cout<<"TIPE JURUSAN     : "<<info(carjus).tipe<<endl;
                Sleep(1000);
                break;
            }
            else
            {
                cout<<"JURUSAN YANG DICARI TIDAK DITEMUKAN"<<endl;
            }
            break;
        }
        case 7 :
        {
            cout<<"LIHAT DATA DOSEN"<<endl<<endl;
            address_jurusan P = First(jus);
            if(First(jus)!=NULL)
            {
                while (P != NULL)
                {
                    if (First(P->Ldosen) != NULL)
                    {
                        address_dosen Q = First(P->Ldosen);
                        while(Q!=NULL)
                        {
                            cout<<"ID DOSEN             : "<<info(Q).id<<endl;
                            cout<<"JURUSAN DOSEN        : "<<info(Q).nama_jurusan<<endl;
                            cout<<"FAKULTAS DOSEN       : "<<info(Q).fakultas<<endl;
                            cout<<"ALAMAT DOSEN         : "<<info(Q).alamat<<endl;
                            cout<<"TIPE MENGAJAR DOSEN  : "<<info(Q).tipe<<endl;
                            Q = next(Q);
                        }
                    }
                    P = next(P);
                }
            }
            Sleep(1000);
            break;
        }
        case 8 :
        {
            cout<<"LIHAT DATA JURUSAN"<<endl;
            PrintInfo(jus);
            Sleep(1000);
            break;
        }
        case 9 :
        {
            cout<<"TERIMA KASIH"<<endl;
            cout<<"AGUNG JATI PRAWIRA | 1301154421"<<endl;
            cout<<"ROFIF IRSYAD FAKHRUDDIN | 1301150001"<<endl;
            return 0;
        }
        default :
        {
            cout<<"INPUTAN YANG ANDA MASUKAN SALAH"<<endl;
            Sleep(1000);
            system("cls");
        }
        }
    }
}

