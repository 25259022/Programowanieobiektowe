#include <iostream>
#include "tablica.h"
#include "pliki.h"
#include "menu.h"

using namespace std;

int main(){
float **tablica;
int *X;
int *Y;

menu_wyswietl (tablica,X,Y);


    /*for(int i = 0; i < Y; ++i) {
        delete [] tablica[i];
    }
    delete [] tablica;
*/
return 0;
}
