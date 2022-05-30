#pragma once
#include "Medicine.h"
#include "vec.h"
class Apteka {
private:
	vec v;
	T** cur;
public:
	Apteka(int n);


	int remove(T* d);
	int replace(T* Old, T* New);
	int search(T* item);

	void sort();
	int input();
	void output();
	~Apteka();

	T** begin();
	T** end();
	T** insert(T* t);
	int lenght();
	void erase(int p);

	int search1(MyString a);
	int replace1(int index);
	T* search2(MyString a);
	T* search3(MyString a);


};



int menu();