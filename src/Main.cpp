#include<iostream>
#include<locale>
#include<Windows.h>	
#include<fstream>
#include<iostream>
#include<string>
#include<istream>
#include<exception>
#include"warehouse.h"	


using namespace std;

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	Warehouse product(100);

	int key, num;
start:
	num = 0;
	cout << "\t МЕНЮ !!!" << endl;
	cout << "1)Ввод данных " << endl;
	cout << "2)Вывод данных " << endl;
	cout << "3)добавить данные " << endl;
	cout << "4)удалить данные" << endl;
	cout << "5)Поиск данные" << endl;
	cout << "6)обновить данные" << endl;
	cout << "7)Сорировка по Inventory_number" << endl;
	cout << "8)Сорировка по Price" << endl;
	cout << "9)Сорировка по name" << endl;
	cout << "Выберете пункт из меню " << endl;

	cout << "Введите число" << endl;
	if (!(cin >> key)) {
		cout << "Error" << endl;
		exit;
	}
	else {

		switch (key)
		{

		case 1:product.input(); break;
		case 2:product.read(); break;
		case 3:product.add(); break;
		case 4:product.del(); break;
		case 5:product.search(); break;
		case 6:product.update(); break;
		case 7:product.sort_Inventory_number(); break;
		case 8:product.sort_Price(); break;
		case 9:product.sort_name(); break;
		default: cout << "ERROR " << endl;
			break;
		}
		cout << "Хотите продолжить ?" << endl;
		cout << "Если да нажмите 0:" << endl;
		cout << "Усли нет  то введите любое число кроме 0" << endl;
		cin >> num;
		if (num == 0) {
			goto start;
		}
		else {
			exit;
		}
		system("Pause");
	}
}
