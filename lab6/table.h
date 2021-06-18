#include <iostream>
#include <string>
#include "cell.h"

const int file_open_err = -1;
const int wrong_format = -525;
const int no_table = -3;
const int int_col_operation_on_string_col = -5;

using namespace std;

/// Main table class
/**
* this class stores information about axis X and axis Y. It also stores table content. inside of this class are also functions responsible for main functions of program.
*/
/**
 * @param[in,out] X - Axis X lenght
 * @param[in,out] Y - Axis Y lenght
 * @param[in,out] *type - Pointer to int table storing type of cell
 * @param[in,out] ***tab - 2 dimensions table storing pointers to Cell clases.
 * @param[in,out] table_inicialized - Bool variable informing on table status
 */
class Table
        {
private:
    int *type;
    int X;
    int Y;
    Cell ***tab;
    bool table_inicialized = false;


    /// creates new table
/**
* creates new table from scratch. running this function is nessecary before running functions working on table content. those operation require table which is created by tab_create.
 * @param[in] x - Axis X requested lenght
 * @param[in] y - Axis Y requested lenght
 */

public:
    Table(int x, int y)
    {
        if (x < 0 || y < 0)
        {
            cout << "wrong_format";
        }
        else
        {
            X = x;
            Y = y;

            tab = new Cell **[Y];
            for (int i = 0; i < Y; i++)
            {
                tab[i] = new Cell *[X];
            }
            table_inicialized = true;
        }
    }

    /// removes table.
/**
* Removes table content.
 */

    ~Table()
    {
        for (int i = 0; i < Y; i++)
        {
            delete[] *tab[i];
        }
        delete[] tab;
        delete type;

        table_inicialized = false;

    }


    int set_type(int intput_type[]);



    ///edits chosen by user cell
/**
* @param[in] axis_x - column number for changing
* @param[in] axis_y - row number for changing
* @param[in] value - value for replacing
**/

    int tab_editcell(int axis_x, int axis_y, string value);

    /// adds new data to existing table
/**
* @param[in] nx - new column number
* @param[in] ny - new row number
**/

    int tab_change(int nx, int ny);

    ///Shows content of table
/**
*outputs to console content of existing table.
**/

    int tab_show();

    ///reads from txt file and saves to Table class
/**
*@param[out] name - String storing file name choosed to read from.
**/

    int save(string name);

    ///takes info from existing table and saves it into file
/**
*@param[out] name - String storing saving file name.
**/

    int read(string name);

    ///checks if table is inicialized

    bool table_exist();

    ///Sums up all int type cells from requested row
/**
*@param[in] row - requested row to sum up.
*@param[out] sum - stores result.
**/

    int sumRow(int row);

    ///Sums up all int type cells from requested column
/**
*@param[in] col - requested col to sum up.
*@param[out] sum - stores result.
**/


    int sumCol(int col);

    ///Finds max int type cell from requested row
/**
*@param[in] row - requested row to check.
*@param[out] max - stores result.
**/

    int findMaxInRow(int row);

    ///Finds max int type cell from requested column
/**
*@param[in] row - requested col to check.
*@param[out] max - stores result.
**/

    int findMaxInCol(int col);

    ///Finds min int type cell from requested row
/**
*@param[in] row - requested row to check.
*@param[out] min - stores result.
**/

    int findMinInRow(int row);

    ///Finds min int type cell from requested column
/**
*@param[in] row - requested col to check.
*@param[out] min - stores result.
**/

    int findMinInCol(int col);

    ///returns average of int type cell from requested row
/**
*@param[in] row - requested row to check.
**/

    double findAvgInRow(int row);

    ///returns average of int type cell from requested column
/**
*@param[in] col - requested row to check.
**/

    double findAvgInCol(int col);
};
