#pragma once
#include "vec.h"
class Tabl {
	vec v;
	T buf;
	T* cur;
public:
	Tabl(int sz, T bf);
	Tabl();
	~Tabl();
	T* begin()const;
	T* end()const;
	int length();
	int getSize();
	T* insert(const T& item);
	T* erase(T* pos);
	void clear();
	int remove(const T& item);
	int find(const T& item);
	int replace(const T& Old, const T& New);
	void sort();
	int input(istream& Cin);
	void output(ostream& Cout)const;
	// ѕерегрузка операторов
	friend ostream& operator<<(ostream& os, const Tabl& r);// оператор вывода (замен€ет	output())
	friend istream& operator>>(istream& is, Tabl& r);
};