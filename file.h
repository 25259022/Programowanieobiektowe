#include <string>
#include <iostream>
#include <fstream>
#ifndef PROGRAMOWANIE_2_FILE_H
#define PROGRAMOWANIE_2_FILE_H

using namespace std;

///saves from file to Table class
/**
*@param[out] name - String storing file name choosed to read from.
**/

int save(const string name);

///takes info from existing table and saves it into file
/**
*@param[out] name - String storing saving file name.
**/

int read(const string name);


#endif
