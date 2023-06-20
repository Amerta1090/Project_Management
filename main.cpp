#include <iostream>
#include <string>


using namespace std;



struct proyek{
	string lproyek;
	string statusproyek;
	
}proyek;

struct akun{
	string username[99];//jono
	string password[99];//123
	int npenanda;
}akuninfo;

struct Node{
	
};
void Login();
void Menu()
{
	int menu_pil;
	system("cls");
	cout << "MENU PROYEK" << endl;
	cout << "Pilih Menu dibawah ini : " << endl;
	cout << "1. List Proyek" << endl;
	cout << "2. List Proyek WIP" << endl;
	cout << "3. List Proyek Finish" << endl;
	cout << "4. Logout" << endl;
	cout << "Masukkan Pilihan [1..4] : ";
	if(menu_pil == 4)
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
				cout << "Selamat anda berhasil login!!";
//				system("cls");
				Menu();
			}
			else if(i == 98 && username == akuninfo.username[i] && password == akuninfo.password[i])
			{
				cout << "Mohon masukkan username dan password yang benar";
				Login();
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
			Login(); 	
			}
			else
			{
			akuninfo.username[akuninfo.npenanda + 1] += user_baru;
			akuninfo.password[akuninfo.npenanda + 1] += pass_baru; 
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
int main()
{
	Login();
}