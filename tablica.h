using namespace std;






/// creates new table
/**
* creates new table from scratch. running this function is nessecary before running: tab_add and tab_wysw. those operation require table which is created by tab_create.
*/
/**
 * @param[in] X - Axis X lenght
 * @param[in] Y - Axis Y lenght
 */
void tab_create(float **tablica,int X, int Y);


///edits chosen by user cell
/**
*@param[out] tablica - Table for editting
* @param[in] X - Axis X lenght
* @param[in] Y - Axis Y lenght
* @param[in] axis_x - column number for changing
* @param[in] axis_y - row number for changing
* @param[in] value - value for replacing
**/
void tab_editcell( float **tablica, int X, int Y,int axis_x,int axis_y, int value);


/// adds new data to existing table
/**
*@param[out] tablica - Table for editting
 * @param[in,out] X - Axis X lenght
 * @param[in,out] Y - Axis Y lenght
 * @param[in] value - axis X or Y increase value
 * @param[in] choice - Defines which axis to change, true=x false=y
**/
void tab_add(float **tablica, int *X, int *Y, bool choice, int value);





