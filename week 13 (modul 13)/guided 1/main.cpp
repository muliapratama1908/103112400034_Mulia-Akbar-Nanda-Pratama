#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    listInduk LInduk;
    createListInduk(LInduk);

    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    printStrukturMLL(LInduk);
    cout << endl;

    findChildByID(LInduk, "D01");
    cout << endl;
    deleteAfterChild(k01->L_Anak, M01);
    cout<< endl;
    deleteAfterParent(LInduk, k02);
    cout << endl;
    printStrukturMLL(LInduk);
    cout << endl;
    
    return 0;
}