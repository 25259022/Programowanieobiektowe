using namespace std;

/// operations on table
/**
* This class is responsible for all operations on table in program. All data is stored with help of 2 dimension pointer table. in addition lenght of axis x and y is stored in int x and y accordingly.
*/
class Table
{
    int X;
    int Y;
    int *tablica= new int [X,Y];


public:
/// creates new table
/**
* creates new table from scratch. running this function is nessecary before running: tab_add and tab_wysw. those operation require table which is created by tab_create.
*/
/**
 * @param[in] x - column number
 * @param[in] y - row number
 */
Table (int x, int y)
    {


    }

///edits chosen by user cell
/**
*@param[out] arr - Table for editting
*@param[in] axis_x - column number
*@param[in] axis_y - row number
 * *@param[in] value - value for replacing
**/
void tab_editcell(Table arr, int axis_x, int axis_y, int value);


/// adds new data to existing table
void tab_add();




};
