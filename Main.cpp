#include <iostream>
#include "Ticket.h"
#include "TicketTable.h"
#include "MyDate.h"
#include "MyString.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");

    cout << "Добро пожаловать\n";
    cout << "Введите количество билетов: ";
    int n;
    cin >> n;

    TicketArray ticket(n);

    int i;
    while (1) 
    {
        i = menu();
        switch (i)
        {
            case 1: 
            {
                ticket.input();
            }
              break;
            case 2: 
            {
                ticket.output();
                break;
            }

            case 3: 
            {
                char name[25];

                cout << "Введите параметры  билета, который хотите изменить : " << endl;
                Ticket* Old = new Ticket;
                Old->inputAll();
                cout << "Введите параметры нового билета : " << endl;
                Ticket* New = new Ticket;
                New->inputAll();
                ticket.replace(Old, New);
            }
            break;
            case 4: 
            {
                char name[25];
                cout << "Введите имя пассажира: " << endl;
                cin >> name;
                if (ticket.search3((MyString)((char*)name)))
                {
                   cout << "Билет " << name << " найден" << endl;
                   cout << "Его номер в списке " << ticket.search3((MyString)((char*)name)) << endl;
                }
            }
            break;
            case 5: 
            {
                ticket.sort();
                cout << "Билеты отсортированы по возрастанию цены" << endl;
                break;
            }
            case 6: 
            {
                char name[25];
                cout << "Введите имя пассажира, чей билет необходимо удалить: " << endl;
                cin >> name;
                ticket.remove(ticket.search3((MyString)((char*)name)));
            }
            break;
            case 7: 
            {
                exit(0);
                break;
            default: 
                cout << "Ошибка" << endl;
            }
        }
    }

    return 0;
}