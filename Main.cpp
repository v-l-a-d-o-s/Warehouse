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
	cout << "\t ���� !!!" << endl;
	cout << "1)���� ������ " << endl;
	cout << "2)����� ������ " << endl;
	cout << "3)�������� ������ " << endl;
	cout << "4)������� ������" << endl;
	cout << "5)����� ������" << endl;
	cout << "6)�������� ������" << endl;
	cout << "7)��������� �� Inventory_number" << endl;
	cout << "8)��������� �� Price" << endl;
	cout << "9)��������� �� name" << endl;
	cout << "�������� ����� �� ���� " << endl;

	cout << "������� �����" << endl;
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
		cout << "������ ���������� ?" << endl;
		cout << "���� �� ������� 0:" << endl;
		cout << "���� ���  �� ������� ����� ����� ����� 0" << endl;
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
