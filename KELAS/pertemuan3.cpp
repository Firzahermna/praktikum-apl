#include <iostream>
using namespace std;

// Variabel global bernilai 10
int angka = 10;

void cobaShadow() {
    // Variabel lokal akan menimpa variabel global 'angka'
    int angka = 500;
    cout << "Nilai angka dalam fungsi: " << angka << " (Ini yang lokal)" << endl;
}

int main() {
    cout << "Nilai angka di global: " << angka << " (Ini yang global)" << endl;
    cobaShadow();
    cout << "Nilai angka akhir: " << angka << " (Balik ke global)" << endl;
    return 0;
}