#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
typedef FILE* File;
class MyDate
{
	int day, month, year;
	static int daytab[2][13];
	static const char* MonthName[13];
	static const char* DayNames[8];
public:
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	int get_day()const { return day; }
	int get_month()const { return month; }
	int get_year()const { return year; }
	char* get_DayOfWeek()const;
	//MyDate get_Now();
	MyDate Parser(char*);
	void AddDays(long); //аргумент может быть отрицательным числом
	void AddMonth(long); //аргумент может быть отрицательным числом
	void AddYear(long); //аргумент может быть отрицательным числом
	int validate();
	void set_day(int d) { int tmp = day; day = d; if (!validate()) day = tmp; }
	void set_month(int m) { int tmp = month; month = m; if (!validate()) month = tmp; }
	// void set_year(int y) { int tmp = year; year = q; if (!validate()) year = tmp; 

static int dayofyear(int y, int m, int d);
static void day_month(int d, int y, int* m, int* dd);
static int vis(int y) {
	return ((!(y % 4)) && (y % 100) || (!(y % 400)));
}
char* ToPchar();
unsigned long ToLong()const;
MyDate(void);
~MyDate(void);
MyDate(int d, int m, int y);
MyDate(char* s);
MyDate(const MyDate&);
void assign(const MyDate& t);
void dispose();
MyDate* copy();
int equal(const MyDate& t)const;
int cmp(const MyDate& t)const;
// int input(File fp);
int input(std::istream& in = cin);
// int output(File f);
void output(std::ostream& out = cout)const;
MyDate& operator = (const MyDate str); // оператор присваивания (использует assign()) 
operator const char* (); // оператор преобразования типа из MyDate в char* использует _itoa
friend ostream& operator <<(ostream&, const MyDate&); // оператор вывода (используетoutput())
friend istream& operator >>(istream&, MyDate&); // оператор ввода (использует input()) 
friend int operator ==(const MyDate&, const MyDate&); // оператор сравнения (используетequal())
friend int operator !=(const MyDate&, const MyDate&); // оператор сравнения (используетequal())
friend int operator <= (const MyDate&, const MyDate&); // оператор сравнения (используетcmp())
friend int operator >= (const MyDate&, const MyDate&); // оператор сравнения (используетcmp())
friend int operator < (const MyDate&, const MyDate&); // оператор сравнения (используетcmp())
friend int operator > (const MyDate&, const MyDate&); // оператор сравнения (используетcmp())

MyDate& operator +=(long); // оператор добавления дней (использует add_Days()) 
friend MyDate operator +(const MyDate&, long d); // оператор сложения (использует +=) 
friend long operator -(const MyDate&, const MyDate&); // оператор вычитания двух дат.
//Возвращает количество дней между ними использует ToLong

MyDate& operator++(); //инфиксный (использует +=)
MyDate operator++(int);// постфиксный (использует +=)
MyDate& operator--();//инфиксный (использует +=)
MyDate operator--(int);// постфиксный (использует +=)
};