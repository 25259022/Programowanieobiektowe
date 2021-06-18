//
// Created by Paweł on 12/06/2021.
//

#include "table.h"

using namespace std;

int Table::tab_editcell(int axis_x, int axis_y, string value)
{
    if (X == 0 || Y == 0)
    {
        return no_table;
    }

    if (axis_x <= 0 || axis_y <= 0)
    {
        return wrong_format;
    }

    tab[axis_y - 1][axis_x - 1]->setValue(value);
    return 0;
}

int Table::tab_change(int new_x, int new_y)
{
    if (X == 0 || Y == 0)
    {
        return no_table;
    }

    if (new_x <= 0 || new_y <= 0)
    {
        return wrong_format;
    }

    Cell ***new_table;

    new_table = new Cell **[new_y];
    for (int i = 0; i < new_y; i++)
    {
        new_table[i] = new Cell *[new_x];
    }

    int smaller_y, smaller_x;
    if (X < new_x) {
        smaller_x = X;
    }
    else
    {
        smaller_x = new_x;
    }
    if (Y < new_y) {
        smaller_y = Y;
    }
    else
    {
        smaller_y = new_y;
    }


    for (int i = 0; i < smaller_y; i++)
    {
        for (int j = 0; j < smaller_x; j++)
        {
            new_table[i][j] = tab[i][j];
        }
    }

    if (X < new_x) {
        int *new_type;
        new_type = new int[new_x];

        for (int i = 0; i < X; i++)
        {
            if (new_type[i] != 0)
            {
                type[i] = 1;
            }
            else
            {
                type[i] = 0;
            }
        }

        for (int i = X; i < new_x; i++)
        {
            cout << " Wpisz jakiego typu ma byc " << i + 1 << " kolumna? int=0 string=1 " << endl;
            cin >> new_type[i];
        }
        type = new_type;

        for (int i = X; i < new_x; i++)
        {
            for (int j = 0; j < new_y; j++)
            {
                if (new_type[i] == 0)
                {
                    new_table[j][i] = new IntCell;
                }
                else
                {
                    new_table[j][i] = new StringCell;
                }
            }
        }
    }

    if (Y < new_y)
    {
        for (int i = 0; i < smaller_x; i++)
        {
            for (int j = Y; j < new_y; j++)
            {
                if (type[i] == 0)
                {
                    new_table[j][i] = new IntCell;
                }
                else
                {
                    new_table[j][i] = new StringCell;
                }
            }
        }
    }

    tab = new_table;
    X = new_x;
    Y = new_y;

    return 0;
}


int Table::tab_show()
{

    if (X == 0 || Y == 0) { return wrong_format; }

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            cout << tab[i][j]->getValue() << " ";
        }
        cout << endl;

    }
    cout << endl;
    return 0;
}

int Table::set_type(int intput_type[])
{
    type = new int[X];

    for (int i = 0; i < X; i++)
    {
        if (intput_type[i] != 0) { type[i] = 1; } else { type[i] = 0; }
    }


    for (int i = 0; i < X; i++)
    {

        for (int j = 0; j < Y; j++)
        {
            if (type[i] == 0)
            {
                tab[j][i] = new IntCell;
            }
            else
            {
                tab[j][i] = new StringCell;
            }
        }
    }

    return 0;
}

bool Table::table_exist()
{
    return table_inicialized;
}

int Table::sumRow(int row)
{
    if (row > X || row <= 0)
    {
        return wrong_format;
    }
    int sum = 0;

    for (int i = 0; i < Y; i++)
    {
        if (type[i] == 0)
        {
            sum += stoi(tab[row - 1][i]->getValue());
        }
    }
    return sum;
}


int Table::sumCol(int col)
{
    if (col > Y || col <= 0)
    {
        return wrong_format;
    }
    if (type[col - 1] != 0)
    {
        return int_col_operation_on_string_col;
    }
    int sum = 0;
    for (int i = 0; i < Y; i++)
    {
        sum += stoi(tab[i][col - 1]->getValue());
    }
    return sum;
}

int Table::findMaxInRow(int row)
{
    if (row > X || row <= 0)
    {
        return wrong_format;
    }
    int max = 0;
    for (int i = 0; i < Y; i++)
    {
        if (stoi(tab[row - 1][i]->getValue()) > max)
        {
            max = stoi(tab[row - 1][i]->getValue());
        }
    }
    return max;
}

int Table::findMaxInCol(int col)
{
    if (col > Y || col <= 0)
    {
        return wrong_format;
    }
    if (type[col - 1] != 0)
    {
        return int_col_operation_on_string_col;
    }
    double max = 0;
    for (int i = 0; i < X; i++)
    {
        if (stoi(tab[i][col - 1]->getValue()) > max)
        {
            max = stoi(tab[i][col - 1]->getValue());
        }
    }
    return max;
}

int Table::findMinInRow(int row)
{
    if (row > X || row <= 0)
    {
        return wrong_format;
    }
    int min = 2147483647;
    for (int i = 0; i < X; i++)
    {
        if (type[i] == 0 && stoi(tab[row - 1][i]->getValue()) < min)
        {
            min = stoi(tab[row - 1][i]->getValue());
        }
    }
    return min;
}

int Table::findMinInCol(int col)
{
    if (col > Y || col <= 0)
    {
        return wrong_format;
    }
    if (type[col - 1] != 0)
    {
        return int_col_operation_on_string_col;
    }
    int min = 2147483647;
    for (int i = 0; i < X; i++)
    {
        if (/*type[i]==0 &&*/ stoi(tab[i][col - 1]->getValue()) < min)
        {
            min = stoi(tab[i][col - 1]->getValue());
        }
    }
    return min;
}

double Table::findAvgInRow(int row)
{
    if (row > X || row <= 0)
    {
        return wrong_format;
    }
    int denominator = 0;
    for (int i = 0; i < X; i++)
    {
        denominator += type[i];
    }
    if (denominator == 0)
    {
        return 0;
    }
    return (sumRow(row) / Y);
}

double Table::findAvgInCol(int col)
{
    if (col > Y || col <= 0)
    {
        return wrong_format;
    }
    if (type[col - 1] != 0)
    {
        return int_col_operation_on_string_col;
    }
    return (sumCol(col) / X);
}