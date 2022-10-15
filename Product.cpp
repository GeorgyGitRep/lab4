#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Product.h"
Product::Product()// выделяет память под структур Product 
 //и инициализирует ее значениями по умолчанию
{
	price = 0;
	count = 0;
}
Product::Product(char* a, int n, int p, int d0, int m, int y):name(a), date(d0, m, y), count(n), price(p)
{ }
Product::Product(const Product& t) //coздает копию структуры Product в динамической памяти
	:
 date(t.date), count(t.count), price(t.price),	name(t.name)
{}
Product::~Product() // Освобождает выделенную память под структур Product
{
}
Product* Product::copy()
{
	return new Product(*this);
}
int Product::equal(const Product& t)const // функция, проверяющая равенство значений полей записей.Используется при поиске
{
	int a = 1;
	a = a && ((t.price != 0) ? price == t.price : 1);
	a = a && ((t.count != 0) ? count == t.count : 1);
	a = a && ((t.date.get_day() != 0 && t.date.get_month() != 0 && t.date.get_year() != 0) ? date.equal(t.date) : 1);
	a = a && ((t.name.length() != 0) ? name.equal(t.name) : 1);
	return a;
}
int Product::cmp(const Product& t) const// функция, сравнивающая записи Используется при сортировке
{
	int cond;
	MyString s1(t.name);
	if (s1.length() != 0 && (cond = name.cmp(t.name))) return cond;
	else return count - t.count;
}
int Product::input(istream& Cin)
{

	cout << "Название: ";
	name.input();
	cout << " колличество : ";
	cin >> count;
	cout << "Цена: ";
	cin >> price;
	cout << "Дата День месяц год: ";
	date.input();
	return 1;
}
void Product::output(ostream& Cout)const
{
	cout << "Название: ";
	name.output();
	cout << "Цена: ";
	cout << price << endl;
	cout << "Номер: ";
	cout << count << endl;
	cout << "Дата День месяц год: ";
	date.output();
}
// Перегрузка операторов
int operator == (const Product& a, const Product& b)
// оператор сравнения (заменяет equal())
{
	return !a.cmp(b);
}
int operator != (const Product& a, const Product& b)
{
	return a.cmp(b);
}
int operator <(const Product& a, const Product& b)
{
	return a.cmp(b) < 0;
}
int operator <= (const Product& a, const Product& b)
{
	return a.cmp(b) <= 0;
}
int operator > (const Product& a, const Product& b)
{
	return a.cmp(b) > 0;
}
int operator >= (const Product& a, const Product& b)
{
	return a.cmp(b) >= 0;
}
ostream& operator<<(ostream& os, const Product& r)// оператор вывода (заменяет output()) 
{
	r.output(os);
	return os;
}
istream& operator>>(istream& is, Product& r)// оператор ввода (заменяет input()) 
{
	r.input(is);
	return is;
}