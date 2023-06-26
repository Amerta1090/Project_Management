#include <iostream>
#include <string>
#include <unistd.h>
#define maxproyek 150
using namespace std;



struct proyek{
	string listproyek[maxproyek];
	string statusproyek;	
	int penanda_array = 0;
}proyek;

//Untuk tempat menyimpan data akun username dan password
struct akun{
	string username[99];//jono
	string password[99];//123
	int npenanda;
}akuninfo;

struct Node{
	
};
void Login(); //Menu Login
void Menu(); //Untuk Menu Utama Pengguna
void ListProyek();
void Menu()
{
	int menu_pil;
	system("cls");
	cout << "MENU PROYEK" << endl;
	cout << "Pilih Menu dibawah ini : " << endl;
	cout << "1. List Proyek" << endl;
	cout << "2. List Proyek WIP" << endl;
	cout << "3. List Proyek Finish" << endl;
	cout << "4. Tambah Akun/User" << endl;
	cout << "5. Ganti Password Akun/User" << endl;
	cout << "6. Logout" << endl;
	cout << "Masukkan Pilihan [1..6] : ";
	cin >> menu_pil;
	if(menu_pil == 1)
	{
	    ListProyek();
	}
	else if(menu_pil == 2)
	{
// 		ListProyekWIP();
	}
	else if(menu_pil == 3)
	{
// 		ListProyekFinish();
	}
	else if(menu_pil == 4)
	{
		Login();
	}
	else if(menu_pil == 5)
	{
// 		GantiPassword();
	}
	else if(menu_pil == 6)
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
		for(int i = 0; i < 99; i++)
		{
			if(username == akuninfo.username[i] && password == akuninfo.password[i])
			{
				cout << "Selamat anda berhasil login!!" << endl;
//				system("cls");
                sleep(5);
				Menu();
				break;
			}
			else if((i == 98 || i == 99) && username == akuninfo.username[i] && password == akuninfo.password[i])
			{
				cout << "Mohon masukkan username dan password yang benar" << endl;
				sleep(3);
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
			akuninfo.npenanda = 0;
			cout << "Selamat akun telah terbuat!!" << endl;
			Login(); 	
			}
			else
			{
			akuninfo.username[akuninfo.npenanda + 1] += user_baru;
			akuninfo.password[akuninfo.npenanda + 1] += pass_baru; 
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
    string proyek_tambah;
    system("cls");
    cout << "Tampilan List Proyek yang Ada" << endl;
    cout << "=============================" << endl << endl;
    // Menghitung Value dalam Array
    // for(int i = 0; i < maxproyek; i++)
    // {
    //     if(proyek.listproyek[i] == "")
    //     {
    //         break;
    //     }
    //     count++;
    // }
    // // End
    for(int i = 0; i < proyek.penanda_array; i++)
    {
        cout << nomor << ". " << proyek.listproyek[i] << endl;
        nomor++;
    }
    cout << "Pilih Opsi dibawah ini [1..4]" << endl;
    cout << "[1]Tambah Proyek [2]Hapus Proyek [3]Pindahkan ke WIP [4]Kembali : ";
    cin >> pil_menu_lp;
    if(pil_menu_lp == 1)
    {
        // cout << proyek.penanda_array << endl;
        cout << "Masukkan Proyek Yang diTambahkan : ";
        cin >> proyek_tambah;
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
    
    }
    else if(pil_menu_lp == 4)
    {
    
    }
}
int main()
{
    data_ada();
	Login();
}