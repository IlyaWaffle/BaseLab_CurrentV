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

    friend ostream& operator<< (ostream& out, MyString& right) {
        for (int i = 0; i < right.len; i++)
            out << right.s[i];
        return out;
    }
    friend istream& operator>> (istream& in, MyString& right)
    {
        char temp[254];
        in >> temp;
        int n = 0;
        while (temp[n] != 0)
            n++;
        right.s = new char[n];
        for (int i = 0; i < n; i++)
            right.s[i] = temp[i];
        right.len = n;
        return in;
    }
    MyString& operator= (const MyString& right);
    bool operator==(const MyString& right);
    bool operator>=(const MyString& right);
    bool operator<=(const MyString& right);

    char* operator+ (const MyString& right);
    MyString& operator+= (const MyString& right);
    

};