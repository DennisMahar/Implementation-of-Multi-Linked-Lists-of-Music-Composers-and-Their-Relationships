#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define info(P) (P)->info
#define next(P) (P)->next
#define child(P) (P)->child


// HEADER RELASI
typedef struct elmRelation *adrRelation;


// HEADER MUSIK
struct musik{
    string judul;
    string genre;
    string tahun;
    string pencipta1;
    string pencipta2;
    string pencipta3;
};

typedef struct elmMusik *adrMusik;

struct elmMusik{
    musik info;
    adrMusik next;
    adrRelation child;
};


struct listMusik{
    adrMusik first;
};


// HEADER KOMPOSER
struct komposer{
    string nama;
    string asal;
    string jeniskelamin;
    string tahunlahir;
};

typedef struct elmKomposer *adrKomposer;

struct elmKomposer{
    komposer info;
    adrKomposer next;
};


struct listKomposer{
    adrKomposer first;
};

// HEADER RELASI
struct elmRelation{
    adrRelation next;
    adrKomposer info;
};


int Menu();
/*
    FS : Menampilkan pilihan menu
*/



//    PROGRAM TERKAIT KOMPOSER

void createListKomposer(listKomposer &LK);
/*
    FS : Mengembalikan sebuah list kosong
*/
adrKomposer createElmKomposer(komposer k);
/*  IS : Tersedia data komposer
    FS : Mengembalikan alamat elemen list hasil alokasi, info berisi data dari masukan
*/
void insertLastKomposer (listKomposer &LK, adrKomposer p);
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
         dan
    FS : Elemen komposer ditambahkan sebagai elemen terakhir dari listKomposer LK
*/
void showDataKomposer(listKomposer LK);
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Menampilkan isi dari listKomposer LK secara vertikal
*/
void delFirstK(listKomposer &LK, adrKomposer p);
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Elemen pertama pada listKomposer terhapus
*/
void delLastK (listKomposer &LK, adrKomposer p);
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Elemen terakhir pada listKomposer terhapus
*/
void delAfterK(listKomposer &LK, adrKomposer p, adrKomposer prec);
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Elemen setelah adrKomposer prec pada listKomposer terhapus
*/
void deleteKomposer(listKomposer &LK, listMusik &LM,string namaK, string tahunK);
/*  IS : Terdefinisi sebuah listKomposer LK yang mungkin kosong
    FS : Pointer p berisi alamat elemen list LK yang memiliki nama = namaK dan tahunlahir = tahunK
         dan elemem tersebut dihapus dari listKomposer LK
*/
adrKomposer searchKomposer(listKomposer LK, string namaK, string tahunlahirK);
/*  IS : Terdefinisi sebuah listKomposer LK (mungkin kosong)
    FS : Mengembalikan alamat dari elemen list LK yang memiliki info namaK = nama dan tahunlahirK = tahunK
         atau NULL jika tidak ditemukan
*/
void showSelectedKomposer (adrKomposer k);
/*  IS : Terdefinisi sebuah adrKomposer k
    FS : Menampilkan isi dari adrKomposer k secara vertikal
*/



//    PROGRAM TERKAIT MUSIK

void createListMusik(listMusik &LM);
/*
    FS : Mengembalikan sebuah list kosong
*/
adrMusik createElmMusik(musik m);
/*  IS : Tersedia data musik
    FS : Mengembalikan alamat elemen list hasil alokasi, info berisi data dari masukan
*/
void insertLastMusik (listMusik &LM, adrMusik p);
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
         dan
    FS : Elemen komposer ditambahkan sebagai elemen terakhir dari listMusik LM
*/
void delFirstM(listMusik &LM, adrMusik p);
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Elemen pertama pada listMusik terhapus
*/
void delLastM (listMusik &LM, adrMusik p);
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Elemen terakhir pada listMusik terhapus
*/
void delAfterM(listMusik &LM, adrMusik p, adrMusik prec);
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Elemen setelah adrMusik prec pada listMusik terhapus
*/
void showDataMusik(listMusik LM);
/*  IS : Terdefinisi sebuah listMusik LM yang mungkin kosong
    FS : Menampilkan isi dari listMusik LM secara vertikal
*/
adrMusik searchMusik(listMusik LM, string judulM, string tahunM);
/*  IS : Terdefinisi sebuah listMusik LM (mungkin kosong)
    FS : Mengembalikan nilai True apabila info judulM = judul dan tahunM = tahun,
         atau NULL jika tidak ditemukan
*/
void showSelectedMusik(adrMusik m);
/*  IS : Terdefinisi sebuah adrMusik m
    FS : Menampilkan isi dari adrMusik m secara vertikal
*/



//    PROGRAM TERKAIT RELASI

adrRelation createElmRelasi (adrKomposer p);
/*  IS : Tersedia data relasi
    FS : Mengembalikan alamat hasil alokasi, info berisi adrKomposer
*/
void insertLastRelasi (adrMusik &m, adrRelation r);
/*  IS : Terdefinisi sebuah adrMusik m
    FS : Elemen relasi ditambahkan sebagai elemen terakhir dari child m
*/
void gabungKompMusik(listKomposer &LK, listMusik &LM);
/*  IS : Terdefinisi listKomposer LK dan listMusik LM yang tidak terhubung
    FS : listKomposer LK dan listMusik LM terhubung berdasarkan pencipta musik dan nama komposer
*/
void hapusHubungan(listKomposer &LK, listMusik &LM);
/*  IS : Terdefinisi listKomposer LK dan listMusik LM yang terhubung
    FS : listKomposer LK dan listMusik LM tidak terhubung
*/
void showKompMusik (listKomposer LK, listMusik LM);
/*  IS : Terdefinisi listKomposer LK dan listMusik LM yang terhubung
    FS : Menampilkan isi dari listKomposer LK secara vertikal berserta karya musiknya di listMusik LM
*/
void searchMusikKomp(listKomposer LK, listMusik LM, string namaK, string tahunK);
/*  IS : Terdefinisi sebuah listKomposer LK dan listMusik LM
    FS : Mengembalikan  apabila info judulM = judul dan tahunM = tahun,
         atau  jika tidak ditemukan
*/
void delFirstR(adrMusik &m, adrRelation r);
/*  IS : Terdefinisi sebuah chidl adrMusik m  yang mungkin kosong
    FS : Elemen pertama pada child pada adrMusik m terhapus
*/
void delLastR (adrMusik &m, adrRelation r);
/*  IS : Terdefinisi sebuah child adrMusik m  yang mungkin kosong
    FS : Elemen terakhir pada child pada adrMusik m terhapus
*/
void delAfterR(adrMusik &m, adrRelation r, adrRelation prec);
/*  IS : Terdefinisi sebuah child adrMusik m yang mungkin kosong
    FS : Elemen setelah child pada adrMusik m terhapus
*/
void hapusMusikKomp(listKomposer LK, listMusik LM, string namaK, string tahunlahirK);
/*  IS : Terdefinisi listKomposer LK dan listMusik LM yang terhubung
    FS : Data Musik dari Komposer dengan namaK terhapus
*/
void showColab(listKomposer &LK, listMusik &LM);
/*  IS : Terdefinisi listKomposer LK dan listMusik LM yang terhubung
    FS : Menampilkan isi dari listKomposer LK yang terlibat dalam musik yang sama pada listMusik LM
*/

#endif // TUBES_H_INCLUDED
