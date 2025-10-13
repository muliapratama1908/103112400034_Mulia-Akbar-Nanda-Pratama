#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string mapel = "Struktur Data";
    string kode = "STD";
    
    pelajaran pel = buat_pelajaran(mapel, kode);
    
    tampil_pelajaran(pel);
    
    return 0;
}