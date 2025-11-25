#include <iostream>
#include "StackMahasiswa.h"
using namespace std;
int main() {
    StackMahasiswa S;
    createStack(S);
    int pilihan;
    while (true) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Update\n";
        cout << "4. View\n";
        cout << "5. Exit\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            Push(S);
        } 
        else if (pilihan == 2) {
            Pop(S);
        } 
        else if (pilihan == 3) {
            int pos;
            cout << "masukan posisi yg mau di update: ";
            cin >> pos;
            Update(S, pos);
        } 
        else if (pilihan == 4) {
            View(S);
        }
        else if (pilihan == 6) {
            break;
        }
    }
    return 0;
}
