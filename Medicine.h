#pragma once
#include "MyDate.h" 
#include "MyString.h"
class Medicine {
private:
    MyString name;
    MyString group;
    MyDate date;
    double count;
    double price;
public:
    Medicine();
    Medicine(MyString name, MyString group, int day, int month, int year, double price, double count);//инциализация
    ~Medicine();

    Medicine(const Medicine& a);

    MyString& getName() { return name; }
    MyString& getGroup() { return group; }
    double getPrice() { return price; }
    MyDate getDate() { return date; }
    double getCount() { return count; }

    void setOwner(MyString aName) { name = aName; }
    void setGroup(MyString aGroup) { group = aGroup; }
    void setCount(double aCount) { count = aCount; }
    void setOwner(double aPrice) { price = aPrice; }
    void setOwner(MyDate aDate) { date = aDate; }
    Medicine* copy();



    void inputAll();
    void OutputAll();
    int cmp(Medicine* t);
};
