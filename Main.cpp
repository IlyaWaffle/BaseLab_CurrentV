#include <iostream>
#include "Ticket.h"
#include "TicketTable.h"
#include "MyDate.h"
#include "MyString.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");

    cout << "����� ����������\n";
    cout << "������� ���������� �������: ";
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

                cout << "������� ���������  ������, ������� ������ �������� : " << endl;
                Ticket* Old = new Ticket;
                Old->inputAll();
                cout << "������� ��������� ������ ������ : " << endl;
                Ticket* New = new Ticket;
                New->inputAll();
                ticket.replace(Old, New);
            }
            break;
            case 4: 
            {
                char name[25];
                cout << "������� ��� ���������: " << endl;
                cin >> name;
                if (ticket.search3((MyString)((char*)name)))
                {
                   cout << "����� " << name << " ������" << endl;
                   cout << "��� ����� � ������ " << ticket.search3((MyString)((char*)name)) << endl;
                }
            }
            break;
            case 5: 
            {
                ticket.sort();
                cout << "������ ������������� �� ����������� ����" << endl;
                break;
            }
            case 6: 
            {
                char name[25];
                cout << "������� ��� ���������, ��� ����� ���������� �������: " << endl;
                cin >> name;
                ticket.remove(ticket.search3((MyString)((char*)name)));
            }
            break;
            case 7: 
            {
                exit(0);
                break;
            default: 
                cout << "������" << endl;
            }
        }
    }

    return 0;
}