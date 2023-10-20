#include "tubes.h"
#include <iostream>

using namespace std;

int Menu(){
    int pilih;
    cout << "========= Menu ========="<<endl;
    cout << "1. Tambah Data Komposer" << endl;
    cout << "2. Tambah Data Musik" << endl;
    cout << "3. Menghubungkan Data Musik ke Data Komposer" << endl;

    cout << "4. Hapus Data Komposer Beserta Relasinya" << endl;
    cout << "5. Hapus Data Musik Pada Komposer" << endl;

    cout << "6. Cari Data Komposer" << endl;
    cout << "7. Cara Data Musik" << endl;
    cout << "8. Cari Data Musik Pada Komposer" << endl;

    cout << "9. Tampilkan Semua Data Komposer" << endl;
    cout << "10. Tampilkan Semua Data Musik" << endl;
    cout << "11. Tampilkan Data Komposer Beserta Musiknya" << endl;
    cout << "12. Tampilkan Data Komposer Dengan Musik Yang Sama" << endl;

    cout << "0. Keluar" << endl;
    cout << endl;
    cout << "Masukkan menu : ";
    cin >> pilih;
    return pilih;
}


//===================================================================================================
/*       PROGRAM TERKAIT KOMPOSER         */
//===================================================================================================

void createListKomposer(listKomposer &LK){
/*
    FS : Mengembalikan sebuah list kosong
*/
    first(LK) = NULL;
}

adrKomposer createElmKomposer(komposer k){
/*  IS : Tersedia data komposer
    FS : Mengembalikan alamat elemen list hasil alokasi, info berisi data dari masukan
*/

    adrKomposer p = new elmKomposer;
    info(p) = k;
    next(p) = NULL;
    return p;
}

void insertLastKomposer (listKomposer &LK, adrKomposer p){
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
         dan
    FS : Elemen komposer ditambahkan sebagai elemen terakhir dari listKomposer LK
*/

    adrKomposer bantu = first(LK);
    if (first(LK)==NULL){
        first(LK) = p;
    }else{
        while (next(bantu)!= NULL){
            bantu = next(bantu);
        }
        next(bantu) = p;
    }
}

void showDataKomposer (listKomposer LK){
/*  IS : Terdifinisi sebuah listKomposer LK yang mungkin kosong
    FS : Menampilkan isi dari listKomposer LK secara vertikal
*/

    adrKomposer bantu = first(LK);
    if (first(LK) == NULL){
        cout << "List Komposer Kosong" << endl;
    }else{
        cout << "========  DATA KOMPOSER  ========"<<endl << endl;
        while (bantu != NULL){
            cout << "  Nama Komposer : "<<info(bantu).nama<<endl;
            cout << "  Asal Komposer : "<<info(bantu).asal<<endl;
            cout << "  Jenis Kelamin : "<<info(bantu).jeniskelamin<<endl;
            cout << "  Tahun Lahir   : "<<info(bantu).tahunlahir<<endl;
            cout << endl;
            bantu = next(bantu);
        }
        cout << "================================="<<endl;
    }
}

adrKomposer searchKomposer(listKomposer LK, string namaK, string tahunlahirK){
/*  IS : Terdefinisi sebuah listKomposer LK (mungkin kosong)
    FS : Mengembalikan alamat dari elemen listKomposer LK apabila info namaK = nama dan tahunlahirK = tahunlahir,
         atau NULL jika tidak ditemukan
*/

    adrKomposer k = first(LK);

    if (first(LK) == NULL){
        cout << "List Komposer Kosong";
    }else{
        while (k != NULL){
            if (info(k).nama == namaK && info(k).tahunlahir == tahunlahirK){
                return k;
            }else{
                k = next(k);
            }
        }
        return NULL;
    }
}

void showSelectedKomposer (adrKomposer k){
    cout << "  Nama Komposer : "<<info(k).nama<<endl;
    cout << "  Asal Komposer : "<<info(k).asal<<endl;
    cout << "  Jenis Kelamin : "<<info(k).jeniskelamin<<endl;
    cout << "  Tahun Lahir   : "<<info(k).tahunlahir<<endl;
}

void delFirstK(listKomposer &LK, adrKomposer p){
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Elemen pertama pada listKomposer terhapus
*/
    if (first(LK) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(first(LK)) == NULL){
        first(LK) = NULL;
    }else{
        p = first(LK);
        first(LK) = next(p);
        next(p) = NULL;
    }
}

void delLastK (listKomposer &LK, adrKomposer p){
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Elemen terakhir pada listKomposer terhapus
*/

    if (first(LK) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(first(LK)) == NULL){
        first(LK) = NULL;
    }else{
        adrKomposer Q = first(LK);
        while (next(next(Q)) == NULL){
            Q = next(Q);
        }
        p = next(Q);
        next(Q) = NULL;
    }
}

void delAfterK(listKomposer &LK, adrKomposer p, adrKomposer prec){
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Elemen setelah adrKomposer prec pada listKomposer terhapus
*/
    if (first(LK) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(first(LK)) == NULL){
        first(LK) = NULL;
    }else{
        p = next(prec);
        next(prec) = next(p);
        next(p) = NULL;
    }

}

void deleteKomposer(listKomposer &LK,listMusik &LM, string namaK, string tahunK){
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Pointer p berisi alamat elemen list LK yang memiliki nama = namaK dan tahunlahir = tahunK
         dan elemem tersebut dihapus dari listKomposer LK
*/

    hapusHubungan(LK, LM);
    adrKomposer cari = searchKomposer(LK, namaK, tahunK);
    if (cari == NULL){
        cout << "... Komposer Yang Diinputkan Tidak Ada ...!!!" << endl << endl;
    }else{
        // Proses Hapus Komposer
        adrKomposer tampungK;
        if (cari == first(LK)) {
            delFirstK(LK, tampungK);
        } else {
            adrKomposer r = first(LK);
            while (next(r) != cari) {
                r = next(r);
            }
            if (next(next(r)) == NULL) {
                delLastK(LK, tampungK);
            } else {
                delAfterK(LK, tampungK, cari);
            }
        }
        cout << "Data Komposer Pada List Komposer Beserta Relasinya Telah Dihapus...!!!" << endl << endl;
    }
    gabungKompMusik(LK,LM);

}


//===================================================================================================
/*       PROGRAM TERKAIT MUSIK         */
//===================================================================================================

void createListMusik(listMusik &LM){
/*
    FS : Mengembalikan sebuah list kosong
*/
    first(LM) = NULL;
}

adrMusik createElmMusik(musik m){
/*  IS : Tersedia data musik
    FS : Mengembalikan alamat elemen list hasil alokasi, info berisi data dari masukan
*/

    adrMusik p = new elmMusik;
    info(p) = m;
    child(p) = NULL;
    next(p) = NULL;
    return p;
}

void insertLastMusik (listMusik &LM, adrMusik p){
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
         dan
    FS : Elemen komposer ditambahkan sebagai elemen terakhir dari listMusik LM
*/

    adrMusik bantu = first(LM);
    if (first(LM)==NULL){
        first(LM) = p;
        //next(p) = first(LM);
    }else{
        while (next(bantu)!= NULL){
            bantu = next(bantu);
        }
        next(bantu) = p;


    }
}

void showDataMusik(listMusik LM){
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Menampilkan isi dari listMusik LM secara vertikal
*/
   adrMusik bantu = first(LM);
    if (first(LM) == NULL){
        cout << "List Musik Kosong" << endl;
    }else{
        cout << "=================  DATA MUSIK  ================="<<endl << endl;
        while (bantu != NULL){
            cout << "   Judul Musik : "<<info(bantu).judul<<endl;
            cout << "   Genre Musik : "<<info(bantu).genre<<endl;
            cout << "   Tahun Rilis Musik : "<<info(bantu).tahun<<endl;
            cout << "   Pencipta Musik : "<<info(bantu).pencipta1 ;
            if (info(bantu).pencipta2 != "-" && info(bantu).pencipta3 == "-"){
                cout << ", " << info(bantu).pencipta2 << endl;
            }else if (info(bantu).pencipta2 != "-" && info(bantu).pencipta3 != "-"){
                cout << ", " << info(bantu).pencipta2 << ", " << info(bantu).pencipta3 << endl;
            }else {
                cout << endl;
            }
            cout << endl;
            bantu = next(bantu);
        }
        cout << "================================================"<<endl;
    }

}

adrMusik searchMusik(listMusik LM, string judulM, string tahunM){
/*  IS : Terdefinisi sebuah listMusik LM (mungkin kosong)
    FS : Mengembalikan alamat dari elemen listMusik LM apabila info judulM = judul dan tahunM = tahun,
         atau NULL jika tidak ditemukan
*/

    adrMusik m = first(LM);

    if (first(LM) == NULL){
        cout << "List Musik Kosong";
    }else{
        while (m != NULL){
            if (info(m).judul == judulM && info(m).tahun == tahunM){
                return m;
            }else{
                m = next(m);
            }
        }
        return NULL;
    }
}

void showSelectedMusik(adrMusik m){
    cout << "  Judul Musik : "<<info(m).judul<<endl;
    cout << "  Genre Musik : "<<info(m).genre<<endl;
    cout << "  Tahun Rilis Musik : "<<info(m).tahun<<endl;
    cout << "  Pencipta Musik   : "<<info(m).pencipta1 ;
    if (info(m).pencipta2 != "-" && info(m).pencipta3 == "-"){
        cout << ", " << info(m).pencipta2 << endl;
    }else if (info(m).pencipta2 != "-" && info(m).pencipta3 != "-"){
        cout << ", " << info(m).pencipta2 << ", " << info(m).pencipta3 << endl;
    }else {
        cout << endl;
    }
    cout << endl;
}

void delFirstM(listMusik &LM, adrMusik p){
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Elemen pertama pada listMusik terhapus
*/
    if (first(LM) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(first(LM)) == NULL){
        first(LM) = NULL;
    }else{
        p = first(LM);
        first(LM) = next(p);
        next(p) = NULL;
    }
}

void delLastM (listMusik &LM, adrMusik p){
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Elemen terakhir pada listMusik terhapus
*/

    if (first(LM) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(first(LM)) == NULL){
        first(LM) = NULL;
    }else{
        adrMusik Q = first(LM);
        while (next(next(Q)) == NULL){
            Q = next(Q);
        }
        p = next(Q);
        next(Q) = NULL;
    }
}

void delAfterM(listMusik &LM, adrMusik p, adrMusik prec){
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Elemen setelah adrMusik prec pada listMusik terhapus
*/
    if (first(LM) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(first(LM)) == NULL){
        first(LM) = NULL;
    }else{
        p = next(prec);
        next(prec) = next(p);
        next(p) = NULL;
    }

}


//===================================================================================================
/*       PROGRAM TERKAIT RELASI         */
//===================================================================================================

adrRelation createElmRelasi (adrKomposer k){
    adrRelation r = new elmRelation;
    info(r) = k;
    next(r) = NULL;
    return r;
}

void insertLastRelasi (adrMusik &m, adrRelation r){
    if (child(m) == NULL){
        child(m) = r;
    }else{
        adrRelation a = child(m);
        while (next(a) != NULL){
            a = next(a);

        }
        next(a) = r;
    }
}

void gabungKompMusik(listKomposer &LK, listMusik &LM){
    adrKomposer k = first(LK);

    while (k!=NULL){
        adrMusik m = first(LM);
        while (m!= NULL){
            if (info(m).pencipta1 == info(k).nama || info(m).pencipta2 == info(k).nama || info(m).pencipta3 == info(k).nama ){
                adrRelation r = createElmRelasi(k);
                insertLastRelasi(m,r);
            }
            m = next(m);
        }
        k = next(k);
    }
}

void hapusHubungan(listKomposer &LK, listMusik &LM){
    adrKomposer k = first(LK);

    while (k!=NULL){
        adrMusik m = first(LM);
        while (m!= NULL){
            adrRelation r = child(m);
            while (r!= NULL){
                delFirstR(m ,r);
                r = next(r);
            }
            m = next(m);
        }
        k = next(k);
    }
}

void showKompMusik (listKomposer LK, listMusik LM){
    adrKomposer bantu = first(LK);
    if (first(LK) == NULL){
        cout << "List Komposer Kosong" << endl;
    }else{
        cout << "=============== DATA KOMPOSER BESERTA MUSIKNYA  ==============="<<endl <<endl;
        while (bantu != NULL){
            cout << "Data Komposer : " << endl;
            showSelectedKomposer(bantu);

            cout << "Karya Musiknya : " << endl;
            int i = 1;
            adrMusik m = first(LM);
            while (m != NULL){
                adrRelation r = child(m);
                while (r != NULL){
                    if ( info(r) == bantu){
                        cout << "  Musik " << i << endl;
                        cout << "   -  Judul Musik       : " << info(m).judul << endl;
                        cout << "   -  Genre Musik       : " << info(m).genre << endl;
                        cout << "   -  Tahun Rilis Musik : " << info(m).tahun << endl;
                        i++;
                    }
                    r = next(r);
                }
                m = next(m);
            }
            cout << endl << endl;
            bantu = next(bantu);
        }
        cout << "==============================================================="<<endl;
    }

}

void searchMusikKomp(listKomposer LK, listMusik LM, string namaK, string tahunK){
/*  IS : Terdefinisi sebuah listKomposer LK dan listMusik LM
    FS : Mengembalikan  apabila info judulM = judul dan tahunM = tahun,
         atau NULL jika tidak ditemukan
*/
    adrKomposer cari = searchKomposer(LK, namaK, tahunK);
    if (cari == NULL){
        cout << "... Komposer Yang Diinputkan Tidak Ada ...!!!" << endl << endl;
    }else{
        if (first(LM) == NULL){
            cout << "List Musik Kosong" << endl << endl;
        }else{
            cout << "Karya Musik Dari " << namaK << " : "<< endl;
            adrKomposer bantu = first(LK);
            while (bantu != NULL){
                if (info(bantu).nama == namaK){
                    int i = 1;
                    adrMusik m = first(LM);
                    while (m != NULL){
                        adrRelation r = child(m);
                        while (r != NULL){
                            if ( info(r) == bantu){
                                cout << "  Musik " << i << endl;
                                cout << "   -  Judul Musik       : " << info(m).judul << endl;
                                cout << "   -  Genre Musik       : " << info(m).genre << endl;
                                cout << "   -  Tahun Rilis Musik : " << info(m).tahun << endl;
                                i++;
                            }
                            r = next(r);
                        }
                        m = next(m);
                    }
                    bantu = next(bantu);
                }else{
                    bantu = next(bantu);
                }
            }
            cout << endl;
        }
    }
}

void showColab(listKomposer &LK, listMusik &LM){
/*  IS : Terdefinisi listKomposer LK dan listMusik LM yang terhubung
    FS : Menampilkan isi dari listKomposer LK yang terlibat dalam musik yang sama pada listMusik LM
*/
    cout << "==== KOMPOSER YANG TERLIBAT PADA PROYEK MUSIK YANG SAMA ====" << endl << endl;
    adrMusik m = first(LM);
    while (m != NULL){
        adrRelation r = child(m);
        if ( next(r) != NULL){
            while (r != NULL){
                cout << "   Komposer : " << info(info(r)).nama << endl;


                r = next(r);
            }
        cout << "   Terlibat Bersama Pada Musik : " << info(m).judul << endl;
        cout << endl;
        }

        m = next(m);
    }
    cout << "============================================================" << endl << endl;
}

void delFirstR(adrMusik &m, adrRelation r){
/*  IS : Terdefinisi sebuah chidl adrMusik m  yang mungkin kosong
    FS : Elemen pertama pada child pada adrMusik m terhapus
*/
    if (child(m) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(child(m)) == NULL){
        child(m) = NULL;
    }else{
        r = child(m);
        child(m) = next(r);
        next(r) = NULL;
    }
}

void delLastR (adrMusik &m, adrRelation r){
/*  IS : Terdefinisi sebuah child adrMusik m  yang mungkin kosong
    FS : Elemen terakhir pada child pada adrMusik m terhapus
*/

    if (child(m) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(child(m)) == NULL){
        child(m) = NULL;
    }else{
        adrRelation bantu = child(m);
        while(next(next(bantu)) == NULL){
            bantu = next(bantu);
        }
        r = next(bantu);
        next(bantu) = NULL;
    }
}

void delAfterR(adrMusik &m, adrRelation r, adrRelation prec){
/*  IS : Terdefinisi sebuah child adrMusik m yang mungkin kosong
    FS : Elemen setelah child pada adrMusik m terhapus
*/
    if (child(m) == NULL){
        cout << "List Kosong" << endl;
    }else if(next(child(m)) == NULL){
        child(m) = NULL;
    }else{
        r = next(prec);
        next(prec) = next(r);
        next(r) = NULL;
    }
}

void hapusMusikKomp(listKomposer LK, listMusik LM, string namaK, string tahunK){
/*  IS : Terdefinisi listKomposer LK dan listMusik LM yang terhubung
    FS : Data Musik dari Komposer dengan namaK terhapus
*/
    adrKomposer cari = searchKomposer(LK,namaK,tahunK);

    adrMusik m = first(LM);
    while (m != NULL){
        adrRelation r = child(m);
        while (r != NULL){
            if (info(r) == cari){
                info(r) = NULL;
            }
            r = next(r);
        }
        m = next(m);
    }

    cout << "Data Musik Dari Komposer " << namaK <<" Telah Dihapus...!!!" << endl << endl;
}












