#include <iostream>
using namespace std;

struct User {
    string username;
    string password;
};

struct Gaming {
    string nama_peralatan;
    int harga;
    int stok;
};

#define MAX 100
Gaming daftarGaming[MAX];
int totalData = 0;

int main() {
    User admin = {"Firza","090"};
    string input_nama, input_pw;
    int percobaan = 0;
    bool login_berhasil = false;

while (percobaan < 3) {
    cout << "-------LOGINKAN DOLO-------" << endl;
    cout << "Masukkan Nama: ";
    cin >> input_nama;
    cout << "Masukkan Password: ";
    cin >> input_pw;

if (input_nama == admin.username && input_pw == admin.password) {
    login_berhasil = true;
        cout << "Selamat datang! bos besarku, " << input_nama << "." << endl;
        break;
    } 
    else {
        percobaan++;
        cout << "Nama atau Password salah batas percobaan sisa: " << 3 - percobaan << endl << endl;
    }
    }

if (!login_berhasil) {
    cout << "telah gagal login 3 kali. cobalagi nanti ya." << endl;
    return 0;
}

    int pilihan, index;

do {
    cout << "\n===== MENU UTAMA TOKO PERALATAN GAMING =====" << endl;
    cout << "1. Tambah Data Peralatan Gaming" << endl;
    cout << "2. Lihat Daftar Peralatan Gaming" << endl;
    cout << "3. Ubah Data Peralatan Gaming" << endl;
    cout << "4. Hapus Data Peralatan Gaming" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu (1-5): ";
    cin >> pilihan;

    switch (pilihan) {

    case 1:
        if (totalData < MAX) {
            cout << "Masukkan Nama Peralatan Gaming : ";
            cin.ignore();
            getline(cin, daftarGaming[totalData].nama_peralatan);

            cout << "Masukkan Harga : ";
            cin >> daftarGaming[totalData].harga;

            cout << "Masukkan Stok : ";
            cin >> daftarGaming[totalData].stok;

        totalData++;
        cout << "Berhasil menambahkan" << endl;
    } 
        else {
        cout << "Kapasitasnya penuh" << endl;
    }
        break;

    case 2:
        if (totalData == 0) {
            cout << "Data masih kosong" << endl;
    }
        else {
            cout << "\n----- Daftar Peralatan Gaming -----" << endl;
            for (int i = 0; i < totalData; i++) {
            cout << i + 1 << ". " << daftarGaming[i].nama_peralatan
                        << " | Harga: Rp" << daftarGaming[i].harga
                        << " | Stok: " << daftarGaming[i].stok << endl;
            }
    }
                break;

    case 3:
        if (totalData == 0) {
            cout << "Tidak ada data yang bisa di ubah." << endl;
        }
        else {
            cout << "\n----- Daftar Peralatan Gaming -----" << endl;

        for (int i = 0; i < totalData; i++) {
        cout << i + 1 << ". " << daftarGaming[i].nama_peralatan
                << " | Harga: Rp" << daftarGaming[i].harga
                << " | Stok: " << daftarGaming[i].stok << endl;
    }

    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> index;

    if (index > 0 && index <= totalData) {
        cout << "Masukkan Nama Baru : ";
        cin.ignore();
        getline(cin, daftarGaming[index - 1].nama_peralatan);

        cout << "Masukkan Harga Baru : ";
        cin >> daftarGaming[index - 1].harga;

        cout << "Masukkan Stok Baru : ";
        cin >> daftarGaming[index - 1].stok;

    cout << "Data berhasil diperbarui!" << endl;
    }
    else {
cout << "Nomor tidak ada" << endl;
    }
}
        break;

    case 4:
        if (totalData == 0) {
            cout << "Tidak ada data untuk dihapus." << endl;
        } 
    else {
        cout << "\n----- Daftar Peralatan Gaming -----" << endl;

    for (int i = 0; i < totalData; i++) {
            cout << i + 1 << ". " << daftarGaming[i].nama_peralatan
        << " | Harga: Rp" << daftarGaming[i].harga
        << " | Stok: " << daftarGaming[i].stok << endl;
    }

    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> index;

    if (index > 0 && index <= totalData) {

    for (int i = index - 1; i < totalData - 1; i++) {
        daftarGaming[i] = daftarGaming[i + 1];
    }

    totalData--;
        cout << "Data berhasil dihapus!" << endl;
        } 
        else {
        cout << "Nomor tidak ada" << endl;
        }
    }
        break;

    case 5:
            cout << "Terima kasih telah berbelanja digeming store terbaik lah." << endl;
            break;

        default:
            cout << "nomor tidak ada" << endl;
        }

} while (pilihan != 5);

return 0;
}
