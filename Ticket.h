#pragma once
#include "MyDate.h" 
#include "MyString.h"
class Ticket {
private:
    MyString name;
    MyString airport;
    MyDate date;
    double price;
public:
    Ticket();
    Ticket(MyString Name, MyString Airport, int day, int month, int year, double price);//инциализация
    ~Ticket();

    Ticket(const Ticket& a);

    MyString& getName() { return name; }
    MyString& getAirport() { return airport; }
    double getPrice() { return price; }
    MyDate getDate() { return date; }

    void setOwner(MyString aName) { name = aName; }
    void setAirport(MyString aAirport) { airport = aAirport; }
    void setOwner(double aPrice) { price = aPrice; }
    void setOwner(MyDate aDate) { date = aDate; }
    Ticket* copy();



    void inputAll();
    void OutputAll();
    int cmp(Ticket* t);

    friend ostream& operator<< (ostream& out, Ticket& right);
    friend istream& operator>> (istream& in, Ticket& right);
};
