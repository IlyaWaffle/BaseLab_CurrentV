#pragma once
#include "Ticket.h"
#include "vec.h"
class TicketArray {
private:
	vec v;
	T** cur;
public:
	TicketArray(int n);


	int remove(T* d);
	int replace(T* Old, T* New);
	int search(T* item);

	void sort();
	int input();
	void output();
	~TicketArray();

	T** begin();
	T** end();
	T** insert(T* t);
	int lenght();
	void erase(int p);

	int search1(MyString a);
	int replace1(int index);
	T* search2(MyString a);
	T* search3(char* a);

};



int menu();