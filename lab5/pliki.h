#include <iostream>
#include <fstream>
#include <string>

using namespace std;
///Saving/Reading table to/from file


///saves from file to Table class
/**
*@param[out] array - Table for storing table from file
*@param[out] X - Axis X lenght
*@param[out] Y - Axis Y lenght
**/

int read(float ***array, int *X, int *Y, const string& name);

///takes info from existing table and saves it into file
/**
*@param[in] array - Table for saving to file
*@param[in] X - Axis X lenght
*@param[in] Y - Axis Y lenght
**/
int save(float **array, int X, int Y,const string& name);

