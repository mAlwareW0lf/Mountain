#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Classes.h"
using namespace std;
int getRandomNumber();
bool lever[8];
bool battleWas[10];
bool bossDead[5];
//------------------------------------------------------------------------------------------------------------
//Тут объявляются классы
//------------------------------------------------------------------------------------------------------------
Armor FurArmor;
Armor IronPlate;
Weapon IronDagger;
Weapon IronSword;
Weapon OakClub;
Enemy Goblin;
Enemy Wolf;
Enemy Bear;
Enemy Werewolf;
Enemy Cobolt;
Enemy Troll;
Enemy GoblinKing;
//------------------------------------------------------------------------------------------------------------
//Здесь объявляются направления для движения.
//------------------------------------------------------------------------------------------------------------
void South();
void SouthR();
void SouthL();
void SouthF();
void East();
void Vest();
void VestR();
void VestL();
void VestF();
void North();
//------------------------------------------------------------------------------------------------------------
//Здесь объявляются функции битв для каждого из противников. Жопой чую, что можно было сделать проще, но
// я еблан и это мой первый нормальный проект.
// P.S 
// Как видно, теперь здесь всего одна функия, а значит я допёр
// 
// P.P.S
// Как видно, уже не одна, но так надо
//------------------------------------------------------------------------------------------------------------
void randomBattle(int ran);
void randomSet(int ran);
void setFurArmor();
void setIronPlate();
void setIronDagger();
void setIronSword();
void Woa();
//------------------------------------------------------------------------------------------------------------
//Тут, короче, задаются параметры противников и вывод их изображения в ASCII, когда вызываешь функцию
//------------------------------------------------------------------------------------------------------------
void setGoblin();
void setWolf();
void setBear();
void setCobolt();
void setWerewolf();
void setTroll();
void setGoblinKing();

//Функция для рандома, не трогать!

//Основная функция для путешествий

void Adventure() {
	for (int i = 0; i <= 9; i++) {
		battleWas[i] = false;
	}
to:
	system("cls");
	cout << "Вас ведут 4 направления:" << endl;
	cout << "1 - Запад." << endl;
	cout << "2 - Юг." << endl;
	cout << "3 - Восток." << endl;
	cout << "4 - Север." << endl;
	cout << "5 - Остаться." << endl;
	short int x = 0;
	cin >> x;

	switch (x)
	{
	case 1:
		system("cls");
		cout << "Вы отправляетесь в западные пещеры..." << endl;
		system("pause");
		Vest();
		break;
	case 2:
		system("cls");
		cout << "Вы отправляетесь в южные руины..." << endl;
		system("pause");
		South();
		break;
	case 3:
		system("cls");
		cout << "Не реализовано" << endl;
		system("pause");
		goto to;
		break;
	case 4:
		system("cls");
		cout << "Вы направляетесь в северный тоннель..." << endl;
		system("pause");
		North();
		break;
	case 5:
		system("cls");
		cout << "Вы остались у костра." << endl;
		system("pause");
		break;
	default:
		goto to;
		break;

	}
}

//Функции направлений движения

void North() {
	system("cls");
	cout << "Вы оказались в коридоре с развилкой.\nНад каждым из проход вы можете заметить буквы." << endl;
	cout << "Чтобы это могло значить?" << endl;
	system("pause");

}

void Vest() {
	system("cls");
	bossDead[1] = false;
	for (short int i = 1; i < 3; i++) {
		lever[i] = false;
	}
	system("cls");
	cout << "Вы пришли в западную пещеру и встретили там..." << endl;
	Sleep(1500);
	int ran = getRandomNumber(1, 5);
	randomSet(ran);
	cout << "------------------------------------------------------" << endl;
	cout << "Что вы хотите сделать?" << endl;
	cout << "1 - Атаковать" << endl;
	cout << "2 - Сбежать" << endl;
	int x;
	cin >> x;

	if (x == 1)
	{
		system("cls");
		randomBattle(ran);
		if (dead == false) {
			int y = getRandomNumber(1, 100);
			if (y >= 50) {
				int x = getRandomNumber(1, 10);
				if (x > 6)
				{
					cout << "Вы нашли зелье лечения." << endl;
					Pl.setPotions(1);
					system("pause");
				}
				 x = getRandomNumber(1, 10);
				if (x <= 5) {
					setFurArmor();
					system("pause");
				}
				 x = getRandomNumber(1, 10);
				if (x <= 5) {
					setIronDagger();
					system("pause");
				}
				x = getRandomNumber(1, 10);
				if (x > 8) {
					Woa();
					system("pause");
				}
			}
			else
				system("pause");
			to:
			system("cls");
			cout << "После победы над противником, вы видете развилку." << endl;
			to2:
			cout << "1 - Пойти направо." << endl;
			cout << "2 - Пойти налево." << endl;
			cout << "3 - Пойти прямо." << endl;
			cout << "4 - Вернуться." << endl;
			short int t;
			cin >> t;
			switch (t)
			{
			case 1:

				VestR();
				system("cls");
				if (dead == false) {
					cout << "Вы вернулись на развилку." << endl;
					goto to2;
				}
				break;
			case 2:
				VestL();
				system("cls");
				if (dead == false) {
					cout << "Вы вернулись на развилку." << endl;
					goto to2;
				}
				break;
			case 3:
				VestF();
				if (bossDead[1] == true)
					break;
				if (dead == false) {
					if (bossDead[1] == false) {
						system("cls");
						cout << "Вы вернулись на развилку." << endl;
						goto to2;

					}
				}
				break;
			case 4:
				break;
			default:
				goto to;
				break;
			}
		}
		if (dead == true)
		{

		}
	}
	if (x == 2)
	{
		system("cls");
		cout << "Вы убежали из пещеры обратно в лагерь." << endl;
		system("pause");
	}
}
void VestR() {
	system("cls");
	if (battleWas[1] == false) {
		cout << "Вы повернули направо и отправились в каменную комнату и встретили там..." << endl;
		Sleep(1500);
		int ran = getRandomNumber(1, 5);
		randomSet(ran);
		cout << "------------------------------------------------------" << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Атаковать" << endl;
		cout << "2 - Сбежать" << endl;
		int x;
		cin >> x;
		if (x == 1) {
			system("cls");
			randomBattle(ran);
			if (dead == false) {
				battleWas[1] = true;
				int y = getRandomNumber(1, 100);
				if (y >= 50) {
					int x = getRandomNumber(1, 10);
					if (x > 7)
					{
						cout << "Вы нашли зелье лечения." << endl;
						Pl.setPotions(1);
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x <= 5) {
						setFurArmor();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x <= 5) {
						setIronDagger();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x > 5) {
						Woa();
						system("pause");
					}

				}
				else
					system("pause");
			}
		
		}
	}
		if (battleWas[1] == true) {
			if (dead == false) {
				system("cls");
				cout << "Вы, в слабом свете горящего факела, видите рычаг.\nХотите его переключить?" << endl;
				cout << "1 - Да" << endl;
				cout << "2 - Нет" << endl;
				short int t = 0;
				cin >> t;
				switch (t)
				{
				case 1:
					system("cls");
					cout << "Вы переключили рычаг." << endl;
					lever[1] = !lever[1];
					if (lever[2] == true && lever[1] == true) {
						cout << "Вы слышите скрежет, который издаётся из предыдущей комнаты..." << endl;
					}


					system("pause");
					break;
				default:
					break;
				}

			}
		}
		
	
	else
	{

	}
		
	
}	
void VestL() {
	system("cls");
	if (battleWas[2] == false) {

		cout << "Вы повернули налево и отправились в каменную комнату и встретили там..." << endl;
		Sleep(1500);
		int ran = getRandomNumber(1, 5);
		randomSet(ran);
		cout << "------------------------------------------------------" << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Атаковать" << endl;
		cout << "2 - Сбежать" << endl;
		int x;
		cin >> x;
		if (x == 1) {
			system("cls");
			randomBattle(ran);
			if (dead == false) {
				battleWas[2] = true;
				int y = getRandomNumber(1, 100);
				if (y >= 50) {
					int x = getRandomNumber(1, 10);
					if (x > 7)
					{
						cout << "Вы нашли зелье лечения." << endl;
						Pl.setPotions(1);
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x <= 5) {
						setFurArmor();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x >= 5) {
						setIronDagger();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x > 8) {
						Woa();
						system("pause");
					}
				}
				else
					system("pause");
			}
		}
		
	}
			
		if(battleWas[2]==true)
		{
			if (dead == false) {
				system("cls");
				cout << "Вы, в слабом свете горящего факела, видите рычаг.\nХотите его переключить?" << endl;
				cout << "1 - Да" << endl;
				cout << "2 - Нет" << endl;
				short int t = 0;
				cin >> t;
				switch (t)
				{
				case 1:
					system("cls");
					cout << "Вы переключили рычаг." << endl;
					lever[2] = !lever[2];
					if (lever[2] == true && lever[1] == true) {
						cout << "Вы слышите скрежет, который издаётся из предыдущей комнаты..." << endl;
					}
					system("pause");
					break;
				default:
					break;
				}

			}
		}
	
	else
	{

	}

}
void VestF() {
	if (lever[1] == true && lever[2] == true)
	{
		system("cls");
		cout << "Вы проходите в раннее закрытыю комнату и встречаете там Короля Гоблинов!" << endl;
		Sleep(1500);
		setGoblinKing();
		cout << "------------------------------------------------------" << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Атаковать" << endl;
		cout << "2 - Сбежать" << endl;
		int x;
		cin >> x;

		if (x == 1)
		{
			system("cls");
			GoblinKing.Battle();
			if (dead == false) {
				bossDead[1] = true;
					int x = getRandomNumber(1, 2);
					if (x == 1)
					{
						setIronSword();
					}
					if (x == 2)
					{
						setIronPlate();
					}
					system("cls");
					cout << "Вы нашли на полу комнаты скрижаль, на которой написанны две буквы 'AF'" << endl;
					cout << "Где бы это могло бы пригодиться?" << endl;
					system("pause");
				
			}
		}
	}

	else
	{
		system("cls");
		cout << "Пройдя вперед вы натыкаетесь на закрытый проход.\nМожет его можно как-то открыть?" << endl;
		system("pause");
		system("cls");
	}
}

void South(){
	system("cls");
	bossDead[2] = false;
	for (short int i = 1; i < 3; i++) {
		lever[i] = false;
	}
	system("cls");
	cout << "Вы пришли в южные руины и встретили там..." << endl;
	Sleep(1500);
	int ran = getRandomNumber(5, 10);
	randomSet(ran);
	cout << "------------------------------------------------------" << endl;
	cout << "Что вы хотите сделать?" << endl;
	cout << "1 - Атаковать" << endl;
	cout << "2 - Сбежать" << endl;
	int x;
	cin >> x;

	if (x == 1)
	{
		system("cls");
		randomBattle(ran);
		if (dead == false) {
			int y = getRandomNumber(1, 100);
			if (y >= 50) {
				int x = getRandomNumber(1, 10);
				if (x > 6)
				{
					cout << "Вы нашли зелье лечения." << endl;
					Pl.setPotions(1);
					system("pause");
				}
				x = getRandomNumber(1, 10);
				if (x <= 5) {
					setFurArmor();
					system("pause");
				}
				x = getRandomNumber(1, 10);
				if (x <= 5) {
					setIronDagger();
					system("pause");
				}
				x = getRandomNumber(1, 10);
				if (x > 8) {
					Woa();
					system("pause");
				}
			}
			else
				system("pause");
		to:
			system("cls");
			cout << "После победы над противником, вы видете развилку." << endl;
		to2:
			cout << "1 - Пойти направо." << endl;
			cout << "2 - Пойти налево." << endl;
			cout << "3 - Пойти прямо." << endl;
			cout << "4 - Вернуться." << endl;
			short int t;
			cin >> t;
			switch (t)
			{
			case 1:

				SouthR();
				system("cls");
				if (dead == false) {
					cout << "Вы вернулись на развилку." << endl;
					goto to2;
				}
				break;
			case 2:
				SouthL();
				system("cls");
				if (dead == false) {
					cout << "Вы вернулись на развилку." << endl;
					goto to2;
				}
				break;
			case 3:
				VestF();
				if (bossDead[1] == true)
					break;
				if (dead == false) {
					if (bossDead[1] == false) {
						system("cls");
						cout << "Вы вернулись на развилку." << endl;
						goto to2;

					}
				}
				break;
			case 4:
				break;
			default:
				goto to;
				break;
			}
		}
		if (dead == true)
		{

		}
	}
	if (x == 2)
	{
		system("cls");
		cout << "Вы убежали из пещеры обратно в лагерь." << endl;
		system("pause");
	}
}
void SouthR() 
{
	system("cls");
	if (battleWas[1] == false) {
		cout << "Вы повернули направо и отправились в каменную комнату и встретили там..." << endl;
		Sleep(1500);
		int ran = getRandomNumber(5, 10);
		randomSet(ran);
		cout << "------------------------------------------------------" << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Атаковать" << endl;
		cout << "2 - Сбежать" << endl;
		int x;
		cin >> x;
		if (x == 1) {
			system("cls");
			randomBattle(ran);
			if (dead == false) {
				battleWas[1] = true;
				int y = getRandomNumber(1, 100);
				if (y >= 50) {
					int x = getRandomNumber(1, 10);
					if (x > 7)
					{
						cout << "Вы нашли зелье лечения." << endl;
						Pl.setPotions(1);
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x <= 5) {
						setFurArmor();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x <= 5) {
						setIronDagger();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x > 5) {
						Woa();
						system("pause");
					}

				}
				else
					system("pause");
			}

		}
	}
	if (battleWas[1] == true) {
		if (dead == false) {
			system("cls");
			cout << "Вы осматриваете комнату и видите что-то блестящее в углу." << endl;
			cout << "1 - Да" << endl;
			cout << "2 - Нет" << endl;
			short int t = 0;
			cin >> t;
			switch (t)
			{
			case 1:
				system("cls");
				cout << "Вы переключили рычаг." << endl;
				lever[1] = !lever[1];
				if (lever[2] == true && lever[1] == true) {
					cout << "Вы слышите скрежет, который издаётся из предыдущей комнаты..." << endl;
				}


				system("pause");
				break;
			default:
				break;
			}

		}
	}


	else
	{

	}
}
void SouthL()
{
	system("cls");
	if (battleWas[2] == false) {

		cout << "Вы повернули налево и отправились в каменную комнату и встретили там..." << endl;
		Sleep(1500);
		int ran = getRandomNumber(5, 10);
		randomSet(ran);
		cout << "------------------------------------------------------" << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Атаковать" << endl;
		cout << "2 - Сбежать" << endl;
		int x;
		cin >> x;
		if (x == 1) {
			system("cls");
			randomBattle(ran);
			if (dead == false) {
				battleWas[2] = true;
				int y = getRandomNumber(1, 100);
				if (y >= 50) {
					int x = getRandomNumber(1, 10);
					if (x > 7)
					{
						cout << "Вы нашли зелье лечения." << endl;
						Pl.setPotions(1);
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x <= 5) {
						setFurArmor();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x >= 5) {
						setIronDagger();
						system("pause");
					}
					x = getRandomNumber(1, 10);
					if (x > 8) {
						Woa();
						system("pause");
					}
				}
				else
					system("pause");
			}
		}

	}

	if (battleWas[2] == true)
	{
		if (dead == false) {
			system("cls");
			cout << "Вы, в слабом свете горящего факела, видите рычаг.\nХотите его переключить?" << endl;
			cout << "1 - Да" << endl;
			cout << "2 - Нет" << endl;
			short int t = 0;
			cin >> t;
			switch (t)
			{
			case 1:
				system("cls");
				cout << "Вы переключили рычаг." << endl;
				lever[2] = !lever[2];
				if (lever[2] == true && lever[1] == true) {
					cout << "Вы слышите скрежет, который издаётся из предыдущей комнаты..." << endl;
				}
				system("pause");
				break;
			default:
				break;
			}

		}
	}

	else
	{

	}

}
void SouthF()
{
	if (lever[3] == true || lever[4] == true)
	{
		system("cls");
		cout << "Вы проходите в раннее закрытыю комнату и встречаете там Оборотня!" << endl;
		Sleep(1500);
		setGoblinKing();
		cout << "------------------------------------------------------" << endl;
		cout << "Что вы хотите сделать?" << endl;
		cout << "1 - Атаковать" << endl;
		cout << "2 - Сбежать" << endl;
		int x;
		cin >> x;

		if (x == 1)
		{
			system("cls");
			GoblinKing.Battle();
			if (dead == false) {
				bossDead[1] = true;
				int x = getRandomNumber(1, 2);
				if (x == 1)
				{
					setIronSword();
				}
				if (x == 2)
				{
					setIronSword();
				}
				system("cls");
				cout << "Вы нашли на полу комнаты скрижаль, на которой написанны две буквы 'CB'" << endl;
				cout << "Где бы это могло бы пригодиться?" << endl;
				system("pause");

			}
		}
	}

	else
	{
		system("cls");
		cout << "Пройдя вперед вы натыкаетесь на закрытый проход.\nМожет его можно как-то открыть?" << endl;
		system("pause");
		system("cls");
	}
}

//а тут уже работа функций set кого-либо и battle
void randomSet(int r) {

	if (r >= 1 && r < 3) {
		setGoblin();
	}

	if (r >=3 && r < 5)
	{
		setCobolt();
	}

	if (r >= 5 && r < 8)
	{
		setWolf();
	}
	if (r >= 8 && r < 10)
	{
		setBear();
	}

}
void randomBattle(int r) {

	if (r >= 1 && r < 3)
	{
		Goblin.Battle();
	}
	if (r >= 3 && r < 5)
	{
		Cobolt.Battle();
	}
	if (r >= 5 && r < 8)
	{
		Wolf.Battle();
	}
	if (r >= 8 && r < 10)
	{
		Bear.Battle();
	}

}

void setGoblin() {
	Goblin.setHealth(70);
	Goblin.setDamage(8, 15);
	Goblin.setName("Goblin");
	Goblin.setArmorClass(10);
	image.getGoblin();
	Goblin.ViewEnemy();
}
void setWolf() {
	Wolf.setHealth(100);
	Wolf.setDamage(20, 30);
	Wolf.setName("Wolf");
	Wolf.setArmorClass(10);
	image.getWolf();
	Wolf.ViewEnemy();
}
void setBear()
{
	Bear.setHealth(120);
	Bear.setDamage(25, 35);
	Bear.setName("Bear");
	Bear.setArmorClass(20);
	image.getBear();
	Bear.ViewEnemy();
}
void setCobolt() 
{
	Cobolt.setHealth(50);
	Cobolt.setDamage(13, 20);
	Cobolt.setName("Kobold");
	Cobolt.setArmorClass(0);
	image.getCobolt();
	Cobolt.ViewEnemy();
}
void setWerewolf();
void setTroll()
{
	Troll.setName("Горный тролль");
	Troll.setHealth(200);
	Troll.setArmorClass(90);
	Troll.setDamage(50, 100);
	image.getTroll();
	Troll.ViewEnemy();
}
void setGoblinKing()
{
	GoblinKing.setHealth(100);
	GoblinKing.setDamage(20, 25);
	GoblinKing.setName("King of Goblins");
	GoblinKing.setArmorClass(20);
	image.getGoblinKing();
	GoblinKing.ViewEnemy();
}

void setFurArmor() 
{

	FurArmor.setDescription("Обычная броня из кожи и меха.\nЗащищает очень слабо, но это хоть что-то.");
	FurArmor.setName("Меховая броня");
	FurArmor.setArmor(10);
	FurArmor.getLoot();
}
void setIronPlate() 
{
	IronPlate.setDescription("Отличные железные латы! Скорее всего, они спасут вас от множества врагов.");
	IronPlate.setName("Железные латы");
	IronPlate.setArmor(30);
	IronPlate.getLoot();
}

void setIronDagger()
{
	IronDagger.setDamage(15, 20);
	IronDagger.setName("Желеный кинжал");
	IronDagger.setDescription("Ржавый железный кинжал.\nОн знавал лучшие времена, но и сейчас будет очень полезен.");
	IronDagger.getLoot();
}
void setIronSword() 
{

	IronSword.setDamage(25, 40);
	IronSword.setName("Железный меч");
	IronSword.setDescription("Железный меч отличной тролльской работы!");
	IronSword.getLoot();
}
void Woa()
{
	OakClub.setDamage(8, 27);
	OakClub.setName("Деревянная дубинка");
	OakClub.setDescription("Старая деревянная дубинка.\nВ хороших руках, может оказаться довольно смертельной.");
	OakClub.getLoot();
}