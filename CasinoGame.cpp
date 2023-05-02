//Сделано RedFoxMain 
//Git hub: https://github.com/RedFoxMain

#include <iostream>
#include <string>
#include <array>
#include <random>
#include <cstdlib>
#include <windows.h>

using namespace std;

random_device rd;
mt19937 gen(rd());
 
int random(int low, int high)
{
    uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int ShaitanKazinoMachine(int bet, string colour){
	array ar = {"красный","черный"};
	int i = random(0,1);
	int win = 0;
	if((colour == ar[i]) && bet != 0){
		win = bet * 2;	
		printf("Вы выиграли %i",win);
		cout << endl;
	
	} else {
		win = -bet;
		printf("Вы проиграли %i",win);
		cout << endl;
	}
	return win;
}
	

int main(int argc, char *argv[])
{
	
	int bet;
	int money = 500;
	int win = 0;
	string colour;
	
	while (bet != 0){
		if (money == 0){
			cout << "sorry, Link. I can't give credit. Come back when you'll be litle mmm richer!" << endl;
			break;
		}
		cout << "Добро пожаловать в казино!" << endl;
		cout << endl;
		printf("Сейчас на счету %i",money);
		cout << endl;
		cout << "Сделайте ставку(пример 100): ";
		cin >> bet;
		if (bet == 0){
			break;
		}
		cout << "Выберите цвет (красный/чёрный): ";
		cin >> colour;
		win = ShaitanKazinoMachine(bet, colour);
		money = money + win;
		
		printf("На счету %i",money);
		cout << endl;
		cout << "Консоль очистится через 4 секунды, подождите..." << endl;
		Sleep(4000);
		system("cls");
	}
	
}
