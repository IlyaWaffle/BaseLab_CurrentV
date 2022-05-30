#pragma once
#include <string>
#include <iostream>

using namespace std;

class MyString {
private:
    char* s;
    int len;
public:
    MyString();
    MyString(const MyString&);
    MyString(char*);
    MyString(const char[]);
    ~MyString();
    char& item(int);
    MyString* copy();
    void assign(const MyString&);
    int cmp(const MyString&);
    int equal(const MyString&);
    int input();
    void output();

};