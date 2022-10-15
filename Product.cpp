#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Product.h"
Product::Product()// �������� ������ ��� �������� Product 
 //� �������������� �� ���������� �� ���������
{
	price = 0;
	count = 0;
}
Product::Product(char* a, int n, int p, int d0, int m, int y):name(a), date(d0, m, y), count(n), price(p)
{ }
Product::Product(const Product& t) //co����� ����� ��������� Product � ������������ ������
	:
 date(t.date), count(t.count), price(t.price),	name(t.name)
{}
Product::~Product() // ����������� ���������� ������ ��� �������� Product
{
}
Product* Product::copy()
{
	return new Product(*this);
}
int Product::equal(const Product& t)const // �������, ����������� ��������� �������� ����� �������.������������ ��� ������
{
	int a = 1;
	a = a && ((t.price != 0) ? price == t.price : 1);
	a = a && ((t.count != 0) ? count == t.count : 1);
	a = a && ((t.date.get_day() != 0 && t.date.get_month() != 0 && t.date.get_year() != 0) ? date.equal(t.date) : 1);
	a = a && ((t.name.length() != 0) ? name.equal(t.name) : 1);
	return a;
}
int Product::cmp(const Product& t) const// �������, ������������ ������ ������������ ��� ����������
{
	int cond;
	MyString s1(t.name);
	if (s1.length() != 0 && (cond = name.cmp(t.name))) return cond;
	else return count - t.count;
}
int Product::input(istream& Cin)
{

	cout << "��������: ";
	name.input();
	cout << " ����������� : ";
	cin >> count;
	cout << "����: ";
	cin >> price;
	cout << "���� ���� ����� ���: ";
	date.input();
	return 1;
}
void Product::output(ostream& Cout)const
{
	cout << "��������: ";
	name.output();
	cout << "����: ";
	cout << price << endl;
	cout << "�����: ";
	cout << count << endl;
	cout << "���� ���� ����� ���: ";
	date.output();
}
// ���������� ����������
int operator == (const Product& a, const Product& b)
// �������� ��������� (�������� equal())
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
ostream& operator<<(ostream& os, const Product& r)// �������� ������ (�������� output()) 
{
	r.output(os);
	return os;
}
istream& operator>>(istream& is, Product& r)// �������� ����� (�������� input()) 
{
	r.input(is);
	return is;
}