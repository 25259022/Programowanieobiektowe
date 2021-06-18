#include "menu.h"
#include <iostream>
#include "table.h"
using namespace std;

void menu_show() {
    int choice;
    Table main_tab(0,0);
    do {
        cout << "         Menu" << endl;
        cout << "1.Utworz arkusz" << endl;
        cout << "2.Usun arkusz" << endl;
        cout << "3.Zmien rozmiar arkusza" << endl;
        cout << "4.Wyswietl arkusz" << endl;
        cout << "-----------------" << endl;
        cout << "5.Wczytaj z pliku" << endl;
        cout << "6.Zapisz do pliku" << endl;
        cout << "-----------------" << endl;
        cout << "7.Edytuj komorke" << endl;
        cout << endl;
        cout << "0.Wyjdz" << endl;

        cin >> choice;


        switch (choice) {


            case 1: {
                //system("clear");
                int X, Y;
                cout << "Podaj wielkosc X:";
                cin.ignore();
                cin >> X;
                cout << endl << "Podaj wielkosc Y:";
                cin >> Y;
                main_tab.tab_build(X,Y);

                break;
            }

            case 2: {
                system("clear");
                main_tab.tab_remove();
                break;
            }

            case 3: {
                system("clear");
                int nx, ny;
                cout << "Podaj nowa wielkosc X:";
                cin >> nx;
                cout << "Podaj nowa wielkosc Y:";
                cin >> ny;
                main_tab.tab_change(nx, ny);
                break;
            }

            case 4: {
                system("clear");
                main_tab.tab_show();
                break;
            }

            case 5: {
                system("clear");
                cout << "Podaj nazwe pliku:";
                string rname;
                cin >> rname;
                rname += ".txt";
                main_tab.read(rname);
                break;
            }

            case 6: {
                system("clear");
                cout << "Podaj nazwe pliku:";
                string sname;
                cin >> sname;
                sname += ".txt";
                main_tab.save(sname);
                break;
            }

            case 7: {
                system("clear");
                cout << "Podaj adres X";
                int axis_X;
                cin >> axis_X;

                cout << "Podaj adres Y";
                int axis_Y;
                cin >> axis_Y;

                cout << "Podaj wartosc";
                int value;
                cin >> value;

                main_tab.tab_editcell(axis_X, axis_Y, value);
                break;
            }



        }
    }
        while (choice != 0);

}
