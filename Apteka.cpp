#include "Medicine.h"
#include "Apteka.h"
#include <iostream>
#include <string>
using namespace std;

int menu() {
	int a;
	cout << endl << "----Apteka----" << endl;
	cout << "(1) Добавить новый препарат" << endl;
	cout << "(2) Вывести все препараты" << endl;
	cout << "(3) Измененить препарат" << endl;
	cout << "(4) Проверить на существование" << endl;
	cout << "(5) Сортировать по количеству" << endl;
	cout << "(6) Удалить" << endl;
	cout << "(7) Выход из программы" << endl;
	cout << "--------------" << endl;
	cout << "Выберите номер команды: ";
	string temp;
	cin >> temp;
	try {
		a = stoi(temp);
	}
	catch (invalid_argument e) {
		return 0;
	}
	return a;
}

Apteka::Apteka(int sz) :v(sz) {
	cur = begin();
}


//ввод
int Apteka::input() {
	int nlines = cur - begin();
	if (nlines++ >= v.get_size()) return 0;
	T* a;
	a = new T;
	a->inputAll();
	cur = this->insert(a);
	return cur - begin();
	        
	cout << "--------------------------" << endl;
}


//вывод
void Apteka::output() {
	cout << "--------------------------" << endl;
	for (T** t = begin(); t != cur; t++) {
		(*t)->OutputAll();
		cout << "--------------------------" << endl;
	}
}

#include<algorithm>
//сортировка
void Apteka::sort() {

	for (int j = 0; j < cur - begin() - 1; j++)
		for (int i = 0; i < cur - begin() - j - 1; i++)
			if (v.item(i)->cmp(v.item(i + 1)) > 0)
			{
				T* tmp = v.item(i);
				v.item(i) = v.item(i + 1);
				v.item(i + 1) = tmp;
			}


}






//удаление
int Apteka::remove(T* d) {
	int n = 0;
	for (int i = 0; i < lenght(); i++)
		if ((v.item(i))->cmp(d) == 0)
			n++;
	if (n == 0) return 0;
	T** t; T** k;
	k = t = new T * [lenght() - n];
	for (int i = 0; i < lenght(); i++)
		if ((v.item(i))->cmp(d) != 0)
			*t++ = v.item(i);
	cur = begin();
	for (; t - k; k++)
		*cur++ = (*k)->copy();
	return 1;


}


int Apteka::replace(T* Old, T* New) {

	int n = 0;
	for (int i = 0; i < lenght(); i++)
		if ((v.item(i))->cmp(Old) == 0)
		{
			v.item(i) = New->copy(); n++;

		}
	if (n == 0) return 0;
	return 1;
}


//поиск, который возвращает позицию
int Apteka::search(T* item) {

	T** i;
	for (i = begin(); i < cur; i++)
		if ((*i)->cmp(item) == 0) return i - begin();
	return -1;
}





//деструктор
Apteka::~Apteka() {

	for (T** t = begin(); t != cur; t++)
		delete* t;


}

T** Apteka::begin()
{
	return v.begin();
}

T** Apteka::end()
{
	return cur;
}

T** Apteka::insert(T* t)
{
	if (lenght() >= v.get_size()) return 0;
	*cur++ = t->copy();
	return cur;

}

int Apteka::lenght()
{
	return cur - v.begin();
}

void Apteka::erase(int p)
{
	T** t; T** k;
	k = t = new T * [lenght() - 1];
	for (int i = 0; i < lenght(); i++)
		if (i != p)
			*t++ = v.item(i);
	cur = begin();
	for (; t - k; k++)
		*cur++ = (*k)->copy();
}

int Apteka::search1(MyString a)
{
	for (int i = 0; i < cur - v.begin() - 1; i++)
	{
		if ((*v.begin() + i)->getName().cmp(a) == 0) {
			return i;
		}

	}
	return -1;
}

int Apteka::replace1(int index)
{

	Medicine* rep = new Medicine();

	rep->inputAll();
	*(v.begin() + index) = rep;

	return 0;
}

T* Apteka::search2(MyString a)
{

	for (int i = 0; i < cur - v.begin() - 1; i++)
	{
		if ((*v.begin() + i)->getName().cmp(a) == 0) {
			return (*v.begin() + i);
		}

	}
	return nullptr;
}

T* Apteka::search3(MyString a)
{
	T** i;
	for (i = begin(); i < cur; i++)
		if ((*i)->getName().cmp(a) == 0) return *i;

	return nullptr;
}
