#include <iostream>
using namespace std;

int main() {
    int n;
    int x;
    cout << "masukkan: ";
    cin >> n;

    cout << "keluaran:\n";
    for (int i = n; i >= 1; i--) {
        for (int x = 0; x < n - i; x++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int x = 0; x < n; x++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}

