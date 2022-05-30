#include "Medicine.h"
#include "Apteka.h"
#include <iostream>
using namespace std;

Medicine::Medicine(MyString _name, MyString _group, int day, int month, int year, double _price) :
	name(_name), gropu(_group), date{ day, month, year }, price(_price) // Список инициализации
{}

Medicine::~Medicine()
{
}

Medicine::Medicine(const Medicine& a)
{
	name = a.name;
	group = a.group;
	date = a.date;
	price = a.price;

}

Medicine::Medicine()
{
	price = 0;
	count = 0;
}



Medicine* Medicine::copy()
{
	return new Medicine(*this);
}

void Medicine::inputAll()
{
	cout << "Введите имя препарата: ";

	this->name.input();
	cout << endl;

	cout << "Введите группу: ";

	this->group.input();
	cout << endl;

	cout << "Введите количество: ";
	cin >> this->count;
	cout << endl;

	cout << "Введите цену: ";
	cin >> this->price;
	cout << endl;

	this->date.input();
}

void Medicine::OutputAll()
{
	cout << "Имя препарата: \t";
	this->name.output();

	cout << "Группа: \t";
	this->group.output();

	cout << endl << "Цена: \t";
	cout << this->price;

	cout << endl << "Количество: \t";
	cout << this->count;

	cout << endl << "Срок годности: \t";
	this->date.output();
}

int Medicine::cmp(Medicine* t)
{
	if (name.cmp(t->name) != 0)
		return name.cmp(t->name);
	else
		if ((price - t->price) != 0)
			return price - t->price;
		else
			if (Group.cmp(t->group) != 0)
				return group.cmp(t->group);
			else
				if (date.cmp(t->date) != 0)
					return date.cmp(t->date);
}

