#include <iostream>
using namespace std;

int main() {
int panjang = 0; / Jumlah data mahasiswa saat ini
string mahasiswa[MAX_MAHASISWA]; / Array 1 dimensi
int pilihan, index;
do {
cout < "\n = MENU PROGRAM DATA MAHASISWA =" < endl;
cout < "1. Tampilkan Mahasiswa" < endl;
cout < "2. Tambah Mahasiswa" < endl;
cout < "3. Ubah Mahasiswa" < endl;
cout < "4. Hapus Mahasiswa" < endl;
cout < "5. Keluar" < endl;
cout < "Pilihan: ";
cin > pilihan;
switch (pilihan) {