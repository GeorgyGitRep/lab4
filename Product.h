#pragma once
#include <iostream>
#include "MyStrung.h"
#include "MyDate.h"
using namespace std;
class Product
{
	// название
	MyString name;
	long count; // инвентарный номер
	double price; // цена
	MyDate date;
public:
	Product();
	Product(char* a, int n, int p, int d, int m, int y);
	Product(const Product&);
	~Product(); // Освобождает выделенную память под структур Product
	Product* copy();
	void dispose() {}
	int equal(const Product&)const; // функция, проверяющая равенство значений полей записей.Используется при поиске
	int cmp(const Product&)const; // функция, сравнивающая записи Используется при сортировке
	int input(istream& Cin = cin);
	void output(ostream& os = std::cout)const;
	

	friend int operator == (const Product&, const Product&);// оператор сравнения(заменяет equal())
	friend int operator != (const Product&, const Product&);
	friend int operator <(const Product&, const Product&);
	friend int operator <= (const Product&, const Product&);
	friend int operator > (const Product&, const Product&);
	friend int operator >= (const Product&, const Product&);
	friend ostream& operator <<(ostream& , const Product& ); // оператор выводa(заменяет output())
	friend istream& operator >>(istream& , Product& );// оператор ввода (заменяетinput())
};
typedef Product* T;
