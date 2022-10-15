#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "MyDate.h"
int MyDate::daytab[2][13] = {
{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31} };const char* MyDate::MonthName[13] = { "Wrong month","January","February","March","April","May","June","July","August","September","October","November","December" };
const char* MyDate::DayNames[8] = { "Wrong day","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
void MyDate::AddDays(long d) {
	if (d > 0)
	{
		while (d--)
		{
			day++;
			if (day > daytab[vis(year)][month])
			{
				day = 1;
				month++;
				if (month == 13)
				{
					month = 1;
					year++;
				}
			}
		}
	}
	else
	{
		while (d++)
		{
			day--;
			if (!day)
			{
				month--;
				if (!month)
				{
					month = 12;
					year--;
					if (!year)
					{
						year = 1;
						month = 1;
						day = 1;
						return;
					}
				}
				day = daytab[vis(year)][month];
			}
		}
	}
}
void MyDate::AddMonth(long m)
{
	if (m > 0)
		while (m--)
		{
			month++;
			if (month == 13)
			{
				month = 1;
				year++;
			}
		}
	else
		while (m++)
		{
			month--;
			if (!month)
			{
				month = 12;
				year--;
				if (!year) { year = 1; month = 1; return; }
			}
		}
	int k;
	if (day > (k = daytab[vis(year)][month])) day = k;
}
void MyDate::AddYear(long y)
{
	year += y;
	if (year <= 0)
	{
		year = 1;
		month = 1;
		day = 1;
	}
	int k;
	if (day > (k = daytab[vis(year)][month])) day = k;
}
unsigned long MyDate::ToLong()const
{
	unsigned long d, m, y;
	d = day; y = 1; m = 1;
	while (y < year)
	{
		d += 365 + vis(y);
		y++;
	}
	while (m < month)
	{
		d += daytab[vis(year)][m];
		m++;
	}
	return d;
}
char* MyDate::get_DayOfWeek() const
{
	long dd = (ToLong()) % 7 + 1;
	char* s = new char[strlen(DayNames[dd]) + 1];
	strcpy(s, DayNames[dd]);
	return s;
}
int MyDate::dayofyear(int y, int m, int d)
{
	int dd = d;
	while (--m)
	{
		dd += daytab[vis(y)][m];
	}
	return dd;
}
void MyDate::day_month(int d, int y, int* m, int* dd)
{
	*m = 1;
	while (d > daytab[vis(y)][*m])
	{
		d -= daytab[vis(y)][(*m)++];
	}
	*dd = d;
	return;
}
MyDate::MyDate(void)
{
	day = month = year = 0;
}
MyDate::~MyDate(void)
{ }
MyDate::MyDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	if (!validate()) cout << " Error validate MyDate";
}
int MyDate::validate()
{
	return (year > 0 && month > 0 && month <= 12 && day > 0 && day <=
		daytab[vis(year)][month]);
}
MyDate::MyDate(char* s) {}
MyDate::MyDate(const MyDate& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}
void MyDate::assign(const MyDate& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}
void MyDate::dispose() {}
MyDate* MyDate::copy()
{
	return new MyDate(*this);
}
char* MyDate::ToPchar()
{
	char s[256], buf[256], * s1;
	s[0] = '\0';
	_itoa(day, buf, 10); strcat(s, buf); strcat(s, ".");
	_itoa(month, buf, 10); strcat(s, buf); strcat(s, ".");
	_itoa(year, buf, 10); strcat(s, buf);
	s1 = new char[strlen(s) + 1];
	strcpy(s1, s);
	return s1;
}
int MyDate::equal(const MyDate& d)const
{
	return day == d.day && month == d.month && year == d.year;
}
int MyDate::cmp(const MyDate& d)const
{
	if (year != d.year)return year - d.year;
	else if (month != d.month)return month - d.month;
	else return day - d.day;
}
int MyDate::input(std::istream& Cin)
{
	cout << "Day:"; Cin >> day;
	cout << "Month:"; Cin >> month;
	cout << "Year:"; Cin >> year;
	if (!validate()) { cout << "Error Data" << endl; return day = month = year = 0; }
	return 1;
}
void MyDate::output(std::ostream& Cout)const
{
	const char* s = MonthName[month],
		* ss = get_DayOfWeek();
	Cout << day << " (" << ss << ") " << s << " (" << month << ") " << year << endl;
}
MyDate MyDate::Parser(char* s)
{
	return MyDate(s);
}
MyDate& MyDate::operator = (const MyDate dt) // оператор присваивания (заменяет assign()) 
{
	day = dt.day;
	month = dt.month;
	year = dt.year;
	return *this;
}
MyDate::operator const char* () // оператор преобразования типа из MyDate в char*
{
	return "MyDate";

}
std::ostream& operator<<(std::ostream& out, const MyDate& other)
{
	other.output(out);
	return out;
}
std::istream& operator>>(std::istream& in, MyDate& other)
{
	other.input(in);
	return in;
}
int operator ==(const MyDate& d1, const MyDate& d2) // оператор сравнения (заменяет equal())
{
	return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}
int operator !=(const MyDate& d1, const MyDate& d2) // оператор сравнения (заменяет equal())
{
	return d1.day != d2.day || d1.month != d2.month || d1.year != d2.year;
}
int operator <= (const MyDate& d1, const MyDate& d2) // оператор сравнения (заменяет cmp())
{
	return d1.cmp(d2) < 0 || d1.cmp(d2) == 0;
}
int operator >= (const MyDate& d1, const MyDate& d2) // оператор сравнения (заменяет cmp())
{
	return d1.cmp(d2) > 0 || d1.cmp(d2) == 0;
}
int operator < (const MyDate& d1, const MyDate& d2) // оператор сравнения (заменяет cmp())
{
	return d1.cmp(d2) < 0;
}
int operator > (const MyDate& d1, const MyDate& d2) // оператор сравнения (заменяет cmp())
{
	return d1.cmp(d2) < 0;
}
MyDate& MyDate::operator +=(long d) // оператор сложения, добавляет количество дней к дате (заменяет add_days())
{
	AddDays(d);

	return *this;
}
MyDate operator +(const MyDate& dt, long d) // оператор сложения, добавляет количество дней к дате(заменяет add_days())
{
	MyDate Dt;
	Dt = dt;
	Dt += d;
	return Dt;
}
long operator -(const MyDate& d1, const MyDate& d2) // оператор вычитания (заменяет cmp(), возвращает разницу в количестве дней между датами)
{
return d1.ToLong() - d2.ToLong();
}
MyDate& MyDate::operator++()
{
	*this += 1;
	return *this;
}
MyDate MyDate::operator++(int)
{
	MyDate ret(*this);
	*this += 1;
	return ret;
}
MyDate& MyDate::operator --()
{
	*this += -1;
	return *this;
}
MyDate MyDate::operator--(int)
{
	MyDate ret(*this);
	*this += -1;
	return ret;
}