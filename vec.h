#pragma once
#include "Product.h"
class vec
{
	T* v;
	int size;
public:
	T* begin()const { return v; }
	T* end() const { return v + size; }
	int get_size() { return size; }
	vec();
	~vec();
	vec(int sz);
	vec(const vec&);
	T& item(int);
	void resize(int);
	// Перегрузка операторов
	T& operator [](int);
};
