#include "menu.h"
#include "menu.h"
#include <iostream>
#include "table.h"

using namespace std;

void menu_show()
{
    int choice;
    Table *main_tab;
    main_tab = new Table(0, 0);

    do
    {
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
        cout << "8.Opercaje na wierszach" << endl;
        cout << "9.Opercaje na kolumnach" << endl;
        cout << endl;
        cout << "0.Wyjdz" << endl;

        cin >> choice;

        switch (choice)
        {
            case 1: {
                //system("clear");
                int X, Y;
                cout << "Podaj wielkosc X:";
                cin.ignore();
                cin >> X;
                cout << endl << "Podaj wielkosc Y:";
                cin >> Y;
                main_tab = new Table(X, Y);
                if (main_tab->table_exist()) {
                    int int_type[X];
                    for (int i = 0; i < X; i++) {
                        cout << " Wpisz jakiego typu ma byc " << i + 1 << " kolumna? int=0 string=1 " << endl;
                        cin >> int_type[i];
                    }
                    main_tab->set_type(int_type);
                }

                break;
            }

            case 2:
            {
                system("clear");
                if (main_tab->table_exist())
                {
                    delete main_tab;
                }
                else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                }
                break;
            }

            case 3:
            {
                system("clear");
                if (main_tab->table_exist())
                {
                    int nx, ny;
                    cout << "Podaj nowa wielkosc X:";
                    cin >> nx;
                    cout << "Podaj nowa wielkosc Y:";
                    cin >> ny;


                    main_tab->tab_change(nx, ny);
                }
                else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                }
                break;
            }

            case 4: {
                system("clear");
                if (main_tab->table_exist())
                {
                    main_tab->tab_show();
                }
                else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                }
                break;
            }

            case 5: {
                system("clear");
                if (main_tab->table_exist())
                {
                    cout << "Podaj sciezke pliku:";
                    string rname;
                    cin >> rname;
                    rname += ".txt";
                    main_tab->read(rname);
                } else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                }
                break;
            }

            case 6: {
                if (main_tab->table_exist())
                {
                    system("clear");
                    cout << "Podaj nazwe pliku:";
                    string sname;
                    cin >> sname;
                    sname += ".txt";
                    main_tab->save(sname);
                } else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                }
                break;
            }

            case 7: {
                if (main_tab->table_exist())
                {
                    system("clear");
                    cout << "Podaj adres X";
                    int axis_X;
                    cin >> axis_X;

                    cout << "Podaj adres Y";
                    int axis_Y;
                    cin >> axis_Y;

                    cout << "Podaj wartosc";
                    string value;
                    cin >> value;

                    main_tab->tab_editcell(axis_X, axis_Y, value);
                }
                else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                }
                break;
            }

            case 8: {
                if (main_tab->table_exist())
                {
                    cout << "1. Zsumuj wiersze" << endl;
                    cout << "2. Znajdz wartosc maksymalna" << endl;
                    cout << "3. Znajdz wartosc minimalna" << endl;
                    cout << "4. Znajdz srednia" << endl;
                    cout << "Wybierasz: ";
                    int choice_math_operation;
                    cin >> choice_math_operation;
                    cout << "Wprowadz numer wiersza: ";
                    int cellId;
                    cin >> cellId;
                    switch (choice_math_operation) {
                        case 1:
                            cout << "Suma komorek w wierszu: " << main_tab->sumRow(cellId) << endl;
                            break;
                        case 2:
                            cout << "Maksymalna wartosc w wierszu: " << main_tab->findMaxInRow(cellId) << endl;
                            break;
                        case 3:
                            cout << "Minimalna wartosc w wierszu: " << main_tab->findMinInRow(cellId) << endl;
                            break;
                        case 4:
                            cout << "Srednia wartosc w wierszu: " << main_tab->findAvgInRow(cellId) << endl;
                            break;
                        default:
                            system("clear");
                            cout << "Wybrales niewlasciwa opcje!";
                            break;
                    }
                    break;
                } else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                }
            }

            case 9: {
                if (main_tab->table_exist())
                {
                    int choice_math_operation;
                    cout << "1. Zsumuj kolumny" << endl;
                    cout << "2. Znajdz wartosc maksymalna" << endl;
                    cout << "3. Znajdz wartosc minimalna" << endl;
                    cout << "4. Znajdz srednia" << endl;
                    cout << "Wybierasz: ";
                    cin >> choice_math_operation;
                    cout << "Wprowadz numer kolumny: ";
                    int cellId;
                    cin >> cellId;
                    switch (choice_math_operation) {
                        case 1:
                            cout << "Suma komorek w kolumnie: " << main_tab->sumCol(cellId) << endl;
                            break;
                        case 2:
                            cout << "Maksymalna wartosc w kolumnie: " << main_tab->findMaxInCol(cellId) << endl;
                            break;
                        case 3:
                            cout << "Minimalna wartosc w kolumnie: " << main_tab->findMinInCol(cellId) << endl;
                            break;
                        case 4:
                            cout << "Srednia wartosc w kolumnie: " << main_tab->findAvgInCol(cellId) << endl;
                            break;
                        default:
                            system("clear");
                            cout << "Wybrales niewlasciwa opcje!";
                            break;
                    }
                    break;
                }
                else
                {
                    cout << endl << "Potrzebna tablica do tej akcji" << endl;
                };

                default:
                    system("clear");
                cout << "Wybrales niewlasciwa opcje!";
                break;
            }
        }
    }
    while (choice != 0);
}
