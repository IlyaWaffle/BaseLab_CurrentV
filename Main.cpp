#include <iostream>
#include "Medicine.h"
#include "Apteka.h"
#include "MyDate.h"
#include "MyString.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");

    /*Medicine a;
    a.setOwner(MyString("Abc"));
    a.setGroup(MyString("B"));
    a.setCount(40);
    a.setOwner(120);
    MyDate date;
    date.input();
    a.setOwner(date);

    cout << a;*/

    MyDate date;
    date.input();

    cout << date;


    /*
    cout << "������� ���������� ����������: ";
    int n;
    cin >> n;

    Apteka medicines(n);

    int i;
    while (1) {
        i = menu();
        switch (i)
        {
        case 1: {
            medicines.input();
        }
              break;
        case 2: {
            medicines.output();
            break;
        }

        case 3: {
            char name[25];

            cout << "������� ���������  ���������, ������� ������ �������� : " << endl;
            Medicine* Old = new Medicine;
            Old->inputAll();
            cout << "������� ��������� ������ ��������� : " << endl;
            Medicine* New = new Medicine;
            New->inputAll();
            medicines.replace(Old, New);
        }
              break;
        case 4: {
            char name[25];
            cout << "������� ��� ���������: " << endl;
            cin >> name;
            if (medicines.search3((MyString)((char*)name)))
            {

                cout << "�������� " << name << " ������" << endl;
                cout << "��� ����� � ������ " << medicines.search3((MyString)((char*)name)) << endl;
            }
        }
              break;
        case 5: {
            medicines.sort();
            cout << "��������� ������������� �� ����������� ����������" << endl;
            break;
        }
        case 6: {
            char name[25];
            cout << "������� ��� ���������, ������� ���������� �������: " << endl;
            cin >> name;
            medicines.remove(medicines.search3((MyString)((char*)name)));
        }
              break;
        case 7: {
            exit(0);
            break;
        default: cout << "������" << endl;
        }
        }
    }*/

    return 0;
}