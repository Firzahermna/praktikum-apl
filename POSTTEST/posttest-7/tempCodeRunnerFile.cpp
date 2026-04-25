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