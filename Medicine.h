#pragma once
#include "MyDate.h" 
#include "MyString.h"
class Medicine {
private:
    MyString name;
    MyString group;
    MyDate date;
    double count;
    double price
public:
    Medicine();
    Medicine(MyString name, MyString group, int day, int month, int year, double price);//инциализация
    ~Medicine();

    Medicine(const Medicine& a);

    MyString& getName() { return name; }
    MyString& getGroup() { return Group; }
    double getPrice() { return price; }
    MyDate getDate() { return date; }

    void setOwner(MyString aName) { name = aName; }
    void setGroup(MyString aGroup) { gropu = aGroup; }
    void setCount(double aCount) { cout = aCount; }
    void setOwner(double aPrice) { price = aPrice; }
    void setOwner(MyDate aDate) { date = aDate; }
    Medicine* copy();



    void inputAll();
    void OutputAll();
    int cmp(Medicine* t);
};
