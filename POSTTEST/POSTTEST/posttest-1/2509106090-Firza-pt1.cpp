#include <iostream>
using namespace std;

int main() {

    string nama, password;
    string Nama_Benar = "Firza";
    string NIM_Terakhir = "090";
    int percobaan = 0;
    bool login_berhasil = false;

    while (percobaan < 3) {
        cout << "-----Login Sistem-----" << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "Password: ";
        cin >> password;

        if (nama == Nama_Benar && password == NIM_Terakhir) {
            login_berhasil = true;
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            percobaan++;
            cout << "Nama atau Password salah Gagal login." << endl;
            cout << "Sisa percobaan anda: " << (3 - percobaan) << endl << endl;
        }
    }

    if (!login_berhasil) {
        cout << "coba lagi nanti Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    double nilai;

    do {
        cout << "=== Menu Utama Konversi Panjang ===" << endl;
        cout << "1. Meter -> Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer -> Meter dan Centimeter" << endl;
        cout << "3. Centimeter -> Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan nilai Meter: ";
            cin >> nilai;
            cout << "Hasil: " << nilai / 1000 << " km dan " << nilai * 100 << " cm" << endl;
        } 
        else if (pilihan == 2) {
            cout << "Masukkan nilai Kilometer: ";
            cin >> nilai;
            cout << "Hasil: " << nilai * 1000 << " m dan " << nilai * 100000 << " cm" << endl;
        } 
        else if (pilihan == 3) {
            cout << "Masukkan nilai Centimeter: ";
            cin >> nilai;
            cout << "Hasil: " << nilai / 100 << " m dan " << nilai / 100000 << " km" << endl;
        } 
        else if (pilihan == 4) {
            cout << "Program selesai." << endl;
        } 
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;

    } while (pilihan != 4);
    return 0;
}