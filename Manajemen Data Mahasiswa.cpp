#include <iostream> //standar input output : cout, cin, endl
#include <fstream>  //header untuk operasi file
#include <algorithm> //untuk menggunakan fungsi sort()
#include <windows.h> // untuk menggunakan fungsi system : cls, color, Sleep 

using namespace std; //menggunakan namespace std = std::cout dll

int main(); //deklarari fungsi main
void Login(); //deklarari fungsi Login
void Loading(); //deklarari fungsi Loading
void Loading2(); //deklarari fungsi Loading2
void Add(); //deklarari fungsi Add
void Edit(); //deklarari fungsi Edit
void Show(int Jumlah_Data); //deklarari fungsi Show dengan parameter (int Jumlah_Data)
void Sorting(); //deklarari fungsi Sorting
void Search(); //deklarari fungsi Search
void Print(); //deklarari fungsi Print
void Print_Save(); //deklarari fungsi Print_Save
void Clear(); //deklarari fungsi Clear
void Recycle(); //deklarari fungsi Recycle
void Recovery(); //deklarari fungsi Recovery
bool Full(); //deklarari fungsi Full
bool Empty(); //deklarari fungsi Empty
bool Empty_Recycle(); //deklarari fungsi Empty_Recycle
void gotoxy(int x, int y); //deklarari fungsi gotoxy

//deklarasi variabel global

int Jumlah_Data = 0; 
int Simpan_Data;
int Data_Sementara;
int pilih = 0;
int cari;
int i;
string userName;
string userPassword;
int loginAttempt = 0;

struct data // struct untuk menyimpan data mhs
{
    //deklarasi variabel
    string npm;
    string nama_akhir;
    string nama;
    string kelas;
    string fkp;
    string ttl;
    string alamat;
    string hp;
};
data mhs[5]; //array mhs berjumlah 5 (0,1,2,3,4)

struct recovery
{
    //deklarasi variabel
    string npm;
    string nama_akhir;
    string nama;
    string kelas;
    string fkp;
    string ttl;
    string alamat;
    string hp;
};
recovery Mahasiswa[5]; //array Mahasiswa berjumlah 5 (0,1,2,3,4)

int main()
{

    bool loop = true; // untuk mengulang menu
    while (loop) //jika loop = true maka akan di eksekusi
    {
        system("Color 05"); // 0 = hitam 5 = ungu
        Login(); //menuju fungsi Login
        if (loginAttempt == 5-1) //jika login attempt == 5-1 
        {
            return loop =false; //mengembalikan nilai loop menjadi false, dan akan langsung keluar program
        }
        Loading(); //menuju fungsi Loading
        system("Color 06");  //untuk merubah warna indeks pertama = background, indeks kedua = Teks
        //0 = HITAM 6 = KUNING
    kembali: //fungsi goto kembali

        // Tampilan Menu
        cout << "Manajemen Data Mahasiswa Universitas Pakuan"<< endl;
        cout << "===========================================\n"<<endl;
        cout << "1. Masukkan Data Mahasiswa" << endl;
        cout << "2. Edit Data" << endl;
        cout << "3. Lihat Data" << endl;
        cout << "4. Urutkan Data" << endl;
        cout << "5. Cari Data" << endl;
        cout << "6. Print Data" << endl;
        cout << "7. Hapus Semua Data" << endl;
        cout << "8. Recycle Bin" << endl;
        cout << "9. Recovery Data" << endl;
        cout << "10. Keluar" << endl;
        cout << endl;

        cout << "Masukkan Pilihan Anda : ";
        cin >> pilih; // masukkan pilih

        cout << endl;

        switch (pilih) // switch untuk kondisi pilih
        {
        case 1:
            Add();          // menuju fungsi Add
            cout << "\n\n"; // garis baru dua kali
            goto kembali;   // melakukan pengulangan pada menu
            break; //menghentikan kode agar tidak lanjut ke case selanjutnya

        case 2:
            Edit(); // menuju fungsi Edit
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;

        case 3:
            Show(Jumlah_Data); // menuju fungsi Show dengan parameter (Jumlah_Data)
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;

        case 4:
            Sorting(); // menuju fungsi Sorting
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;
        case 5:
            Search(); // menuju fungsi Search
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;
        case 6:
            Print(); // menuju fungsi Print
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;
        case 7:
            Clear(); // menuju fungsi Clear
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;
        case 8:
            Recycle(); // menuju fungsi Recycle
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;
        case 9:
            Recovery(); // menuju fungsi recovery
            cout << "\n\n";// garis baru dua kali
            goto kembali;
            break;
        case 10:
            system("cls"); //menutup system

            Loading2(); //menuju fungsi Loading2
            gotoxy(70, 22); //menuju fungsi gotoxy (x,y)
            cout << "Thanks for Using this Program" << endl;
            gotoxy(75, 23); //menuju fungsi gotoxy (x,y)
            cout << "Copyright@Run&Debug\n"<< endl;
            gotoxy(70,24); //menuju fungsi gotoxy (x,y)
            loop = false; // mengubah nilai loop agar menjadi false, pengulangan tak akan dilakukan

            break;

        default: // input bukan dari 1-10 maka ini akan dieksekusi
            cout << " Input yang Anda Masukkan Salah !" << endl;
            goto kembali;
            break;
        }
    }
}

void Login() //untuk login
{
    while (loginAttempt < 5) //disaat LoginAttempt <5 
    {
    ulang:
        //masukkan username
        gotoxy(65,25);
        cout << "Please Enter Your Username: "; 
        cin >> userName;

        //jika loginAttempt == 5-1 
        if (loginAttempt == 5 - 1)
        {
            gotoxy(52,27);
            cout << "Too Many Login Attempts! The Program Will Now Terminate.\n";
            gotoxy(65,28);
            return ;
        }

        //jika username benar kode dibawah akan dieksekusi
        if (userName == "Admin")
        {
            
            goto password; //fungsi goto 
            break;
        }
        //jika username salah maka kode dibawah akan dieksekusi
        else
        {
            gotoxy(60,26);
            cout << "Invalid login attempt. Please try again.\n" 
                 << '\n';
            gotoxy(65,27);
            system("pause");
            system("cls");
            loginAttempt++; //loginAttempt ditambah 1
            goto ulang;
        }

    password:

        //password
        gotoxy(65,26);
        cout << "Please Enter Your Password: ";
        cin >> userPassword;

        //jika password benar maka akan dieksekusi
        if (userPassword == "Pakuan")
        {
            gotoxy(70,27);
            cout << "Congrats, Log in Success\n";
            gotoxy(65,29);
            system("pause");
            system("cls");
            break;
        }
        //jika password salah maka akan dieksekusi
        else
        {
            gotoxy(60,27);
            cout << "Invalid Login Attempt. Please Try Again.\n"
                 << '\n';
            gotoxy(65,28);
            system("pause");
            system("cls");
            loginAttempt++; //loginAttempt ditambah 1
            goto ulang;
        }
    }
}

void Loading() //untuk menampilkan loading
{

    int a;

    for (a = 0; a <= 100; a++)
    {

        gotoxy(75, 25);

        cout << "Now Loading.." << a << "%";

        

        if (a < 5)
            
            Sleep(100); //akan delay sebesar 100ms

        if (a < 50)
        
            Sleep(75); //akan delay sebesar 75ms

        if (a < 90)
            
            Sleep(25); //akan delay sebesar 25ms

        if (a <= 100)
            
            Sleep(35); //akan delay sebesar 35ms

        system("cls");
    }
}

void Loading2() //untuk menampilkan loading
{

    int a;

    for (a = 0; a <= 100; a++)
    {

        gotoxy(75, 25);

        cout << "Exit Program.." << a << "%";

        if (a < 5)
            Sleep(50); //akan delay sebesar 50ms

        if (a < 50)
            Sleep(35); //akan delay sebesar 35ms

        if (a < 90)
            Sleep(10); //akan delay sebesar 10ms

        if (a <= 100)
            Sleep(25); //akan delay sebesar 25ms

        system("cls");
    }
}

void Add() //untuk menambah data
{
    if (Full()) // jika Full = true maka kode dibawah akan dieksekusi
    {
        cout << "Data Sudah Penuh" << endl;
        return;
    }
    else
    {
        //memasukkan nilai mhs[Jumlah_Data]

        cout << "Masukkan NPM Mahasiswa: ";
        cin.ignore();
        getline(cin, (mhs[Jumlah_Data].npm));
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, (mhs[Jumlah_Data].nama));
        cout << "Masukkan Nama Akhir Mahasiswa: ";
        getline(cin, (mhs[Jumlah_Data].nama_akhir));
        cout << "Masukkan Kelas Mahasiswa: ";
        getline(cin, (mhs[Jumlah_Data].kelas));
        cout << "Masukkan Prodi Mahasiswa: "; // e.g Ilmu Komputer
        getline(cin, (mhs[Jumlah_Data].fkp));
        cout << "Masukkan Tanggal Lahir Mahasiswa(dd/mm/yyyy): ";
        getline(cin, (mhs[Jumlah_Data].ttl));
        cout << "Masukkan Alamat Mahasiswa: ";
        getline(cin, (mhs[Jumlah_Data].alamat));
        cout << "Masukkan No HP Mahasiswa: ";
        cin >> mhs[Jumlah_Data].hp;

        cout << endl;


        Jumlah_Data += 1; //Jumlah_Data = Jumlah_Data + 1
        Simpan_Data = Jumlah_Data; //memasukkan nilai Jumlah_Data ke Simpan_Data
        Print_Save(); //menuju fungsi Print_Save
        cout << "Save Data telah diupdate";
    }
}

void Print_Save()//untuk save otomatis data ke Save Data.txt
{
        ofstream Simpan;                             // open file stream
        //Simpan.open Membuka file
        Simpan.open("Save Data.txt", ios::app); // akan dibuatkan file, apabila belum ada. ios::app untuk menulis di file namun tidak menimpa data

        if (Simpan_Data == 1 )
        {
            Simpan << "ID\t\t";
        Simpan << "Npm\t\t\t";
        Simpan << "Nama\t\t\t\t";
        Simpan << "Kelas\t";
        Simpan << "Prodi\t\t\t\t";
        Simpan << "TTL\t\t";
        Simpan << "\t\tAlamat\t";
        Simpan << "\tNo HP\n\n";

        Simpan << Simpan_Data-1 << "\t\t"; //Simpan_Data - 1 agar menyesuaikan dengan array 
        Simpan<< mhs[Simpan_Data-1].npm << "\t";
        Simpan << mhs[Simpan_Data-1].nama << " ";
        Simpan << mhs[Simpan_Data-1].nama_akhir << "\t\t";
        Simpan << mhs[Simpan_Data-1].kelas << "\t\t";
        Simpan << mhs[Simpan_Data-1].fkp << "\t\t"; // e.g Ilmu Komputer
        Simpan << mhs[Simpan_Data-1].ttl << "\t\t";
        Simpan << mhs[Simpan_Data-1].alamat << "\t\t";
        Simpan << mhs[Simpan_Data-1].hp;

        Simpan << endl;

        }
        for (int i = 1 ; i<= Simpan_Data-1;i++)
        {

         if (mhs[i].npm == mhs[Simpan_Data-1].npm) //jika nilai dari mhs[i].npm sama dengan mhs[Simpan_Data-1].npm maka kode dibawah akan dieksekusi
            {
        Simpan << Simpan_Data-1 << "\t\t";
        Simpan<< mhs[Simpan_Data-1].npm << "\t";
        Simpan << mhs[Simpan_Data-1].nama << " ";
        Simpan << mhs[Simpan_Data-1].nama_akhir << "\t\t";
        Simpan << mhs[Simpan_Data-1].kelas << "\t\t";
        Simpan << mhs[Simpan_Data-1].fkp << "\t\t"; // e.g Ilmu Komputer
        Simpan << mhs[Simpan_Data-1].ttl << "\t\t";
        Simpan << mhs[Simpan_Data-1].alamat << "\t\t";
        Simpan << mhs[Simpan_Data-1].hp;

        Simpan << endl;
            }
        }
        
        Simpan.close(); //menutup file
}

void Edit()// untuk melakukan pengeditan data
{
    if (Empty()) // jika Empty = true maka kode dibawah akan dieksekusi
    {
        cout << "Data Masih Kosong!!" << endl;
        return;
    }
    else if (pilih == 2)
    {
        cout << "Masukkan Nomor Data yang Ingin diedit: ";
        cin >> cari;
        for (int i = 0; i < Jumlah_Data; i++)
        {
            if (mhs[i].npm == mhs[cari].npm) //jika nilai dari mhs[i].npm sama dengan mhs[cari].npm maka kode dibawah akan dieksekusi
            { 
                //memasukkan nilai mhs[i]
                cout << "Masukkan NPM Mahasiswa: ";
                cin.ignore();
                getline(cin, (mhs[i].npm));
                cout << "Masukkan Nama Mahasiswa: ";
                getline(cin, (mhs[i].nama));
                cout << "Masukkan Nama Akhir Mahasiswa: ";
                getline(cin, (mhs[i].nama_akhir));
                cout << "Masukkan Kelas Mahasiswa: ";
                getline(cin, (mhs[i].kelas));
                cout << "Masukkan Prodi Mahasiswa: "; // e.g Ilmu Komputer
                getline(cin, (mhs[i].fkp));
                cout << "Masukkan Tanggal Lahir Mahasiswa(dd/mm/yyyy): ";
                getline(cin, (mhs[i].ttl));
                cout << "Masukkan Alamat Mahasiswa: ";
                getline(cin, (mhs[i].alamat));
                cout << "Masukkan No HP Mahasiswa: ";
                cin >> mhs[i].hp;

                cout << endl;
                cout << "Data Telah Diperbarui";
            }
            else if (cari >= Jumlah_Data) //jika cari lebih dari sama dengan Jumlah_Data kode akan dieksekusi
                cout << "Data Tidak Ditemukan";
        }
    }
}

void Show(int Jumlah_Data) //untuk menampilkan data yang ada dengan parameter int Jumlah_Data
{
    if (Empty()) // jika Empty = true maka kode dibawah akan dieksekusi
    {
        cout << "Data Masih Kosong!!" << endl;
        return;
    }
    else
    {
        cout << "ID\t";
        cout << "Npm\t\t";
        cout << "Nama\t\t\t";
        cout << "Kelas\t";
        cout << "Prodi\t\t\t";
        cout << "TTL\t";
        cout << "\t\tAlamat\t";
        cout << "\tNo HP\n\n";

        for (int i = 0; i < Jumlah_Data; i++)
        {
            cout << i << "\t";
            cout << mhs[i].npm << "\t";
            cout << mhs[i].nama << " ";
            cout << mhs[i].nama_akhir << "\t\t";
            cout << mhs[i].kelas << "\t";
            cout << mhs[i].fkp << "\t\t"; // e.g Ilmu Komputer
            cout << mhs[i].ttl << "\t\t";
            cout << mhs[i].alamat << "\t\t";
            cout << mhs[i].hp<<"\n\n";
        }
    }
}

bool Compare(data b1, data b2) //untuk melakukan komparasi data
{
    if (b1.npm < b2.npm)
    {
        return true;
    }
    return false;
}
void Sorting()
{
    sort(mhs, mhs + Jumlah_Data, Compare); // (data,jumlah data yang ada, komparasi)
    cout << "ID\t";
        cout << "Npm\t\t";
        cout << "Nama\t\t\t";
        cout << "Kelas\t";
        cout << "Prodi\t\t\t";
        cout << "TTL\t";
        cout << "\t\tAlamat\t";
        cout << "\tNo HP\n\n";
    for (int i = 0; i < Jumlah_Data; i++)
    {
        cout << i << "\t";
            cout << mhs[i].npm << "\t";
            cout << mhs[i].nama << " ";
            cout << mhs[i].nama_akhir << "\t\t";
            cout << mhs[i].kelas << "\t";
            cout << mhs[i].fkp << "\t\t"; // e.g Ilmu Komputer
            cout << mhs[i].ttl << "\t\t";
            cout << mhs[i].alamat << "\t\t";
            cout << mhs[i].hp<<"\n\n";
    }
}

void Search() //untuk melakukan pencarian
{
    if (Empty()) // jika Empty = true maka kode dibawah akan dieksekusi
    {
        cout << "Data Masih Kosong!!" << endl;
        return;
    }
    else if (pilih == 5)
    {
        cout << "Masukkan Nomor Data: ";
        cin >> cari;
        cout << "ID\t";
        cout << "Npm\t\t";
        cout << "Nama\t\t\t";
        cout << "Kelas\t";
        cout << "Prodi\t\t\t";
        cout << "TTL\t";
        cout << "\t\tAlamat\t";
        cout << "\tNo HP\n\n";
        for (int i = 0; i < Jumlah_Data; i++)
        {
            if (mhs[i].npm == mhs[cari].npm) //jika nilai dari mhs[i].npm sama dengan mhs[cari].npm maka kode dibawah akan dieksekusi
            {
                cout << cari << "\t";
            cout << mhs[cari].npm << "\t";
            cout << mhs[cari].nama << " ";
            cout << mhs[cari].nama_akhir << "\t\t";
            cout << mhs[cari].kelas << "\t";
            cout << mhs[cari].fkp << "\t\t"; // e.g Ilmu Komputer
            cout << mhs[cari].ttl << "\t\t";
            cout << mhs[cari].alamat << "\t\t";
            cout << mhs[cari].hp<<"\n\n";
            }
            else if (cari >= Jumlah_Data) //jika cari lebih dari sama dengan Jumlah_Data maka kode akan dieksekusi
                cout << "Data Tidak Ditemukan";
        }
    }
}

void Print() //untuk print data 
{
    if (Empty()) // jika Empty = true maka kode dibawah akan dieksekusi
    {
        cout << "Data Masih Kosong!!" << endl;
        return;
    }
    else
    {
        // --- menulis ke file
        ofstream Penyimpanan;                             // open file stream
        //Penyimpanan.open untuk membuka file
        Penyimpanan.open("Data Mahasiswa.txt", ios::app); // akan dibuatkan file, apabila belum ada. ios:app untuk menulis file namun tidak akan menimpa data sebelumnya
        
        Penyimpanan << "ID\t\t";
        Penyimpanan << "Npm\t\t\t";
        Penyimpanan << "Nama\t\t\t\t";
        Penyimpanan << "Kelas\t";
        Penyimpanan << "Prodi\t\t\t\t";
        Penyimpanan << "TTL\t\t";
        Penyimpanan << "\t\tAlamat\t";
        Penyimpanan << "\tNo HP\n\n";

        for (int i = 0; i < Jumlah_Data; i++)
        {

            Penyimpanan << i << "\t\t";
            Penyimpanan << mhs[i].npm << "\t";
            Penyimpanan << mhs[i].nama << " ";
            Penyimpanan << mhs[i].nama_akhir << "\t\t";
            Penyimpanan << mhs[i].kelas << "\t\t";
            Penyimpanan << mhs[i].fkp << "\t\t"; // e.g Ilmu Komputer
            Penyimpanan << mhs[i].ttl << "\t\t";
            Penyimpanan << mhs[i].alamat << "\t\t";
            Penyimpanan << mhs[i].hp;

            Penyimpanan << endl;
        }
        Penyimpanan.close(); //Penyimpanan.close untuk menutup file

        cout << "Data Telah Tersimpan, Silahkan Cek Data Mahasiswa.txt" << endl;
    }
}

void Clear() //untuk menghapus semua data
{
    char y;      // variabel y bertipe data char
    if (Empty()) // jika Empty = true maka kode dibawah akan dieksekusi
    {
        cout << "Data Masih Kosong!!" << endl;
        return;
    }
    else
    {
        cout << "Apakah Anda Yakin (y/t) ? : ";
        cin >> y; // input nilai y

        if (y == 'y' || y == 'Y') // jika y = 'y'&&'Y' kode akan dieksekusi
        {
            cout << endl;
            cout << "Data Telah Terhapus" << endl;
            Data_Sementara = Jumlah_Data;
            Jumlah_Data = 0; // mengembalikan nilai jumlah_stack menjadi 0
        }
        else if (y == 't' || y == 'T') // jika y = 't'&&'T' kode akan dieksekusi
        {
            cout << endl;
            cout << "Data Tidak Dihapus" << endl;
        }
        else // jika selain y dan t maka ini akan dieksekusi
        {
            cout << endl;
            cout << "Input Salah" << endl;
        }
    }
}

void Recycle() //untuk dapat mengembalikan data yang terhapus (anggap saja ini Recycle bin)
{
    if (Empty_Recycle()) // jika Empty = true maka kode dibawah akan dieksekusi
    {
        cout << "Belum Ada Data yang dihapus!!" << endl;
        return;
    }
    else
    {

        for (int i = 0; i < Data_Sementara; i++)
        {
            //memasukkan data mhs[i] ke Mahasiswa[i]

            Mahasiswa[i].npm = mhs[i].npm;
            Mahasiswa[i].nama = mhs[i].nama;
            Mahasiswa[i].kelas = mhs[i].kelas;
            Mahasiswa[i].fkp = mhs[i].fkp;
            Mahasiswa[i].ttl = mhs[i].ttl;
            Mahasiswa[i].alamat = mhs[i].alamat;
            Mahasiswa[i].hp = mhs[i].hp;
        }

        cout << "ID\t";
        cout << "Npm\t\t";
        cout << "Nama\t\t\t";
        cout << "Kelas\t";
        cout << "Prodi\t\t\t";
        cout << "TTL\t";
        cout << "\t\tAlamat\t";
        cout << "\tNo HP\n\n";

        for (int i = 0; i < Data_Sementara; i++)
        {
            cout << i << "\t";
            cout << Mahasiswa[i].npm << "\t";
            cout << Mahasiswa[i].nama << " ";
            cout << Mahasiswa[i].nama_akhir << "\t\t";
            cout << Mahasiswa[i].kelas << "\t";
            cout << Mahasiswa[i].fkp << "\t\t"; // e.g Ilmu Komputer
            cout << Mahasiswa[i].ttl << "\t\t";
            cout << Mahasiswa[i].alamat << "\t\t";
            cout << Mahasiswa[i].hp<<"\n\n";
        }
    }
}
void Recovery()
{
    if (Empty_Recycle()) // jika Empty = true maka kode dibawah akan dieksekusi
    {
        cout << "Belum Ada Data yang dihapus!!" << endl;
        return;
    }
    else
    {
        Jumlah_Data = Data_Sementara; //memasukkan nilai Data_Sementara ke Jumlah_Data

        for (int i = 0; i < Data_Sementara; i++)
        {
            //memasukkan nilai Mahasiswa[i] ke mhs[i]
            mhs[i].npm = Mahasiswa[i].npm;
            mhs[i].nama = Mahasiswa[i].nama;
            mhs[i].kelas = Mahasiswa[i].kelas;
            mhs[i].fkp = Mahasiswa[i].fkp;
            mhs[i].ttl = Mahasiswa[i].ttl;
            mhs[i].alamat = Mahasiswa[i].alamat;
            mhs[i].hp = Mahasiswa[i].hp;
        }
        Show(Jumlah_Data); //meuju fungsi Show dengan parameter Jumlah_Data
    }
}

bool Full() // untuk mengecek apakah data penuh atau tidak
{
    if (Jumlah_Data == 5)
    {
        return true; // mengembalikan nilai menjadi true
    }
    else
    {
        return false; // mengembalikan nilai menjadi false
    }
}

bool Empty() // untuk mengecek apakah data kosong atau tidak
{
    if (Jumlah_Data == 0)
    {
        return true; // mengembalikan nilai menjadi true
    }
    else
    {
        return false; // mengembalikan nilai menjadi false
    }
}

bool Empty_Recycle() // untuk mengecek apakah Data_Sementara kosong atau tidak
{
    if (Data_Sementara == 0)
    {
        return true; // mengembalikan nilai menjadi true
    }
    else
    {
        return false; // mengembalikan nilai menjadi false
    }
}

void gotoxy(int x, int y) //untuk melakukan fungsi gotoxy
{
    HANDLE out;
    COORD posisi;
    cout.flush();
    posisi.X = x;
    posisi.Y = y;
    out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, posisi);
}