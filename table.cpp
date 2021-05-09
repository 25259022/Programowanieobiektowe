//
// Created by Mariola on 30/04/2021.
//

#include "table.h"


using namespace std;

int Table::tab_create(){

    tab = new float *[Y];
    for (int i = 0; i < Y; i++) {
        (tab)[i] = new float[X];
    }
    return 0;
}

int Table::tab_remove(){
    if(X==0||Y==0)
    {return no_table;}

    for (int i = 0; i < Y; i++) {
        delete[] tab[i];
    }
    delete[] tab;
    X=0;
    Y=0;
    return 0;
}

int Table::tab_build(int nx,int ny) {
    if(nx<=0||ny<=0)
    {return wrong_format;}

        X = nx;
        Y = ny;
        tab_create();

}

int Table::tab_editcell(int axis_x, int axis_y, int value){
    if(X==0||Y==0)
    {return no_table;}

    if(axis_x<=0||axis_y<=0)
    {return wrong_format;}

    tab[axis_y-1][axis_x-1] = value;
    return 0;
}

int Table::tab_change(int new_x, int new_y){
    if(X==0||Y==0)
    {return no_table;}

    if(new_x<=0||new_y<=0)
    {return wrong_format;}

    Table new_table(new_x,new_y);

    int smaller_y, smaller_x;
    if (Y <= new_y) { smaller_y = Y; }
    else { smaller_y = new_y; }
    if (X <= new_x) { smaller_x = X; }
    else { smaller_x = new_x; }


    for (int i = 0; i < smaller_y; i++) {
        for (int j = 0; j < smaller_x; j++) {
            new_table.tab[i][j] = tab[i][j];
        }

    }

    tab=new_table.tab;
    X=new_x;
    Y=new_y;

   // new_table.tab_remove();??????
    return 0;
}

int Table::tab_show(){

    if(X==0||Y==0)
    {return no_table;}

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cout<<tab[i][j] << " ";
        }
        cout << endl;

    }
    cout<<endl;
    return 0;
}