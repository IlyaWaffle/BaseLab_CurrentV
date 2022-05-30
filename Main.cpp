#include <iostream>
#include "Medicine.h"
#include "Apteka.h"
#include "MyDate.h"
#include "MyString.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");

    cout << "Введите количество препаратов: ";
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

            cout << "Введите параметры  препарата, который хотите изменить : " << endl;
            Medicine* Old = new Medicine;
            Old->inputAll();
            cout << "Введите параметры нового препарата : " << endl;
            Medicine* New = new Medicine;
            New->inputAll();
            medicines.replace(Old, New);
        }
              break;
        case 4: {
            char name[25];
            cout << "Введите имя препарата: " << endl;
            if (medicines.search3((MyString)((char*)name)))
            {
                cout << "Препарат " << name << " найден" << endl;
                cout << "Его номер в списке " << medicines.search2((MyString)((char*)name)) << endl;
            }
            else
                cout << "Такого препарата не найдено" << endl;
        }
              break;
        case 5: {
            medicines.sort();
            cout << "Препараты отсортированы по возрастанию количества" << endl;
            break;
        }
        case 6: {
            char name[25];
            cout << "Введите имя препарата, который необходимо удалить: " << endl;
            cin >> name;
            medicines.remove(medicines.search3((MyString)((char*)name)));
        }
              break;
        case 7: {
            exit(0);
            break;
        default: cout << "Ошибка" << endl;
        }
        }
    }

    return 0;
}