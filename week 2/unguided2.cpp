#include <iostream>

using namespace std;

int main() {
    int p = 10;
    int lbr = 5;
    int l = 0;
    int k= 0;

    cout << " nilai awal " << endl;
    cout << "Panjang: " << p << endl;
    cout << "Lebar: " << lbr << endl;
    cout << endl;

    int *ptrPanjang = &p;
    int *ptrLebar = &lbr;

    l = (*ptrPanjang) * (*ptrLebar);
    k= 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << " hasil " << endl;
    cout << "Luas Persegi Panjang: " << l << endl;
    cout << "Keliling Persegi Panjang: " << k<< endl;
    cout << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << " nilai setelah diubah " << endl;
    cout << "Panjang Baru: " << p<< endl;
    cout << "Lebar Baru: " << lbr<< endl;

    l = (*ptrPanjang) * (*ptrLebar);
    k = 2 * ((*ptrPanjang) + (*ptrLebar));
    cout << "Luas Baru: " << l << endl;
    cout << "Keliling Baru: " << k << endl;

    return 0;
}