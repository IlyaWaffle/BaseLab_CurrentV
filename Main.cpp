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

    Apteka Medicine(n);

    int i;
    while (1) {
        i = menu();
        switch (i)
        {
        case 1: {
            Medicine.input();
        }
              break;
        case 2: {
            Medicine.output();
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
            Medicine.replace(Old, New);
        }
              break;
        case 4: {
            char name[25];
            cout << "Введите имя препарата: " << endl;
            cin >> name;
            if (Medicine.search3((MyString)((char*)name)))
            {

                cout << "Препарат " << name << " найден" << endl;
                cout << "Его номер в списке " << Medicine.search3((MyString)((char*)name)) << endl;
            }
        }
              break;
        case 5: {
            Medicine.sort();
            cout << "Препараты отсортированы по возрастанию цены" << endl;
            break;
        }
        case 6: {
            char name[25];
            cout << "Введите имя препарата, который необходимо удалить: " << endl;
            cin >> name;
            Medicine.remove(Medicine.search3((MyString)((char*)name)));
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