/*�������� 1
�������� ���� ��� ������� ������ ���� ����� � ���������� � ������� ��������. ��������� ��������� ����� �  ������������� ����, � ���������� ������� �� ������� ������� �������� � � ���� ������� ������. ����������� ��������� ������ � �������� ������ ������, � ����� ���������� �������� ��������� �����:  
-	������������ ��� ��������� �� � ����������� ; 
-	���������; 
-	��������; 
-	��������� ���������� �� �����; 
-	����� ������� ���������� �� ���������� �������; 
-	����������� ������; 
-	���������� �� ������ ������.  
������������ ��������� ����� ��� �������� ��������-����� ����� �� ���������, � ���� ��� ���� ���������������. �������� ������� ������ ���� ��� �������� ��� ������ �����. 
*/

/*8. ������ ����в  - ����������� �����, ����� ������, ����, ����, �������. */
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<exception>

using namespace std;
class Warehouse {
private:
		int Inventory_number;
		string name_p;
		float weight;
		float price;
		int numerosity;

public:
	Warehouse();//+
	Warehouse(int s);//+

	void add();//���������� +
	void del();// �������� 
	void read();// ������ �� ����� +
	void sort_Inventory_number();//����������� �� ������� ������������ 
	void sort_Price();
	void sort_name();
	void search();//����� �� �������
	void input();
	void update();



};

