#include "menu.h"
#include "pliki.h"
#include "tablica.h"
#include <iostream>

using namespace std;

void menu_wyswietl (float **tablica, int *X,int *Y)
{
    int wybor;
    cin>>wybor;

    switch (wybor)
    {
        case 1:
            cin>>*X;
            cin>>*Y;
            tab_create (tablica,*X,*Y);
            break;
    }

}

