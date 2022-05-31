#include "Ticket.h"
#include "TicketTable.h"
#include <iostream>
#include <string>
using namespace std;

int menu() {
	int a;
	cout << endl << "***********MENU***********" << endl;
	cout << "(1) ����������" << endl;
	cout << "(2) ������ �� �����" << endl;
	cout << "(3) ���������" << endl;
	cout << "(4) �������� �� �������������" << endl;
	cout << "(5) ����������" << endl;
	cout << "(6) ��������" << endl;
	cout << "(7) ����� �� ���������" << endl;
	cout << "***************************" << endl;
	cout << "�������� ����� �������: ";
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

TicketArray::TicketArray(int sz) :v(sz) {
	cur = begin();
}


//����
int TicketArray::input() {
	int nlines = cur - begin();
	if (nlines++ >= v.get_size()) return 0;
	T* a;
	a = new T;
	a->inputAll();
	cur = this->insert(a);
	return cur - begin();

	cout << "=================================" << endl;
}


//�����
void TicketArray::output() {
	cout << "=================================" << endl;
	for (T** t = begin(); t != cur; t++) {
		(*t)->OutputAll();
		cout << "=================================" << endl;
	}
}

#include<algorithm>
//����������
void TicketArray::sort() {

	for (int j = 0; j < cur - begin() - 1; j++)
		for (int i = 0; i < cur - begin() - j - 1; i++)
			if (v.item(i)->cmp(v.item(i + 1)) > 0)
			{
				T* tmp = v.item(i);
				v.item(i) = v.item(i + 1);
				v.item(i + 1) = tmp;
			}


}






//��������
int TicketArray::remove(T* d) {
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


int TicketArray::replace(T* Old, T* New) {

	int n = 0;
	for (int i = 0; i < lenght(); i++)
		if ((v.item(i))->cmp(Old) == 0)
		{
			v.item(i) = New->copy(); n++;

		}
	if (n == 0) return 0;
	return 1;
}


//�����, ������� ���������� �������
int TicketArray::search(T* item) {

	T** i;
	for (i = begin(); i < cur; i++)
		if ((*i)->cmp(item) == 0) return i - begin();
	return -1;
}





//����������
TicketArray::~TicketArray() {

	for (T** t = begin(); t != cur; t++)
		delete* t;


}

T** TicketArray::begin()
{
	return v.begin();
}

T** TicketArray::end()
{
	return cur;
}

T** TicketArray::insert(T* t)
{
	if (lenght() >= v.get_size()) return 0;
	*cur++ = t->copy();
	return cur;

}

int TicketArray::lenght()
{
	return cur - v.begin();
}

void TicketArray::erase(int p)
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

int TicketArray::search1(MyString a)
{
	for (int i = 0; i < cur - v.begin() - 1; i++)
	{
		if ((*v.begin() + i)->getName().cmp(a) == 0) {
			return i;
		}

	}
	return -1;
}

int TicketArray::replace1(int index)
{

	Ticket* rep = new Ticket();

	rep->inputAll();
	*(v.begin() + index) = rep;

	return 0;

	/*int n = 0;
	for (int i = 0; i < lenght(); i++)
		if ((v.item(i))->cmp(Old) == 0)
		{
			v.item(i) = New->copy(); n++;

		}
	if (n == 0) return 0;
	return 1;*/
}

T* TicketArray::search2(MyString a)
{

	for (int i = 0; i < cur - v.begin() - 1; i++)
	{
		if ((*v.begin() + i)->getName().cmp(a) == 0) {
			return (*v.begin() + i);
		}

	}
	return nullptr;
}

T* TicketArray::search3(char* a)
{
	T** i;
	for (i = begin(); i < cur; i++)
		if ((*i)->getName().cmp(a) == 0) return *i;

	return nullptr;
}