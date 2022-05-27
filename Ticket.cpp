#include "Ticket.h"
#include "TicketTable.h"
#include <iostream>
using namespace std;

Ticket::Ticket(MyString Name, MyString Airport, int day, int month, int year, double price) :
	name(Name), airport(Airport), date{ day, month, year }, price(price) // ������ �������������
{}

Ticket::~Ticket()
{
}

Ticket::Ticket(const Ticket& a)
{
	name = a.name;
	airport = a.airport;
	date = a.date;
	price = a.price;

}

Ticket::Ticket()
{
	price = 0;
}



Ticket* Ticket::copy()
{
	return new Ticket(*this);
}

void Ticket::inputAll()
{
	cout << "������� ��� ���������: ";

	this->name.input();

	cout << endl;

	cout << "������� �������� ���������: ";

	this->airport.input();

	cout << endl;


	cout << "������� ����: ";
	cin >> this->price;
	cout << endl;

	this->date.input();
}

void Ticket::OutputAll()
{
	cout << "��� ���������: \t";
	this->name.output();

	cout << "��������: \t";
	this->airport.output();

	cout << endl << "����: \t";
	cout << this->price;

	cout << endl << "���� \t";
	this->date.output();
}

int Ticket::cmp(Ticket* t)
{
	if (name.cmp(t->name) != 0)
		return name.cmp(t->name);
	else
		if ((price - t->price) != 0)
			return price - t->price;
		else
			if (airport.cmp(t->airport) != 0)
				return airport.cmp(t->airport);
			else
				if (date.cmp(t->date) != 0)
					return date.cmp(t->date);
}

