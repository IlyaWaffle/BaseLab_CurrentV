
#include "vec.h"
#include <iostream>

using namespace std;
vec::vec()
{
	v = new T * [size = 10];
	for (int i = 0; i < size; i++)
		v[i] = nullptr;
}
vec::vec(int sz)
{
	v = new T * [size = sz];
}

vec::vec(const vec& l)
{
	v = new T * [size = l.size];
	for (int i = 0; i < size; i++)
		v[i] = l.v[i];
}

vec::~vec() {
	delete[]v;
}

T*& vec::item(int it)
{
	if (it<0 || it>size) { std::cout << "Index error"; std::exit(1); }
	return v[it];
}
void vec::resize(int n)
{
	T** t = new T * [size + n];
	for (int i = 0; i < size && v[i] != nullptr; i++)
		t[i] = v[i]->copy();
	for (T** l = v; l - v < size && *l != nullptr; l++)
		delete* l;
	v = t;
	size = size + n;
}
