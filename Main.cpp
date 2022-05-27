#include <iostream>
#include "Ticket.h"
#include "TicketTable.h"
#include "MyDate.h"
#include "MyString.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");

    cout << "¬ведите количество билетов";
    int n;
    cin >> n;

    TicketArray ticket(n);





    int i;
    while (1) {
        i = menu();
        switch (i)
        {
        case 1: {
            ticket.input();
        }
              break;
        case 2: {
            ticket.output();
            break;
        }

        case 3: {
            char name[25];

            cout << "¬ведите параметры  билета, который хотите изменить : " << endl;
            Ticket* Old = new Ticket;
            Old->inputAll();
            cout << "¬ведите параметры нового билета : " << endl;
            Ticket* New = new Ticket;
            New->inputAll();
            ticket.replace(Old, New);
        }
              break;
        case 4: {
            char name[25];
            cout << "¬ведите им€ пассажира: " << endl;
            cin >> name;
            if (ticket.search3((MyString)((char*)name)))
            {

                cout << "Ѕилет " << name << " найден" << endl;
                cout << "≈го номер в списке " << ticket.search3((MyString)((char*)name)) << endl;
            }
        }
              break;
        case 5: {
            ticket.sort();
            cout << "Ѕилеты отсортированы по возрастанию цены" << endl;
            break;
        }
        case 6: {
            char name[25];
            cout << "¬ведите им€ пассажира, чей билет необходимо удалить: " << endl;
            cin >> name;
            ticket.remove(ticket.search3((MyString)((char*)name)));
        }
              break;
        case 7: {
            exit(0);
            break;
        default: cout << "ќшибка" << endl;
        }
        }
    }

    return 0;
}