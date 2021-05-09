#include <iostream>
#include <string>

const int file_open_err=1;
const int wrong_format=2;
const int no_table=3;

using namespace std;

/// Main table class
/**
* this class stores information about axis X and axis Y. It also stores table content. inside of this class are also functions responsible for main functions of program.
*/
/**
 * @param[in,out] X - Axis X lenght
 * @param[in,out] Y - Axis Y lenght
 */
class Table {
private:

    int X;
    int Y;
    float **tab;

    /// creates new table
/**
* creates new table from scratch. running this function is nessecary before running functions working on table content. those operation require table which is created by tab_create.
*/
    int tab_create();

public:
Table(int x, int y){
    tab_build(x,y);
    }

/// asks tab_create to build table
/**
* Takes X and Y lenght. checks if they are in correct format. then checks if there is already table created, if yes deletes it then asks tab_create to create table from chceked values X and Y.
*/
/**
 * @param[in] nx - Axis X lenght for new table
 * @param[in] ny - Axis Y lenght for new table
 */
    int tab_build(int nx,int ny);

    /// removes table.
/**
* Removes table content and X and Y values;
 */

    int tab_remove();

    ///edits chosen by user cell
/**
* @param[in] axis_x - column number for changing
* @param[in] axis_y - row number for changing
* @param[in] value - value for replacing
**/

    int tab_editcell(int axis_x, int axis_y, int value);

    /// adds new data to existing table
/**
 * * @param[in] nx - new column number
* @param[in] ny - new row number
**/

    int tab_change(int nx, int ny);

    ///Shows content of table
/**
*outputs to console content of existing table.
**/

    int tab_show();

    ///saves from file to Table class
/**
*@param[out] name - String storing file name choosed to read from.
**/

    int save(string name);

    ///takes info from existing table and saves it into file
/**
*@param[out] name - String storing saving file name.
**/

    int read(string name);


};


