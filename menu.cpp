#include "menu.h"
#include "pliki.h"
#include "tablica.h"
#include <iostream>

using namespace std;

void meny_show() {
    float **array;
    int X;
    int Y;
    int choice;
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
        cout << "7.Zapisz do pliku" << endl;
        cout << endl;
        cout << "0.Wyjdz" << endl;

        cin >> choice;

        switch (choice) {

            case 1: {
                system("clear");
                cout << "Podaj wielkosc X:";
                cin.ignore();
                cin >> X;
                cout << endl << "Podaj wielkosc Y:";
                cin >> Y;
                array = tab_create(X, Y);
                break;
            }

            case 2: {
                system("clear");
                tab_remove(array, Y);
                break;
            }

            case 3: {
                system("clear");
                int nx, ny;
                cout << "Podaj nowa wielkosc X:";
                cin >> nx;
                cout << "Podaj nowa wielkosc Y:";
                cin >> ny;
                tab_change(array, &X, &Y, nx, ny);
                break;
            }

            case 4: {
                system("clear");
                tab_show(array, X, Y);
                break;
            }

            case 5: {
                system("clear");
                cout << "Podaj nazwe pliku:";
                string rname;
                cin >> rname;
                rname += ".txt";
                read(&array, &X, &Y, rname);
                break;
            }

            case 6: {
                system("clear");
                cout << "Podaj nazwe pliku:";
                string sname;
                cin >> sname;
                sname += ".txt";
                save(array, X, Y, sname);
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

                tab_editcell(array, X, Y, axis_X, axis_Y, value);
                break;
            }
        }

    } while (choice != 0);
    tab_remove(array, Y);
}

