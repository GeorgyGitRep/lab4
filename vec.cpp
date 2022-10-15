#include "vec.h"
#include <iostream>
using namespace std;
using namespace std;
vec::vec()
{
	v = new T[size = 10];

}
vec::vec(int sz)
{
	v = new T[size = sz];
}
vec::vec(const vec& l)
{
	v = new T[size = l.size];
	for (int i = 0; i < size; i++)
		v[i] = l.v[i];
}
vec::~vec() {
	delete[] v;
}
T& vec::item(int it)
{
	if (it<0 || it>size) { cout << "Index error"; exit(1); }
	return v[it];

}
T& vec::operator [](int i)
{
	return v[i];
}
void vec::resize(int n)
{
	T* t = new T[size + n];
	for (int i = 0; i < size; i++)
		t[i] = v[i];

	delete[] v;
	v = t;
	size += n;
}