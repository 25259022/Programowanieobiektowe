#include "table.h"
#include <iostream>
#include <fstream>
#include <string>


int Table::read(string name)
{
    fstream file;
    string line;
    file.open(name, fstream::in | fstream::out);
    if (!file.good())
    {
        return file_open_err;
    }

    int new_y, new_x;

    file >> new_y;
    file >> new_x;

    Cell ***new_table;

    new_table = new Cell **[new_y];
    for (int i = 0; i < new_y; i++)
    {
        new_table[i] = new Cell *[new_x];
    }


    int newtype[new_x];

    for (int j = 0; j < new_x; j++)
    {
        getline(file, line, ',');
        newtype[j] = stoi(line);
    }

    for (int i = 0; i < new_x; i++)
    {

        for (int j = 0; j < new_y; j++)
        {

            if (newtype[i] == 0)
            {
                new_table[j][i] = new IntCell;
            }
            else {
                new_table[j][i] = new StringCell;
            }
        }
    }
    for (int i = 0; i < new_y; i++)
    {

        for (int j = 0; j < new_x; j++)
        {
            getline(file, line, ',');
            new_table[i][j]->setValue(line);
        }


    }

    tab = new_table;
    X = new_x;
    Y = new_y;
    type = new int[X];
    for (int i = 0; i < X; i++)
    {
        if (newtype[i] != 0)
        {
            type[i] = 1;
        }
        else
        {
            type[i] = 0;
        }
    }

    return 0;
}

int Table::save(string name)
{
    fstream file;
    file.open(name, ios::out);
    if (!file.good())
    {
        return file_open_err;
    }
    file << Y << endl;
    file << X << endl;

    for (int i = 0; i < X; i++)
    {
        file << type[i] << ",";
    }
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            file << tab[i][j]->getValue() << ",";
        }

    }
    return 0;
}

