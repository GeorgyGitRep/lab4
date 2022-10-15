#include "Table.h"
Tabl::Tabl(int sz, T bf) :v(sz), buf(bf) {
	cur = v.begin();
}
Tabl::Tabl() : v(10), buf(0)
{
}
Tabl::~Tabl()
{
	clear();

}
T* Tabl::begin()const {
	return v.begin();
}
T* Tabl::end()const { return cur; }
int Tabl::length() { return cur - begin(); }
int Tabl::getSize() { return v.get_size(); }
T* Tabl::insert(const T& item)
{
	int sz = getSize();
	if (length() >= sz)v.resize(2 * sz);
	*cur++ = item->copy();
	return cur;
}
T* Tabl::erase(T* pos)
{
	T* i;
	(*pos)->dispose();
	for (i = pos; i < cur; i++)
		*i = *(i + 1);
	cur--;
	return pos;
}
void Tabl::clear()
{
	T* i;
	for (i = begin(); i < cur; i++)
	{
		(*i)->dispose();
		delete (*i);
	}
	cur = begin();
}
int Tabl::remove(const T& item)
{
	T* i, * j = begin(); int n = 0;
	for (i = begin(); i < cur; i++)
		if ((**i) != (*item))
			*j++ = *i;
		else { (*i)->dispose(); n++; }
	cur = j;
	return n;
}
int Tabl::find(const T& item)
{
	T* i;
	for (i = begin(); i < cur; i++)
		if ((**i) == *item) return i - begin();
	return -1;
}
int Tabl::replace(const T& Old, const T& New)
{
	T* i; int count = 0;
	for (i = begin(); i < cur; i++)
		if (**i == *Old)
		{
			(*i)->dispose();
			(*i) = (New)->copy();
			count++;
		}
	return count;
}
void Tabl::sort() {
	int i, j, len = length();
	for (j = 0; j < len - 1; j++)
		for (i = 0; i < len - 1 - j; i++)
			if (*v[i] > *v[i + 1])
			{
				T tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
}
int Tabl::input(istream& Cin)
{
	int count;
	for (count = 0; count < getSize() && buf->input(Cin); count++)
		insert(buf);
	return count;
}
void Tabl::output(ostream& Cout)const
{
	T* i;
	for (i = begin(); i != end(); i++)
		(*i)->output(Cout);
}
// Перегрузка операторов
ostream& operator<<(ostream& os, const Tabl& r)// оператор вывода (заменяет output()) 
{
	r.output(os);
	return os;
}
istream& operator>>(istream& is, Tabl& r)// оператор ввода (заменяет input()) 
{
	r.input(is);
	return is;
}