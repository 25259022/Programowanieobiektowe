#include "tablica.h"
#include <iostream>

using namespace std;


float **tab_create(int X, int Y) {
    auto **array = new float *[Y];
    for (int i = 0; i < Y; i++) {
        (array)[i] = new float[X];
    }

    return array;
}


void tab_remove(float **array, int Y) {
    for (int i = 0; i < Y; ++i) {
        delete[] array[i];
    }
    delete[] array;

}


int tab_editcell(float **array, int X, int Y, int axis_x, int axis_y, int value) {
    if (axis_x < 0 || axis_x > X || axis_y < 0 || axis_y > Y) {
        return 3;
    }
    array[axis_y][axis_x] = value;
    return 0;
}


float **tab_change(float **array, int *X, int *Y, int new_x, int new_y) {
    float **new_table = tab_create(new_x, new_y);

    int smaller_y, smaller_x;

    if (*Y <= new_y) { smaller_y = *Y; }
    else { smaller_y = new_y; }

    if (*X <= new_x) { smaller_x = *X; }
    else { smaller_x = new_x; }

    for (int i = 0; i < smaller_y; i++) {
        for (int j = 0; j < smaller_x; j++) {
            new_table[i][j] = array[i][j];
        }
    }

    tab_remove(array, *Y);
    *X = new_x;
    *Y = new_y;
    return new_table;
}


int tab_show(float **array, int X, int Y) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;

    }

}
