#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <queue>
#define maxproyek 150
using namespace std;

struct proyek{
    queue<string> sekaligus;
	string listproyek[maxproyek];
	string statusproyek;	
	int penanda_array = 0;
	string listproyeksementara[maxproyek];
}proyek;
struct proyekwip{
	string listproyek[maxproyek];
	string statusproyek;
	int penanda_array = 0;
}proyekwip;
struct proyekfinish{
	string listproyek[maxproyek];
	string statusproyek;
	int penanda_array = 0;
}proyekfinish;
//Untuk tempat menyimpan data akun username dan password
struct akun{
	string username[99];//jono
	string password[99];//123
	int npenanda = 0;
}akuninfo;

void Login(); //Menu Login
void Menu(); //Untuk Menu Utama Pengguna
void ListProyek();
void ListProyekWIP();//untuk list proyek WIP
void ListAntrianProyekAkun();//untuk list proyek antrian User/Akun
void ListProyekFinish();//untuk list proyek finsih
void GantiPassword();

void SearchProyek();
void SortProyek();
void UndoTambahProyek();
void UndoPindahWIP();
void TambahProyekSekaligus();

void SearchProyekWIP();
void SortProyekWIP();
void UndoPindahFinish();

void SearchProyekFinish();
void SortProyekFinish();



void Menu()
{
	int menu_pil;
	system("cls");
	cout << "MENU PROYEK" << endl;
	cout << "Pilih Menu dibawah ini : " << endl;
	cout << "1. List Proyek" << endl;
	cout << "2. List Proyek WIP" << endl;
	cout << "3. List Proyek Finish" << endl;
	cout << "4. Ganti Password Akun/User" << endl;
	cout << "5. Logout" << endl;
	cout << "Masukkan Pilihan [1..6] : ";
	cin >> menu_pil;
	if(menu_pil == 1)
	{
	    ListProyek();
	}
	else if(menu_pil == 2)
	{
		ListProyekWIP();
	}
	else if(menu_pil == 3)
	{
		ListProyekFinish();
	}
	else if(menu_pil == 4)
	{
 		GantiPassword();
	}
	else if(menu_pil == 5)
	{
		Login();
	}
}
void Login()
{
	system("cls");
	int pil;
	string username, password, user_baru, pass_baru, pass_check;
	cout << "LOGIN MENU" << endl;
	cout << "Pilih Menu di Bawah ini : " << endl;
	cout << "1. Log In" << endl;
	cout << "2. Sign Up" << endl;
	cout << "3. Exit" << endl;
	cout << "Menu [1..3] : ";
	cin >> pil;
	if(pil == 1)
	{
		cout << "Masukkan Username : ";
		cin >> username;
		cout << "Masukkan Password : ";
		cin >> password;
		for(int i = 0; i <= akuninfo.npenanda; i++)
		{
			if(username == akuninfo.username[i] && password == akuninfo.password[i])
			{
				cout << "Selamat anda berhasil login!!" << endl;
//				system("cls");
				Menu();
				break;
			}
			else if(i == akuninfo.npenanda && (username != akuninfo.username[i] || password != akuninfo.password[i]))
			{
				cout << "Mohon masukkan username dan password yang benar" << endl;
				sleep(2);
				// system("cls");
				Login();
				break;
			}
		}
	}
	else if(pil == 2)
	{
		cout << "Masukkan Username Baru : ";
		cin >> user_baru;
		cout << "Masukkan Password Baru : ";
		cin >> pass_baru;
		cout << "Masukkan Ulang Password : ";
		cin >> pass_check;
		if(pass_baru == pass_check)
		{
			if(akuninfo.username[0] == "")
			{
			akuninfo.username[0] += user_baru;
			akuninfo.password[0] += pass_baru;
			akuninfo.npenanda++;
			cout << "Selamat akun telah terbuat!!" << endl;
			Login(); 	
			}
			else
			{
			akuninfo.username[akuninfo.npenanda] += user_baru;
			akuninfo.password[akuninfo.npenanda] += pass_baru; 
			akuninfo.npenanda++;
			cout << "Selamat akun telah terbuat!!" << endl;
			Login();
			}

		}
		else
		{
			cout << "Mohon maaf password tidak sama";
		}
	}
}
void data_ada()
{
    string proyeksimpan[5] = {"Pembangunan taman bermain di sebuah kota.", "Pembangunan pusat seni dan budaya komunitas.", "Pembangunan jalan raya baru untuk mengurangi kemacetan.", "Rehabilitasi dan restorasi bangunan bersejarah"};
    for(int i = 0; i < 4; i++)
    {
        proyek.listproyek[i] += proyeksimpan[i];
        proyek.penanda_array++;
        // cout << proyek.penanda_array;
    }
}

void ListProyek()
{
    int nomor = 1;
    int count = 0;
    int pil_menu_lp;
    int proyek_hapus;
    int proyek_WIP;
    int jumlah_data;
    string proyek_sementara;
    string proyek_tambah;
    system("cls");
    cout << "Tampilan List Proyek yang Ada" << endl;
    cout << "=============================" << endl << endl;
    for(int i = 0; i < proyek.penanda_array; i++)
    {
        cout << nomor << ". " << proyek.listproyek[i] << endl;
        nomor++;
    }
    cout << "Pilih Opsi dibawah ini [1..4]" << endl;
    cout << "[1]Tambah Proyek\n[2]Hapus Proyek\n[3]Pindahkan ke WIP\n[4]Search Proyek\n[5]Sort Proyek\n[6]Undo Tambah Proyek\n[7]Undo Pindah WIP\n[8]Kembali\b[9]sekaligus: ";
    cin >> pil_menu_lp;
    if(pil_menu_lp == 1)
    {
        // cout << proyek.penanda_array << endl;
        cout << "Masukkan Proyek Yang Ditambahkan : ";
        cin.ignore();
        getline(cin, proyek_tambah);

        proyek.listproyek[proyek.penanda_array] += proyek_tambah;
        proyek.penanda_array++;
        ListProyek();
        
    }
    else if(pil_menu_lp == 2)
    {
        cout << "Pilih proyek yang akan dihapus [1.." << proyek.penanda_array << "] : ";
        cin >> proyek_hapus;
        for(int i = 0; i < proyek.penanda_array; i++)
        {
         if(proyek_hapus-1 == i)
         {
             proyek.listproyek[i] = "";
             break;
         }
        }
        for(int i = 0; i < proyek.penanda_array; i++)
        {
            if(proyek.listproyek[i] == "")
            {
                proyek.listproyek[i] = proyek.listproyek[i+1];
                proyek.listproyek[i+1] = "";
            }
        }
        proyek.penanda_array--;
        ListProyek();
    }
    else if(pil_menu_lp == 3)
    {
    	cout << "Pilih proyek yang akan dipindah ke WIP [1.." << proyek.penanda_array << "] : ";
        cin >> proyek_WIP;
        for(int i = 0; i < proyek.penanda_array; i++)
        {
         if(proyek_WIP-1 == i)
         {
         	 proyekwip.listproyek[proyekwip.penanda_array] = proyek.listproyek[i];
             proyek.listproyek[i] = "";
             break;
         }
        }
        proyekwip.penanda_array++;
        for(int i = 0; i < proyek.penanda_array; i++)
        {
            if(proyek.listproyek[i] == "")
            {
                proyek.listproyek[i] = proyek.listproyek[i+1];
                proyek.listproyek[i+1] = "";
            }
        }
        proyek.penanda_array--;
        ListProyek();
    }
    else if(pil_menu_lp == 4)
    {
        SearchProyek();
    }
    else if(pil_menu_lp == 5)
    {
        SortProyek();
    }
    else if(pil_menu_lp == 6)
    {
        UndoTambahProyek();
    }
    else if(pil_menu_lp == 7)
    {
        UndoPindahWIP();
    }
    else if(pil_menu_lp == 8)
    {
    	Menu();
    }
    else if(pil_menu_lp == 9)
    {
        TambahProyekSekaligus();
    }
}
void SearchProyek()
{
    string keyword;
    cout << "Masukkan kata kunci: ";
    cin.ignore();
    getline(cin, keyword);

    cout << "Hasil Pencarian Proyek:" << endl;
    bool found = false;
    for (int i = 0; i < proyek.penanda_array; i++)
    {
        if (proyek.listproyek[i].find(keyword) != string::npos)
        {
            cout << i + 1 << ". " << proyek.listproyek[i] << endl;
            found = true;
            getchar();
            ListProyek();
        }
    }

    if (!found)
    {
        cout << "Proyek tidak ditemukan." << endl;
        getchar();
        ListProyek();
    }
}
void SortProyek()
{
    for (int i = 0; i < proyek.penanda_array - 1; i++)
    {
        for (int j = 0; j < proyek.penanda_array - i - 1; j++)
        {
            if (proyek.listproyek[j] > proyek.listproyek[j + 1])
            {
                string temp = proyek.listproyek[j];
                proyek.listproyek[j] = proyek.listproyek[j + 1];
                proyek.listproyek[j + 1] = temp;
            }
        }
    }

    // Menampilkan list proyek yang telah diurutkan
    cout << "List Proyek setelah diurutkan:" << endl;
    for (int i = 0; i < proyek.penanda_array; i++)
    {
        cout << i + 1 << ". " << proyek.listproyek[i] << endl;
    }
    getchar();
    ListProyek();
}
void UndoTambahProyek()
{
    if (proyek.penanda_array > 0)
    {
        proyek.listproyek[proyek.penanda_array - 1] = "";
        proyek.penanda_array--;
        cout << "Proyek terakhir yang ditambahkan berhasil dihapus." << endl;
    }
    else
    {
        cout << "Tidak ada proyek yang dapat dihapus." << endl;
    }
    getchar();
    ListProyek();
}
void UndoPindahWIP()
{
    if (proyekwip.penanda_array > 0)
    {
        int proyek_terakhir = proyekwip.penanda_array - 1;
        proyek.listproyek[proyek.penanda_array] = proyekwip.listproyek[proyek_terakhir];
        proyek.penanda_array++;
        proyekwip.listproyek[proyek_terakhir] = "";
        proyekwip.penanda_array--;

        cout << "Proyek berhasil di-undo dan dikembalikan ke List Proyek WIP." << endl;
    }
    else
    {
        cout << "Tidak ada proyek yang bisa di-undo pada List Proyek Finish." << endl;
    }

    getchar();
    ListProyek();
}
void TambahProyekSekaligus() {
    int jumlah_data;
    cout << "Berapa banyak data yang ingin dimasukkan sekaligus? : ";
    cin >> jumlah_data;

    cin.ignore(); // Membersihkan newline character dari buffer

    for (int i = 0; i < jumlah_data; i++) {
        string nama_proyek;
        cout << "Masukkan nama proyek ke-" << i + 1 << ": ";
        getline(cin, nama_proyek);
        proyek.sekaligus.push(nama_proyek);
    }

    cout << "Berikut List Sementara" << endl;
    int nomersementara = 1;
    queue<string> proyek_sementara = proyek.sekaligus;
    while (!proyek_sementara.empty()) {
        cout << nomersementara << ". " << proyek_sementara.front() << endl;
        proyek_sementara.pop();
        nomersementara++;
    }

    string pilihan_yn;
    cout << "Apakah Yakin ingin menambahkan ke list? (y/n) : ";
    cin >> pilihan_yn;

    if (pilihan_yn == "y") {
        while (!proyek.sekaligus.empty()) {
            proyek.listproyek[proyek.penanda_array] = proyek.sekaligus.front();
            proyek.sekaligus.pop();
            proyek.penanda_array++;
        }
        ListProyek();
    } else if (pilihan_yn == "n") {
        ListProyek();
    }
}


void ListProyekWIP()
{
	int nomorwip = 1;
    int countwip = 0;
    int pil_menu_wip;
    int proyek_hapus_wip;
    int proyek_pindah_finish;
    system("cls");
    cout << "Tampilan List Proyek WIP yang Ada" << endl;
    cout << "=================================" << endl << endl;
    for(int i = 0; i < proyekwip.penanda_array; i++)
    {
        cout << nomorwip << ". " << proyekwip.listproyek[i] << endl;
        nomorwip++;
    }
    cout << "Pilih Opsi dibawah ini [1..3]" << endl;
    cout << "[1]Hapus Proyek\n[2]Pindahkan ke Finish\n[4]Search Proyek WIP\n[5]Sort Proyek WIP\n[6]Undo Pindah Finish\n[7]Kembali\n: ";
    cin >> pil_menu_wip;
    if(pil_menu_wip == 1)
    {
    	cout << "Pilih proyek yang akan dihapus [1.." << proyekwip.penanda_array << "] : ";
        cin >> proyek_hapus_wip;
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
         if(proyek_hapus_wip-1 == i)
         {
             proyekwip.listproyek[i] = "";
             break;
         }
        }
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
            if(proyekwip.listproyek[i] == "")
            {
                proyekwip.listproyek[i] = proyekwip.listproyek[i+1];
                proyekwip.listproyek[i+1] = "";
            }
        }
        proyekwip.penanda_array--;
        ListProyekWIP();
	}
	else if(pil_menu_wip == 2)
	{
		cout << "Pilih proyek yang akan dipindah ke Finish [1.." << proyekwip.penanda_array << "] : ";
        cin >> proyek_pindah_finish;
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
         if(proyek_pindah_finish-1 == i)
         {
         	 proyekfinish.listproyek[proyekfinish.penanda_array] = proyekwip.listproyek[i];
             proyekwip.listproyek[i] = "";
             break;
         }
        }
        proyekfinish.penanda_array++;
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
            if(proyekwip.listproyek[i] == "")
            {
                proyekwip.listproyek[i] = proyekwip.listproyek[i+1];
                proyekwip.listproyek[i+1] = "";
            }
        }
        proyekwip.penanda_array--;
        ListProyekWIP();
	}
    else if(pil_menu_wip == 4)
    {
        SearchProyekWIP();
    }
    else if(pil_menu_wip == 5)
    {
        SortProyekWIP();
    }
    else if(pil_menu_wip == 6)
    {
        UndoPindahFinish();
    }
	else if(pil_menu_wip == 7)
	{
		Menu();
	}
}
void SearchProyekWIP()
{
    string keyword;
    cout << "Masukkan kata kunci: ";
    cin.ignore();
    getline(cin, keyword);

    cout << "Hasil Pencarian Proyek:" << endl;
    bool found = false;
    for (int i = 0; i < proyekwip.penanda_array; i++)
    {
        if (proyekwip.listproyek[i].find(keyword) != string::npos)
        {
            cout << i + 1 << ". " << proyekwip.listproyek[i] << endl;
            found = true;
            getchar();
            ListProyekWIP();
        }
    }

    if (!found)
    {
        cout << "Proyek tidak ditemukan." << endl;
        getchar();
        ListProyekWIP();
    }
}
void SortProyekWIP()
{
     for (int i = 0; i < proyekwip.penanda_array - 1; i++)
    {
        for (int j = 0; j < proyekwip.penanda_array - i - 1; j++)
        {
            if (proyekwip.listproyek[j] > proyekwip.listproyek[j + 1])
            {
                string temp = proyekwip.listproyek[j];
                proyekwip.listproyek[j] = proyekwip.listproyek[j + 1];
                proyekwip.listproyek[j + 1] = temp;
            }
        }
    }

    // Menampilkan list proyek yang telah diurutkan
    cout << "List Proyek setelah diurutkan:" << endl;
    for (int i = 0; i < proyekwip.penanda_array; i++)
    {
        cout << i + 1 << ". " << proyekwip.listproyek[i] << endl;
    }
    getchar();
    ListProyekWIP();
}
void UndoPindahFinish()
{
    if (proyekfinish.penanda_array > 0)
    {
        int proyek_terakhir = proyekfinish.penanda_array - 1;
        proyekwip.listproyek[proyekwip.penanda_array] = proyekfinish.listproyek[proyek_terakhir];
        proyekwip.penanda_array++;
        proyekfinish.listproyek[proyek_terakhir] = "";
        proyekfinish.penanda_array--;

        cout << "Proyek berhasil di-undo dan dikembalikan ke List Proyek WIP." << endl;
    }
    else
    {
        cout << "Tidak ada proyek yang bisa di-undo pada List Proyek Finish." << endl;
    }

    getchar();
    ListProyekWIP();
}

void ListProyekFinish()
{
	int nomorfinish = 1;
    int countfinish = 0;
    int pil_menu_finish;
    int proyek_hapus_finish;
    system("cls");
    cout << "Tampilan List Proyek Finish yang Ada" << endl;
    cout << "=================================" << endl << endl;
    for(int i = 0; i < proyekfinish.penanda_array; i++)
    {
        cout << nomorfinish << ". " << proyekfinish.listproyek[i] << endl;
        nomorfinish++;
    }
    cout << "Pilih Opsi dibawah ini [1..2]" << endl;
    cout << "[1]Hapus Proyek\n[2]Search\n[3]Sort\n[4]Kembali : ";
    cin >> pil_menu_finish;
    if(pil_menu_finish == 1)
    {
    	cout << "Pilih proyek yang akan dihapus [1.." << proyekfinish.penanda_array << "] : ";
        cin >> proyek_hapus_finish;
        for(int i = 0; i < proyekfinish.penanda_array; i++)
        {
         if(proyek_hapus_finish-1 == i)
         {
             proyekfinish.listproyek[i] = "";
             break;
         }
        }
        for(int i = 0; i < proyekfinish.penanda_array; i++)
        {
            if(proyekfinish.listproyek[i] == "")
            {
                proyekfinish.listproyek[i] = proyekfinish.listproyek[i+1];
                proyekfinish.listproyek[i+1] = "";
            }
        }
        proyekfinish.penanda_array--;
        ListProyekFinish();
	}
    else if(pil_menu_finish == 2)
    {
        SearchProyekFinish();
    }
    else if(pil_menu_finish == 3)
    {
        SortProyekFinish();
    }
	else if(pil_menu_finish == 4)
	{
		Menu();
	}
}
void SearchProyekFinish()
{
    string keyword;
    cout << "Masukkan kata kunci: ";
    cin.ignore();
    getline(cin, keyword);

    cout << "Hasil Pencarian Proyek:" << endl;
    bool found = false;
    for (int i = 0; i < proyekfinish.penanda_array; i++)
    {
        if (proyekfinish.listproyek[i].find(keyword) != string::npos)
        {
            cout << i + 1 << ". " << proyekfinish.listproyek[i] << endl;
            found = true;
            getchar();
            ListProyekFinish();
        }
    }

    if (!found)
    {
        cout << "Proyek tidak ditemukan." << endl;
        getchar();
        ListProyekFinish();
    }
}
void SortProyekFinish()
{
     for (int i = 0; i < proyekfinish.penanda_array - 1; i++)
    {
        for (int j = 0; j < proyekfinish.penanda_array - i - 1; j++)
        {
            if (proyekfinish.listproyek[j] > proyekfinish.listproyek[j + 1])
            {
                string temp = proyekfinish.listproyek[j];
                proyekfinish.listproyek[j] = proyekfinish.listproyek[j + 1];
                proyekfinish.listproyek[j + 1] = temp;
            }
        }
    }

    // Menampilkan list proyek yang telah diurutkan
    cout << "List Proyek setelah diurutkan:" << endl;
    for (int i = 0; i < proyekfinish.penanda_array; i++)
    {
        cout << i + 1 << ". " << proyekfinish.listproyek[i] << endl;
    }
    getchar();
    ListProyekFinish();
}

void ListAntrianProyekAkun()
{
	int nomorantrian = 1;
    int countantrian = 0;
    int pil_menu_antrian;
    int proyek_hapus_antrian;
    system("cls");
    cout << "Tampilan List Antrian Proyek WIP yang Ada" << endl;
    cout << "=================================" << endl << endl;
    for(int i = 0; i < proyekwip.penanda_array; i++)
    {
        cout << nomorantrian << ". " << proyekwip.listproyek[i] << endl;
        nomorantrian++;
    }
    cout << "Pilih Opsi dibawah ini [1..3]" << endl;
    cout << "[1]Hapus Proyek [2]Pindahkan ke Finish [3]Kembali : ";
    cin >> pil_menu_antrian;
    if(pil_menu_antrian == 1)
    {
    	
	}
	else if(pil_menu_antrian == 2)
	{
		
	}
	else if(pil_menu_antrian == 3)
	{
		Menu();
	}
}
void GantiPassword()

{
    string password, pass_baru;
    cout << "Masukkan Password : "; cin >> password;
	for(int i = 0; i <= akuninfo.npenanda; i++)
	{
		if(password == akuninfo.password[i])
		{
        cout << "Password berhasil diverifikasi." << endl;
		cout << "Masukkan Password Baru :";cin>>pass_baru;
        akuninfo.password[i] = pass_baru;
        cout << "Password berhasil diubah." << endl;
        system("cls");
        Menu();
		break;
		}
        else
        {
        cout << "Password yang anda masukkan salah." << endl;
        Menu();
        }

    }
}

int main()
{
    data_ada();
	Login();
}