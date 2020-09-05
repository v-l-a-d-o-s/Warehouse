#include"warehouse.h"
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstring>
#include <vector>
#include<algorithm>
#include<iterator>
#include<exception>
using namespace std;

Warehouse::Warehouse() {
	price = 0.00;
	weight = 0.00;
	name_p = "aaaaaa";
	numerosity = 0;

}
Warehouse::Warehouse(int s) {
	Inventory_number = 1 + rand() % 1000;
	Inventory_number += s;
	
}

int  random(int Inv) {
	srand(time(0));
	int n = 1 + rand() % 1000;
	return n;

}
void Warehouse::input() {
	bool f_fail;
	
		cout << "Введите данные" << endl;
		cout << "Назва товару" << endl;
		cin >> name_p;

	do{
		cout << "Вага" << endl;
		cin >> weight;
		f_fail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (f_fail == true);
	do {
		cout << "Ціна" << endl;
		cin >> price;
		f_fail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (f_fail == true);

	do {
		cout << "Кількість товару" << endl;
		cin >> numerosity;
		f_fail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (f_fail==true);

		fstream f;
		f.exceptions(ifstream::badbit | ifstream::failbit);
		try {
			cout << "..." << endl;
			f.open("input.txt", ios_base::out);
			cout << "open" << endl;
			//f << "Інвентарний номер :" << random(Inventory_number) << "\t" << "Имя :" << name_p << "\t" << "Вага :" << weight << "\t" << "Цена :" << price << "\t" << "Количесво :" << numerosity << endl;
			f << name_p << "\t" << random(Inventory_number) << "\t" << weight << "\t" << price << "\t" << numerosity << endl;

			f.close();
		}
		catch (exception& er) {
			cout << "error" << endl;
			cout << er.what() << endl;
		}

			
}


void Warehouse::read() {
	fstream file;
	string str;
	cout << "Введите название файла input.txt || output.txt" << endl;
	cin >> str;
	file.open(str);
	if (!file.is_open()) {
		cout << "error" << endl;
	}
	else {
		string str;
		while (!file.eof()) {
			str = "";
			getline(file, str);
			cout << str << endl;
		}
	}
	file.close();
}

void Warehouse::add() {
	
	bool f_fail;

	cout << "Введите данные" << endl;
	cout << "Назва товару" << endl;
	cin >> name_p;

	do {
		cout << "Вага" << endl;
		cin >> weight;
		f_fail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (f_fail == true);
	do {
		cout << "Ціна" << endl;
		cin >> price;
		f_fail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (f_fail == true);

	do {
		cout << "Кількість товару" << endl;
		cin >> numerosity;
		f_fail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (f_fail == true);

	fstream f;
	f.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		cout << "..." << endl;
		f.open("input.txt", ios_base::app);
		cout << "open" << endl;
		//f << "Інвентарний номер :" << random(Inventory_number) << "\t" << "Имя :" << name_p << "\t" << "Вага :" << weight << "\t" << "Цена :" << price << "\t" << "Количесво :" << numerosity << endl;
		f << name_p << "\t" << random(Inventory_number) << "\t" << weight << "\t" << price << "\t" << numerosity << endl;

		f.close();
	}
	catch (exception& er) {
		cout << "error" << endl;
		cout << er.what() << endl;
	}

}


bool dlc_searche(string::size_type n, string  &str)
{
	if (n == std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}


void Warehouse::del() {

	fstream f;
	ofstream f1;
	f.open("input.txt");
	f1.open("output.txt");
	if (!f.is_open() && !f1.is_open()) {
		cout << "Error" << endl;
	}
	else {
		string str;
		std::string::size_type n;
		std::string  s;

		cout << "Введие имя товара чтоб удалить" << endl;
		cin >> s;
		while (!f.eof()) {
			str = "";
			getline(f, str);
			n = str.find(s);
			if (!dlc_searche(n, str)) {
				f1 << str << endl;
			}
		}
	}
	f.close();
	f1.close();

}


void dlc_search(string::size_type n, string  &str)
{
	if (n == std::string::npos) {
		cout << endl;
	}
	else {
		cout << "\t FOUND :" << str.substr(n) << '\n';
	}
}



void Warehouse::search()
{
	fstream file;
	string str;
	cout << "Введите название файла input.txt || output.txt" << endl;
	cin >> str;
	file.open(str);
	if (!file.is_open()) {
		cout << "error" << endl;
	}
	else {
		string str;
		std::string::size_type n;
		std::string  s;

		cout << "Введие слово для поиска" << endl;
		cin >> s;
		while (!file.eof()) {
			str = "";
			getline(file, str);
			n = str.find(s);
			dlc_search(n, str);
		}
	}
	file.close();
}

void Warehouse::update() // спросить почему удаляет одну запись при перезаписи файла 
{

	fstream f;
	ofstream f1;
	f.open("input.txt");
	f1.open("output.txt",ios::app);
	if (!f.is_open() && !f1.is_open()) {
		cout << "Error" << endl;
	}
	else {
		string str;
		std::string::size_type n;
		std::string  s;

		cout << "Введие имя товара для обновление данных" << endl;
		cin >> s;
		while (!f.eof()) {
			str = "";
			getline(f, str);
			n = str.find(s);
			if (!dlc_searche(n, str)) {
				f1 << str << endl;
				f1 << endl;
			}
			else {
				f >> name_p >> Inventory_number >> weight >> price >> numerosity;
				cout << "Введите данные" << endl;
				cout << "Назва товару" << endl;
				cin >> name_p;
				cout << "Інвентарний номер" << endl;
				cin >> Inventory_number;
				cout << "Вага" << endl;
				cin >> weight;
				cout << "Ціна" << endl;
				cin >> price;
				cout << "Кількість товару" << endl;
				cin >> numerosity;
				f1 << name_p << "\t" << Inventory_number << "\t" << weight << "\t" << price << "\t" << numerosity;

			}
		}
	}
	f.close();
	f1.close();

}

void Warehouse::sort_Inventory_number() {
	vector<int>inv;
	fstream f;
	f.open("input.txt");
	if (!f.is_open()) {
		cout << "Error" << endl;
	}
	else {
		string s;
		while (!f.eof())
		{

			f >> name_p >> Inventory_number >> weight >> price >> numerosity;
			inv.push_back(Inventory_number);

		}
	}
	f.close();
	cout << endl;
	sort(inv.begin(), inv.end());
	inv.pop_back();
	for (int n : inv) {
		cout << n << endl;
	}
}

void Warehouse::sort_Price() {
	vector<float>inv;
	fstream f;
	f.open("input.txt");
	if (!f.is_open()) {
		cout << "Error" << endl;
	}
	else {
		while (!f.eof())
		{

			f >> name_p >> Inventory_number >> weight >> price >> numerosity;
			inv.push_back(price);

		}
	}
	f.close();
	cout << endl;
	sort(inv.begin(), inv.end());
	inv.pop_back();
	for (float n : inv) {
		cout << n << endl;
	}
}

void Warehouse::sort_name()
{
	fstream in("input.txt");
	vector<string> vs;
	string s;
	while (getline(in, s)) vs.push_back(s);
	sort(vs.begin(), vs.end());
	fstream on("output.txt");
	copy(vs.begin(), vs.end(), ostream_iterator<string>(on, "\n"));
}


