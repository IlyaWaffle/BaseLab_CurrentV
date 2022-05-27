#pragma once
#include "MyString.h"
#include <string>
#include <iostream>

//#pragma warning(disable : 4996)

using namespace std;

MyString::MyString()
{
	s = new char[0];
	len = 0;
}
MyString::MyString(char* t)
{
	int n = 0;
	while (t[n] != NULL)
		n++;

	s = new char[n];
	for (int i = 0; i < n; i++)
		s[i] = t[i];
	len = n;

	/*s = new char[strlen(t)];
	for (size_t i = 0; i < strlen(t); i++)
	{
		s[i] = t[i];
	}
	len = strlen(t);*/
}
MyString::MyString(const char t[])
{
	int n = 0;
	while (t[n] != NULL)
		n++;

	s = new char[n];
	for (int i = 0; i < n; i++)
		s[i] = t[i];
	len = n;
	/*s = new char[strlen(t)];
	for (size_t i = 0; i < strlen(t); i++)
	{
		s[i] = t[i];
	}
	len = strlen(t);*/
}
MyString::MyString(const MyString& u)
{
	int n = 0;
	while (u.s[n] != NULL)
		n++;

	s = new char[n];
	for (int i = 0; i < n; i++)
		s[i] = u.s[i];
	len = n;

	/*s = new char[u.len];
	strcpy(s, u.s);
	len = u.len;*/
}
MyString::~MyString()
{
	delete[] s;
	len = 0;
}
char& MyString::item(int t)
{
	char err = 'e';
	if (t <= len && t >= 0)
		return s[t];
	else
		cout << "Error.";
	return err;
}
MyString* MyString::copy()
{
	return new MyString(*this);
}
void MyString::assign(const MyString& u)
{
	s = new char[u.len];
	for (int i = 0; i < u.len; i++)
		s[i] = u.s[i];
	len = u.len;
}
int MyString::cmp(const MyString& t)
{
	return strcmp(s, t.s);
}
int MyString::equal(const MyString& t)
{
	return strcmp(s, t.s) == 0;
}
int MyString::input()
{

	if (cin.eof())return 0;
	char buf1[256];
	cin.getline(buf1, 254);
	if (strlen(buf1) == 0) cin.getline(buf1, 254);
	s = new char[strlen(buf1)]; len = strlen(buf1);
	*s = '\0';
	for (int i = 0; i < len; i++)
		s[i] = buf1[i];
	//strcpy(s, buf1);
	return 0;

	/*if (cin.eof()) return 0;
	char buf1[256];
	cin.getline(buf1, 254, '\n');
	int n = strlen(buf1);
	if (strlen(buf1) == 0) cin.getline(buf1, 254, '\n');
	//while (buf1[n] != NULL && buf1[n] != '\0' && buf1[n] != '\n')
		//n++;
	//delete[] s;
	s = new char[strlen(buf1)];
	len = n;
	for (int i = 0; i < len; i++)
		s[i] = buf1[i];
	return 0;*/
}
void MyString::output() {
	for (int i = 0; i < len; i++)
		cout << s[i];
	cout << endl;
}

char* MyString::operator+ (const MyString& right) {
	char* temp = new char[len + right.len];

	cout << len << " " << right.len << " " << len + right.len;

	for (int i = 0; i < len; i++) {
		temp[i] = s[i];
	}
	for (int i = 0; i < right.len; i++) {
		temp[i + len] = right.s[i];
	}
	return temp;
}

MyString& MyString::operator=(const MyString& right) {
	if (this == &right && &right == NULL)
		return *this;
	s = new char[right.len];
	for (int i = 0; i < right.len; i++) {
		s[i] = right.s[i];
	}
	len = right.len;
	return *this;
}

MyString& MyString::operator+= (const MyString& right) {
	char* temp = new char[len + right.len];

	for (int i = 0; i < len; i++) {
		temp[i] = s[i];
	}
	for (int i = 0; i < right.len; i++) {
		temp[i + len] = right.s[i];
	}
	s = temp;
	len += right.len;
	return *this;
}

bool MyString::operator==(const MyString& right) {
	if (len != right.len) return false;
	for (int i = 0; i < len; i++)
		if (s[i] != right.s[i]) return false;
	return true;
}