#include <iostream>
using namespace std;

string drakor[1000] = {"hospital playlist", "penthouse", "business proposal"};
int jumlah_data = 3;

void login() {
    cout << "masukkan id dan pass" << endl;
    string id_login;
    string pass_login;
    string id = "cecel";
    string pass = "2309106003";
    int attempt = 3;
    while (attempt > 0) {
        cout << "id :  ";
        getline(cin, id_login);
        cout << "pass : ";
        getline(cin, pass_login);
        if (id_login == id && pass_login == pass) {
            cout << "Berhasil login!" << endl;
            return;
        }
        else {
            cout << "id atau pass salah!" << endl;
            attempt--;
            cout << "Tersisa : " << attempt << endl << endl;
            if (attempt == 0) {
                cout << "anda di kick ! ";
                exit(0);
            }
        }
    }
}

int main() {
    login();
    int pilih;
    string judul = "welcome to gudang drakor";
    while (true) {
        cout << judul << endl;
        cout << "list menu" << endl;
        cout << "1. add new drakor" << endl;
        cout << "2. list drakor" << endl;
        cout << "3. update drakor" << endl;
        cout << "4. delete drakor" << endl;
        cout << "5. exit" << endl;
        cout << "masukkan pilihan : ";
        cin >> pilih;
        cin.ignore(); // untuk membersihkan buffer dari karakter newline
        if (pilih == 1) {
            cout << "add drakor" << endl;
            string ulang;
            do {
                cout << "Masukkan data : ";
                getline(cin, drakor[jumlah_data]);
                jumlah_data++;
                cout << "apakah ingin menambah lagi? (y/n) : ";
                cin >> ulang;
                cin.ignore(); // membersihkan buffer setelah menerima input ulang
            } while (ulang == "y");
        }
        else if (pilih == 2) {
            cout << "list drakor" << endl;
            for (int i = 0; i < jumlah_data; i++) {
                cout << "drakor ke-" << i + 1 << " = " << drakor[i] << endl;
            }
        }
        else if (pilih == 3) {
            int ubah;
            cout << "ubah data drakor" << endl;
            for (int i = 0; i < jumlah_data; i++) {
                cout << "drakor ke-" << i + 1 << " = " << drakor[i] << endl;
            }
            cout << "Masukkan nomor yang ingin diubah : ";
            cin >> ubah;
            cin.ignore(); // untuk membersihkan buffer dari karakter newline
            cout << "Masukkan nama drakor baru : ";
            getline(cin, drakor[ubah - 1]);
        }
        else if (pilih == 4) {
            int hapus;
            string ulang; // inisialisasi ulang di sini
            do {
                cout << "hapus drakor : ";
                cin >> hapus;
                cin.ignore(); // untuk membersihkan buffer dari karakter newline
                if (hapus >= 1 && hapus <= jumlah_data) {
                    for (int i = hapus - 1; i < jumlah_data - 1; i++) {
                        drakor[i] = drakor[i + 1];
                    }
                    jumlah_data--;
                }
                else {
                    cout << "Nomor tidak valid" << endl;
                }
                cout << "ingin menghapus lagi? (y/n) : ";
                cin >> ulang;
            } while (ulang == "y");
        }
        else if (pilih == 5) {
            cout << "program selesai...";
            break;
        }
        else {
            cout << "inputan tidak ada ";
        }
    }
    return 0;
}