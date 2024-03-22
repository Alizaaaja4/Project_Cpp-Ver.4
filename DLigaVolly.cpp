/*
Fitur program (file.txt)
-> Admin
- login username dan pass
- add daftar tim
- melihat daftar tim
- update informasi tim
- add jadwal pertandingan
- delate jadwal pertandingan
- delate tim

-> Public
- searching tim (untuk informasi)
- lihat jadwal pertandingan tim
- melihat ranking klasmen tim

*/

#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>

using namespace std;

void baper();
void log_admin();
void dash_admin();
void add_team();
void view_team();
void delate_team();
void upd_team();
void add_jadwal_team();
void view_jadwal_team();
void delate_jadwal_team();

void dash1_public();
void regis_public();
void log_public();
void view_jadwal_public();
void view_rank_public();
void search_public();

struct items{
    // untuk nomor data entry
    int pk;

    // for login admin
    char uname[30], pass[30];

    // for team
    string nama, pelatih, pemain, rangking, informasi;

    // for jadwal
    string lokasi, jadwal, waktu, nama_club, hasil;

    string cari;
}; items its;

void add_team() {
    string pilih;
    ofstream data_team("data_team.txt", ios::app); // Membuka file untuk penulisan data (mode append)

    if (data_team.is_open()) {
        cout << "-------------------------- D'LIGAVOLLY ------------------------" << endl;
        cout << "--------------------- MENU INPUT DATA TEAM --------------------" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Tim Volly    : "; getline(cin, its.nama);
        cout << "Rangking VPGA: "; getline(cin, its.rangking);
        cout << "Nama Pelatih : "; getline(cin, its.pelatih);
        cout << "Jumlah Pemain: "; getline(cin, its.pemain);
        cout << "Informasi Tim: "; getline(cin, its.informasi);
        cout << "---------------------------------------------------------------" << endl;

        // Menulis data ke dalam file
        data_team << its.nama << " | " << its.rangking << " | " << its.pelatih << " | " << its.pemain << " | " << its.informasi << endl;

        // Menutup file setelah selesai penulisan
        data_team.close();
        cout << "\t\t\tData sedang dimasukan"<< endl; sleep(5);
        cout << "\t\t    Data tim berhasil ditambahkan." << endl << endl;
        cout << "\t  Apakah anda ingin memasukan data lagi (y/n): "; cin >> pilih;

        if(pilih == "Y" || pilih == "y"){
            cout << "\033[2J\033[1;1H"; cin.ignore(); add_team();
        } else if(pilih == "N" || pilih == "n"){
            dash_admin();
        } else{
            cout << "\033[2J\033[1;1H";
            cout << endl << "Maaf option ada tidak terdekteksi!!" << endl; sleep(3);
            dash_admin();
        }
    } else {
        cout << "Gagal membuka file untuk menulis data." << endl; sleep(4); dash_admin();
    }
}

void view_team() {
    string menu;
    ifstream data_team("data_team.txt"); 

    if (data_team.is_open()) {
        string line;
        int nomor = 1; 

        cout << "-------------------------- DAFTAR TIM --------------------------" << endl;
        cout << " No | Nama Team | Nama Pelatih | Jumlah Pemain | Informasi Team |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        while (getline(data_team, line)) {
            cout <<  nomor << ". " << line << endl; 
            nomor++; 
        }
        cout << "-----------------------------------------------------------------" << endl << endl;
        data_team.close(); 

        cout << "\t\t Kembali ke menu utama (y/n) ? "; cin >> menu;
        if (menu == "Y" || menu == "y"){
            cout << "\033[2J\033[1;1H"; cin.ignore(); dash_admin();
        } else if (menu == "N" || menu == "n"){
            cout << "\033[2J\033[1;1H"; cin.ignore();view_team();
        } else {
            cout << "\t\t   Pilihan anda tidak ada!!"; sleep(4); cout << "\033[2J\033[1;1H"; cin.ignore();view_team();
        }
    } else {
        cout << "Gagal membuka file untuk membaca data." << endl << endl;
        cout << "Kembali ke menu utama dalam 5 detik" << endl; sleep(5); dash_admin();
    }
}

void upd_team(){
    string menu;
    fstream data_team("data_team.txt");

    if (data_team.is_open()) {
        string line;
        int nomor = 1;

        cout << "-------------------------- DAFTAR TIM --------------------------" << endl;
        cout << " No | Nama Team | Nama Pelatih | Jumlah Pemain | Informasi Team |" << endl;
        cout << "----------------------------------------------------------------" << endl;

        while (getline(data_team, line)) {
            cout << nomor << ". " << line << endl;
            nomor++;
        }

        data_team.close();

        int nomor_tim;
        cout << endl << "Pilih nomor tim yang ingin Anda edit: ";
        cin >> nomor_tim;

        data_team.open("data_team.txt", ios::out | ios::in);

        if (data_team.is_open()) {
            // Menghitung nomor baris tim yang dipilih
            int baris_tim = 1;
            while (baris_tim < nomor_tim) {
                getline(data_team, line);
                baris_tim++;
            }
            cout << "Loading...." << endl << endl;sleep(3); 
            cin.ignore();
            cout << endl << "Masukkan data baru untuk tim ini:" << endl << endl;
            cout << "Tim Volly    : "; getline(cin, its.nama);
            cout << "Rangking VPGA: "; getline(cin, its.rangking);
            cout << "Nama Pelatih : "; getline(cin, its.pelatih);
            cout << "Jumlah Pemain: "; getline(cin, its.pemain);
            cout << "Informasi Tim: "; getline(cin, its.informasi);

            data_team.seekp(0, ios::beg);
            for (int i = 1; i < baris_tim; i++) {
                getline(data_team, line);
            }
            data_team << its.nama << " | " << its.rangking << " | " << its.pelatih << " | " << its.pemain << " | " << its.informasi << endl;

            data_team.close();

            cout << endl << "\t\t\tData sedang dimasukan"<< endl; sleep(5);
            cout << "\t\t    Data tim berhasil ditambahkan." << endl << endl; sleep(3);
            cout << "\t\t    Kembali ke menu utama (y/n) ? "; cin >> menu;
            if (menu == "Y" || menu == "y"){
                cout << "\033[2J\033[1;1H"; cin.ignore(); dash_admin();
            } else if (menu == "N" || menu == "n"){
                cout << "\033[2J\033[1;1H"; cin.ignore(); upd_team();
            } else{
                cout << "\t\t   Pilihan anda tidak ada!!"; sleep(4); cout << "\033[2J\033[1;1H"; cin.ignore();upd_team();
            }
        } else {
            cout << "Gagal membuka file untuk membaca data." << endl << endl;
            cout << "Kembali ke menu utama dalam 5 detik" << endl; sleep(5); dash_admin();
        }
    } else {
        cout << "Gagal membuka file untuk membaca data." << endl << endl;
        cout << "Kembali ke menu utama dalam 5 detik" << endl; sleep(5); dash_admin();
    }
}

void delate_team(){
    string menu;
    ifstream data_team("data_team.txt");
    
    if (data_team.is_open()) {
        string line;
        int nomor = 1;

        cout << "-------------------------- DAFTAR TIM --------------------------" << endl;
        cout << " No | Nama Team | Nama Pelatih | Jumlah Pemain | Informasi Team |" << endl;
        cout << "----------------------------------------------------------------" << endl;

        while (getline(data_team, line)) {
            cout << nomor << ". " << line << endl;
            nomor++;
        }

        data_team.close();

        int nomor_tim;
        cout << endl << "Pilih nomor tim yang ingin Anda hapus: ";
        cin >> nomor_tim;

        ifstream in("data_team.txt");
        ofstream temp_file("temp_team.txt");

        if (temp_file.is_open() && in.is_open()) {
            int baris_tim = 1;

            while (getline(in, line)) {
                if (baris_tim != nomor_tim) {
                    temp_file << line << endl;
                }
                baris_tim++;
            }

            temp_file.close();
            in.close();

            remove("data_team.txt");
            rename("temp_team.txt", "data_team.txt");
            
            sleep(3);
            cout << endl << "\t\t    Data tim berhasil dihapus." << endl;
            cout << "\t\t   Kembali ke menu utama (y/n) ? "; cin >> menu;
            if (menu == "Y" || menu == "y"){
                cout << "\033[2J\033[1;1H"; cin.ignore(); dash_admin();
            } else if (menu == "N" || menu == "n"){
                cout << "\033[2J\033[1;1H"; cin.ignore(); view_team();
            } else{
                cout << "\t\t   Pilihan anda tidak ada!!"; sleep(4); cout << "\033[2J\033[1;1H"; cin.ignore();dash_admin();
            }
        } else {
            cout << "Gagal membuka file untuk membaca data." << endl << endl;
            cout << "Kembali ke menu utama dalam 5 detik" << endl; sleep(5); dash_admin();
        }
    } else {
        cout << "Gagal membuka file untuk membaca data." << endl << endl;
            cout << "Kembali ke menu utama dalam 5 detik" << endl; sleep(5); dash_admin();
    }
}

void add_jadwal_team(){
    string pilih;
    ofstream data_jadwal("data_jadwal.txt", ios:: app);

    if(data_jadwal.is_open()){
        cout << "-------------------------- D'LIGAVOLLY ------------------------" << endl;
        cout << "----------------  MENU INPUT JADWAL PERTANDINGAN --------------" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Nama Club          : "; getline(cin, its.nama_club);
        cout << "Lokasi Pertandingan: "; getline(cin, its.lokasi);
        cout << "Jadwal Pertandingan: "; getline(cin, its.jadwal);
        cout << "Waktu Dimulai      : "; getline(cin, its.waktu);
        cout << "Hasil Pertandingan : "; getline(cin, its.hasil);
        cout << "---------------------------------------------------------------" << endl;

        data_jadwal << its.nama_club << " | " << its.lokasi << " | " << its.jadwal << " | " << its.waktu << " | " << its.hasil << endl;

        data_jadwal.close();
        cout << "\t\t\tData sedang dimasukan"<< endl; sleep(5);
        cout << "\t\t    Jadwal berhasil ditambahkan." << endl << endl;
        cout << "\t  Apakah anda ingin memasukan data lagi (y/n): "; cin >> pilih;

        if(pilih == "Y" || pilih == "y"){
            cout << "\033[2J\033[1;1H"; cin.ignore(); add_jadwal_team();
        } else if(pilih == "N" || pilih == "n"){
            dash_admin();
        } else{
            cout << "\033[2J\033[1;1H";
            cout << endl << "Maaf option ada tidak terdekteksi!!" << endl; sleep(3);
            dash_admin();
        }
    } else {
        cout << "Gagal membuka file untuk menulis data." << endl; sleep(4); dash_admin();
    }
}

void view_jadwal_team(){
    string pilih;
    ifstream data_jadwal("data_jadwal.txt");

    if(data_jadwal.is_open()){
        string line;
        int nomor = 1;

        cout << "-------------------------- DAFTAR JADWAL PERTANDINGAN --------------------------" << endl;
        cout << " No | Nama Team |   Lokasi Pertandingan  |   Jadwal   |   Waktu   |   Hasil   |" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        while(getline(data_jadwal, line)){
            cout << nomor << ". " << line << endl;
            nomor++;
        }
        cout << "--------------------------------------------------------------------------------" << endl;
        data_jadwal.close();

        cout << "\t\t Kembali ke menu utama (y/n) ? "; cin >> pilih;
        if (pilih == "Y" || pilih == "y"){
            cout << "\033[2J\033[1;1H"; cin.ignore(); dash_admin();
        } else if (pilih == "N" || pilih == "n"){
            cout << "\033[2J\033[1;1H"; cin.ignore();view_jadwal_team();
        } else {
            cout << "\t\t   Pilihan anda tidak ada!!"; sleep(4); cout << "\033[2J\033[1;1H"; cin.ignore();view_jadwal_team();
        }
    }else {
        cout << "Gagal membuka file untuk membaca data." << endl << endl;
        cout << "Kembali ke menu utama dalam 5 detik" << endl; sleep(5); dash_admin();
    }
}

void dash_admin(){
    string menu;
    cout << "\033[2J\033[1;1H";
    cout << "-------------------------- D'LIGAVOLLY ------------------------" << endl;
    cout << "---------------------- MENU ADMINISTRATOR ---------------------" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "----------           [A]. Input Data Team            ----------" << endl;
    cout << "----------           [B]. Review Data Team           ----------" << endl;
    cout << "----------           [C]. Delate Data Team           ----------" << endl;
    cout << "----------           [D]. Update Data Team           ----------" << endl;
    cout << "----------           [E]. Input Jadwal               ----------" << endl;
    cout << "----------           [F]. Review Jadwal              ----------" << endl;
    cout << "----------           [G]. Delate Jadwal              ----------" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "----------           [Z]. Logout                     ----------" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "---------                Input Option                ----------" << endl;
    cout << "                            /> "; cin >> menu;
    cout << "---------------------------------------------------------------" << endl;

    if (menu == "A" || menu == "a"){
        cout << "\033[2J\033[1;1H"; cin.ignore();add_team();
    } else if (menu == "B" || menu == "b"){
        cout << "\033[2J\033[1;1H"; cin.ignore();view_team();
    } else if (menu == "C" || menu == "c"){
        cout << "\033[2J\033[1;1H"; cin.ignore();delate_team();
    } else if (menu == "D" || menu == "d"){
        cout << "\033[2J\033[1;1H"; cin.ignore();upd_team();
    } else if (menu == "E" || menu == "e"){
        cout << "\033[2J\033[1;1H"; cin.ignore();add_jadwal_team();
    } else if (menu == "F" || menu == "f"){
        cout << "\033[2J\033[1;1H"; cin.ignore(); view_jadwal_team();
    } else if (menu == "G" || menu == "g"){
        // kondisi 7
    } else if (menu == "Z" || menu == "z"){
        // kondisi 9
    } else {
        cout << "\033[2J\033[1;1H";
        cout << endl << "Maaf option ada tidak terdekteksi!!" << endl; sleep(3);
        dash_admin();
    }
}

void log_admin(){
    cout << "-------------------------- D'LIGAVOLLY ------------------------" << endl;
    cout << " --------------------- LOGIN ADMINISTRATOR ---------------------" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "\t\t     Username: "; cin >> its.uname;
    cout << "\t\t     Password: "; cin >> its.pass;
    cout << "---------------------------------------------------------------" << endl << endl;
    cout << "\t\t\tProses Verifikasi...." << endl; sleep(3);

    if(strcmp(its.uname, "vollydaskom")== 0 && strcmp(its.pass, "2424")==0){
        cout << "\t\t\t  Login Success!!" << endl; sleep(3); dash_admin();
    } else {
        cout << "\t\t\t  Login failed!!" << endl; sleep(3); log_admin();
    }
}

void baper(){
    cout << "-------------------------- D'LIGAVOLLY ------------------------" << endl;
    cout << " --- A simple practice project to deepen your understanding ---" << endl;
    cout << " --- of C++ programming by building a user-friendly app     ---" << endl;
    cout << "---------------------------------------------------------------" << endl;
}

int main (){
    int menu;

    cout << "\033[2J\033[1;1H";
    cout << endl;
    baper();
    cout << ("\t\t       [1]. D'Liga Admin") << endl;
    cout << ("\t\t       [2]. D'Liga Public") << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "\t\t\t    /> "; cin >> menu;

    switch(menu){
        case 1: cout << "\033[2J\033[1;1H";
                log_admin(); break;
        
        case 2: cout << "\033[2J\033[1;1H";
                break;
        
        default: cout << "\033[2J\033[1;1H";
             cout << endl << "Maaf option ada tidak terdekteksi!!" << endl; sleep(3);
             main(); 
    }
    return 0;
}

