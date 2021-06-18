#include "table.h"
#include <iostream>
#include <fstream>
#include <string>



int Table::read(const string name){
    fstream file;
    string line;
    file.open(name, fstream::in | fstream::out);
    if (!file.good()) { return file_open_err; }

    //tab_remove();
    file >> Y;
    file >> X;
    tab_create();


    for (int i = 0; i < Y; i++) {

        for (int j = 0; j < X - 1; j++) {
            getline(file, line, ',');
            (tab)[i][j] = stoi(line);
        }
        file >> (tab)[i][X - 1];

    }

    return 0;
}

int Table::save(const string name){
    fstream file;
    file.open(name, ios::out);
    if (!file.good()) { return file_open_err; }
    file << Y << endl;
    file << X;

    for (int i = 0; i < Y; i++) {
        file << endl;
        for (int j = 0; j < X - 1; j++) {
            file << tab[i][j] << ",";
        }
        file << tab[i][X - 1];
    }
    return 0;
}
