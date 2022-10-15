#pragma once
#include <iostream>
using namespace std;
class MyString {
	char* s;
	int len;
public:
	MyString();
	MyString(const MyString&);
	MyString(char*);
	~MyString();
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&)const;
	int equal(const MyString&)const;
	int input(istream& Cin=cin);
	void output(ostream& Cout=cout)const;
	int length();
	int length()const;

	// Перегрузка операторов
	MyString& operator=(const MyString&);// оператор присваивания (заменяет assign()) 
	operator char* ();// оператор преобразования типа из MyString в char*
	friend int operator == (const MyString&, const MyString&);// оператор сравнения	(заменяет equal())
		friend int operator != (const MyString&, const MyString&);
	friend int operator <(const MyString&, const MyString&);
	friend int operator <= (const MyString&, const MyString&);
	friend int operator > (const MyString&, const MyString&);
	friend int operator >= (const MyString&, const MyString&);
	char& operator[](int i); // оператор индексирования символов (заменяет item())
	MyString& operator+=(const MyString&);// оператор добавления в конец (аналог strcat()
	friend MyString operator + (const MyString&, const MyString&);// соединяет две строки))
	friend ostream& operator<<(ostream&, const MyString&); // оператор вывода (заменяет	output())
	friend istream& operator>>(istream&, MyString&);// оператор ввода (заменяет input()) 
};