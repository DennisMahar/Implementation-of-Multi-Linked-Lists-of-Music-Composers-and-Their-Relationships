#include "tubes.h"
#include <iostream>


using namespace std;

int main()
{
    listKomposer LK;
    listMusik LM;

    createListKomposer(LK);
    createListMusik(LM);

    komposer dataK;
    musik dataM;

    //Mengisi List Komposer
    dataK.nama = "Chopin";
    dataK.asal = "Polandia";
    dataK.jeniskelamin = "Laki-laki";
    dataK.tahunlahir = "1810";
    insertLastKomposer(LK, createElmKomposer(dataK));

    dataK.nama = "Beethoven";
    dataK.asal = "Jerman";
    dataK.jeniskelamin = "Laki-laki";
    dataK.tahunlahir = "1770";
    insertLastKomposer(LK, createElmKomposer(dataK));

    dataK.nama = "Bach";
    dataK.asal = "Jerman";
    dataK.jeniskelamin = "Laki-laki";
    dataK.tahunlahir = "1685";
    insertLastKomposer(LK, createElmKomposer(dataK));

    dataK.nama = "Clara";
    dataK.asal = "Jerman";
    dataK.jeniskelamin = "Perempuan";
    dataK.tahunlahir = "1819";
    insertLastKomposer(LK, createElmKomposer(dataK));

    dataK.nama = "Vivaldi";
    dataK.asal = "Italia";
    dataK.jeniskelamin = "Laki-laki";
    dataK.tahunlahir = "1678";
    insertLastKomposer(LK, createElmKomposer(dataK));


    //Mengisi List Musik
    dataM.judul = "Moonlight_Sonata";
    dataM.genre = "Klasik";
    dataM.tahun = "1801";
    dataM.pencipta1 = "Beethoven";
    dataM.pencipta2 = "-";
    dataM.pencipta3 = "-";
    insertLastMusik(LM, createElmMusik(dataM));

    dataM.judul = "Fur_Elise";
    dataM.genre = "Romantik";
    dataM.tahun = "1810";
    dataM.pencipta1 = "Beethoven";
    dataM.pencipta2 = "-";
    dataM.pencipta3 = "-";
    insertLastMusik(LM, createElmMusik(dataM));

    dataM.judul = "Etudes";
    dataM.genre = "Klasik";
    dataM.tahun = "1830";
    dataM.pencipta1 = "Chopin";
    dataM.pencipta2 = "-";
    dataM.pencipta3 = "-";
    insertLastMusik(LM, createElmMusik(dataM));

    dataM.judul = "Preludes";
    dataM.genre = "Romantik";
    dataM.tahun = "1834";
    dataM.pencipta1 = "Chopin";
    dataM.pencipta2 = "-";
    dataM.pencipta3 = "-";
    insertLastMusik(LM, createElmMusik(dataM));

    dataM.judul = "Piano_Manjor_Sonata";
    dataM.genre = "Klasik";
    dataM.tahun = "1832";
    dataM.pencipta1 = "Bach",
    dataM.pencipta2 = "Beethoven";
    dataM.pencipta3 = "-";
    insertLastMusik(LM, createElmMusik(dataM));

    dataM.judul = "Simfoni_E_Minor";
    dataM.genre = "Klasik";
    dataM.tahun = "1728";
    dataM.pencipta1 = "Bach",
    dataM.pencipta2 = "Vivaldi";
    dataM.pencipta3 = "-";
    insertLastMusik(LM, createElmMusik(dataM));

    dataM.judul = "Mass_in_C_Major";
    dataM.genre = "Romantik";
    dataM.tahun = "1861";
    dataM.pencipta1 = "Beethoven",
    dataM.pencipta2 = "Chopin";
    dataM.pencipta3 = "Clara";
    insertLastMusik(LM, createElmMusik(dataM));

    //Menghubungkan listKomposer LK dan listKomposer LM
    gabungKompMusik(LK,LM);

    // Program Menu
    int pilih;
    pilih = Menu();
    cout << endl;

    while (pilih != 0){
        if (pilih == 1){

            int N;
            komposer dataK;
            hapusHubungan(LK,LM);

            cout << "Masukan Jumlah Komposer Yang Akan Diinputkan : ";
            cin >> N;
            cout << endl;
            for (int i=1;i<=N;i++){
                cout << "Data Komposer Ke-" << i << endl;
                cout << "Nama Komposer : ";
                cin >> dataK.nama;
                cout << "Asal Komposer : ";
                cin >> dataK.asal;
                cout << "Jenis Kelamin : ";
                cin >> dataK.jeniskelamin;
                cout << "Tahun Lahir   : ";
                cin >> dataK.tahunlahir;

                insertLastKomposer(LK,createElmKomposer(dataK));
                cout << endl;
            }
            hapusHubungan(LK,LM);
            cout << "Data Komposer Berhasil Ditambahkan...!!!" << endl << endl;

        }else if(pilih==2){

            int N;
            musik dataM;
            hapusHubungan(LK,LM);

            cout << "Masukan Jumlah Musik Yang Akan Diinputkan : ";
            cin >> N;
            cout << endl;
            for (int i=1;i<=N;i++){
                cout << "Data Musik Ke-" << i << endl;
                cout << "Judul Musik        : ";
                cin >> dataM.judul;
                cout << "Genre Musik        : ";
                cin >> dataM.genre;
                cout << "Tahun Rilis Musik  : ";
                cin >> dataM.tahun;
                cout << "Pencipta Musik        : ";
                cin >> dataM.pencipta1;
                cout << "Pecipta 2 (jika tidak ada inputkan tanda '-') : ";
                cin >> dataM.pencipta2;
                cout << "Pecipta 3 (jika tidak ada inputkan tanda '-') : ";
                cin >> dataM.pencipta3;

                insertLastMusik(LM,createElmMusik(dataM));
                cout << endl;
            }

            cout << "Data Musik Berhasil Ditambahkan...!!!" << endl << endl;

        }else if(pilih==3){
            gabungKompMusik(LK,LM);
            cout << "List Komposer dan List Musik Telah Dihibungkan...!!!" << endl << endl;

        }else if(pilih==4){
            string namaK, tahunlahirK;
            cout << "Inputkan Nama Komposer Yang Ingin Dihapus : " ;
            cin >> namaK;
            cout << "Inputkan Tahun Lahir Komposer Yang Ingin Dihapus : " ;
            cin >> tahunlahirK;
            cout << endl;

            deleteKomposer(LK,LM,namaK,tahunlahirK);

        }else if(pilih==5){
            string namaK, tahunlahirK;
            cout << "Inputkan Nama Komposer Yang Ingin Dihapus Musiknya : " ;
            cin >> namaK;
            cout << "Inputkan Tahun Lahir Komposer Yang Ingin Dihapus Musiknya : " ;
            cin >> tahunlahirK;
            cout << endl;

            hapusMusikKomp(LK, LM, namaK, tahunlahirK);

        }else if(pilih==6){
            string namaK, tahunlahirK;
            cout << "Inputkan Nama Komposer Yang Dicari : " ;
            cin >> namaK;
            cout << "Inputkan Tahun Lahir Komposer Yang Dicari : " ;
            cin >> tahunlahirK;
            cout << endl;

            adrKomposer x = searchKomposer(LK, namaK, tahunlahirK);
            if (x == NULL){
                cout << "... Data Komposer Tidak Ditemukan ... !!" << endl << endl;
            }else{
                cout << "=== DATA KOMPOSER DI CARI ===" << endl << endl;
                showSelectedKomposer(x);
                cout << endl;
                cout << "=============================" << endl << endl;

            }
        }else if(pilih==7){
            string judulM, tahunM;
            cout << "Inputkan Judul Musik Yang Dicari : " ;
            cin >> judulM;
            cout << "Inputkan Tahun Musik Yang Dicari : " ;
            cin >> tahunM;
            cout << endl;

            adrMusik x = searchMusik(LM, judulM, tahunM);
            if (x == NULL){
                cout << "... Data Musik Tidak Ditemukan ... !!" << endl << endl;
            }else{
                cout << "=== DATA MUSIK YANG DI CARI ===" << endl << endl;
                showSelectedMusik(x);
                cout << endl;
                cout << "=============================" << endl << endl;
            }

        }else if(pilih==8){
            string Knama, Ktahun;
            cout << "Inputkan Nama Komposer Yang Dicari : " ;
            cin >> Knama;
            cout << "Inputkan Tahun Lahir Komposer Yang Dicari : " ;
            cin >> Ktahun;
            cout << endl << endl;

            cout << "==========================================" << endl << endl;
            searchMusikKomp(LK,LM,Knama,Ktahun);
            cout << "==========================================" << endl << endl;

        }else if(pilih==9){
            showDataKomposer(LK);

        }else if(pilih==10){
            showDataMusik(LM);

        }else if(pilih==11){
            showKompMusik(LK,LM);

        }else if(pilih==12){
            showColab(LK,LM);
        }else if(pilih==0){
            break;
        }

        char kembali;
        cout << "Kembali ke menu utama?(Y/N) ";
        cin >> kembali;
        cout << endl;
        if(kembali == 'Y' || kembali == 'y')
        {
            pilih = Menu();
            cout << endl;
        }else if (kembali == 'N' || kembali == 'n')
        {
            return 0;
        }else{
            cout << "Kembali ke menu utama?(Y/N) ";
            cin >> kembali;
            cout << endl;
            if(kembali == 'Y' || kembali == 'y')
            {
                pilih = Menu();
                cout << endl;
            }else if (kembali == 'N' || kembali == 'n')
            {
                return 0;
            }else{
                cout << "Kembali ke menu utama?(Y/N) ";
                cin >> kembali;
                if(kembali == 'Y' || kembali == 'y')
                {
                    pilih = Menu();
                    cout << endl;
                }else
                {
                    return 0;

                }
            }
        }
    }


    return 0;
}

