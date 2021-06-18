#include "tablica.h"
#include "pliki.h"

int read(float ***array, int *X, int *Y, const string& name) {
    fstream file;
    string line;
    file.open(name, fstream::in | fstream::out);
    if (!file.good()) { return 3; }

    file >> *Y;
    file >> *X;

    *array = tab_create(*X, *Y);


    for (int i = 0; i < *Y; i++) {

        for (int j = 0; j < *X - 1; j++) {
            getline(file, line, ',');
            (*array)[i][j] = stoi(line);
        }
        file >> (*array)[i][(*X) - 1];

    }

}


int save(float **array, int X, int Y,const string& name) {

    fstream file;
    file.open(name, ios::out);
    file << Y << endl;
    file << X;

    for (int i = 0; i < Y; i++) {
        file << endl;
        for (int j = 0; j < X - 1; j++) {
            file << array[i][j] << ",";
        }
        file << array[i][X - 1];
    }
}
