#include "tablica.h"
#include <iostream>

using namespace std;

void tab_create (float **tablica,int X,int Y)
        {
        tablica = new float *[Y];
        for ( int i = 0; i < Y; ++i )
        tablica[i] = new float [X];
        }

void tab_editcell( float **tablica, int X, int Y,int axis_x,int axis_y, int value);


void tab_add(float **tablica, int *X, int *Y, bool choice, int value);


