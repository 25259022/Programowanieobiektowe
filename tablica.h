

using namespace std;
/// operations on table
/**
* This class is responsible for all operations on table in program. All data is stored with help of 2 dimension pointer table. in addition lenght of axis x and y is stored in int x and y accordingly.
*/
class tablica
{
int x;
int y;
int tablica;
int add;

/// creates new table
/**
* creates new table from scratch. running this function is nessecary before running: tab_add and tab_wysw. those operation require table which is created by tab_create.
*/
void tab_create(x,y,tablica);

/// adds new data to existing table
void tab_add(tablica);


///writes whole table
void tabl_wysw(x,y,tablica);


};
