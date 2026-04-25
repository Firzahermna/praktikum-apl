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

#define MAX 2
Gaming daftarGaming[MAX];
int totalData = 0;

void tambahData(Gaming *data, int &total) {
    try {
        if (total >= MAX) {
            throw length_error("Kapasitas penuh!");
        }

        cout << "Masukkan Nama Peralatan Gaming : ";
        cin.ignore();
        getline(cin, (data + total)->nama_peralatan);

        cout << "Masukkan Harga : ";
        cin >> (data + total)->harga;
        if (cin.fail()) throw invalid_argument("Harga harus angka!");

        cout << "Masukkan Stok : ";
        cin >> (data + total)->stok;
        if (cin.fail()) throw invalid_argument("Stok harus angka!");

        total++;
        cout << "Berhasil menambahkan data!\n";
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void lihatData(Gaming *data, int total) {
    if (total == 0) {
        cout << "Data masih kosong\n";
    } else {
        cout << "\n----- Daftar Peralatan Gaming -----\n";
        for (int i = 0; i < total; i++) {
            cout << i + 1 << ". " << (data + i)->nama_peralatan
                << " | Harga: Rp" << (data + i)->harga
                << " | Stok: " << (data + i)->stok << endl;
        }
    }
}

void ubahData(Gaming *data, int total) {
    try {
        if (total == 0) {
            throw runtime_error("Tidak ada data yang bisa diubah.");
        }

        int index;
        lihatData(data, total);
        cout << "Masukkan nomor data yang ingin diubah: ";
        cin >> index;

        if (index <= 0 || index > total) {
            throw out_of_range("Nomor tidak ada!");
        }

        cout << "Masukkan Nama Baru : ";
        cin.ignore();
        getline(cin, (data + index - 1)->nama_peralatan);

        cout << "Masukkan Harga Baru : ";
        cin >> (data + index - 1)->harga;
        if (cin.fail()) throw invalid_argument("Harga harus angka!");

        cout << "Masukkan Stok Baru : ";
        cin >> (data + index - 1)->stok;
        if (cin.fail()) throw invalid_argument("Stok harus angka!");

        cout << "Data berhasil diperbarui!\n";
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

int hapusData(Gaming *data, int total) {
    try {
        if (total == 0) {
            throw runtime_error("Tidak ada data untuk dihapus.");
        }

        int index;
        lihatData(data, total);
        cout << "Masukkan nomor data yang ingin dihapus: ";
        cin >> index;

        if (index <= 0 || index > total) {
            throw out_of_range("Nomor tidak ada!");
        }

        for (int i = index - 1; i < total - 1; i++) {
            *(data + i) = *(data + i + 1);
        }
        total--;

        cout << "Data berhasil dihapus!\n";
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return total;
}

void urutNama(Gaming *data, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
        if ((data + j)->nama_peralatan < (data + j + 1)->nama_peralatan) {
        Gaming temp = *(data + j);
        *(data + j) = *(data + j + 1);
        *(data + j + 1) = temp;
        }
        }
    }
    cout << "Sorting nama berhasil!\n";
}

void urutHarga(Gaming *data, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
        if ((data + j)->harga > (data + j + 1)->harga) {
        Gaming temp = *(data + j);
        *(data + j) = *(data + j + 1);
        *(data + j + 1) = temp;
        }
        }
    }
    cout << "Sorting harga berhasil!\n";
}

void urutStok(Gaming *data, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
        if ((data + j)->stok < (data + j + 1)->stok) {
        Gaming temp = *(data + j);
        *(data + j) = *(data + j + 1);
        *(data + j + 1) = temp;
        }
        }
    }
    cout << "Sorting stok berhasil!\n";
}

void sortHargaAsc(Gaming *data, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
        if ((data + j)->harga > (data + j + 1)->harga) {
        Gaming temp = *(data + j);
        *(data + j) = *(data + j + 1);
        *(data + j + 1) = temp;
        }
        }
    }
}

void cariNama(Gaming *data, int total) {
    try {
        string cari;
        cout << "Masukkan nama peralatan: ";
        cin.ignore();
        getline(cin, cari);

        bool found = false;

    for (int i = 0; i < total; i++) {
    if ((data + i)->nama_peralatan == cari) {
        cout << "Data ditemukan:\n";
        cout << (data + i)->nama_peralatan
            << " | Harga: Rp" << (data + i)->harga
        << " | Stok: " << (data + i)->stok << endl;
        found = true;
    break;
    }
}

        if (!found) {
        throw runtime_error("Data tidak ditemukan");
        }
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void cariHarga(Gaming *data, int total) {
    try {
        int target;
        cout << "Masukkan harga yang dicari: ";
        cin >> target;

        if (cin.fail()) throw invalid_argument("Input harus angka!");

        sortHargaAsc(data, total);

        int low = 0, high = total - 1;
        bool found = false;

        while (low <= high) {
        int mid = (low + high) / 2;

        if ((data + mid)->harga == target) {
            cout << "Data ditemukan:\n";
            cout << (data + mid)->nama_peralatan
            << " | Harga: Rp" << (data + mid)->harga
            << " | Stok: " << (data + mid)->stok << endl;
            found = true;
            break;
            } else if ((data + mid)->harga < target) {
            low = mid + 1;
            } else {
            high = mid - 1;
            }
        }

        if (!found) throw runtime_error("Data tidak ditemukan");
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

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
            cout << "Selamat datang! bos besarku, " << input_nama << endl;
            break;
        } else {
            percobaan++;
            cout << "Nama atau Password salah, sisa percobaan: " << 3 - percobaan << endl << endl;
        }
    }

    if (!login_berhasil) {
        cout << "Telah gagal login 3 kali.\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n===== MENU UTAMA TOKO PERALATAN GAMING =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Lihat Data\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Urutkan nama Z-A\n";
        cout << "6. Urutkan Harga Murah-Mahal\n";
        cout << "7. Urutkan Stok dari yang Terbanyak\n";
        cout << "8. Cari Nama \n";
        cout << "9. Cari Harga \n";
        cout << "10. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        try {
            if (cin.fail()) throw invalid_argument("Input menu harus angka!");

            switch (pilihan) {
            case 1: tambahData(daftarGaming, totalData);
            break;
            case 2: lihatData(daftarGaming, totalData);
            break;
            case 3: ubahData(daftarGaming, totalData);
            break;
            case 4: totalData = hapusData(daftarGaming, totalData);
            break;
            case 5: urutNama(daftarGaming, totalData); lihatData(daftarGaming, totalData);
            break;
            case 6: urutHarga(daftarGaming, totalData); lihatData(daftarGaming, totalData);
            break;
            case 7: urutStok(daftarGaming, totalData); lihatData(daftarGaming, totalData);
            break;
            case 8: cariNama(daftarGaming, totalData);
            break;
            case 9: cariHarga(daftarGaming, totalData);
            break;
            case 10: cout << "Terima kasih telah berbelanja!\n";
            break;
            default: throw out_of_range("Pilihan tidak ada!");
            }
        }
        catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (pilihan != 10);

    return 0;
}