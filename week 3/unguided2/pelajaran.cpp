#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran buat_pelajaran(string mapel, string kode) {
    pelajaran p;
    p.namaMapel = mapel;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}