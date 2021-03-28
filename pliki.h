///Saving/Reading table to/from file


///saves from file to Table class
/**
*@param[out] tablica - Table for storing table from file
*@param[out] X - Axis X lenght
*@param[out] Y - Axis Y lenght
**/

int read (float **tablica,int *X, int *Y);

///takes info from existing table and saves it into file
/**
*@param[in] tablica - Table for saving to file
*@param[in] X - Axis X lenght
*@param[in] Y - Axis Y lenght
**/
 int save (float **tablica,int X, int Y);

