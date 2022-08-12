#include <iostream>
#include <string>
#include "Header.h"
#include <windows.h>
#include "Classes.h"
#include <cstdlib> 
#include <ctime>

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Russian");
	system("title Mountain");
	cout <<"Как зовут вашего персонажа?"<<endl;
	string Name;
	cin >> Name;
	Pl.setName(Name);
	short int A = 0;
Home:
	if (dead == false) {
		system("cls");
		image.getCampFire();
		cout << "Вы находитесь в своём лагере среди гор. " << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Осмотреть персонажа" << endl;
		cout << "2 - Спать" << endl;
		cout << "3 - Отправиться в путь" << endl;

		cin >> A;


		switch (A)
		{
		case 3:
			Adventure();
			break;
		case 2:;
			Pl.rest();
			break;
		case 1:
			Pl.View();
			break;
		default:
			break;
		}

		goto Home;
	}
	if (dead == true) {
		image.getRIP();
		system("pause");
	}
	
	return 0;
}


