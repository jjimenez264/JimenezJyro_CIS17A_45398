/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aug.h
 * Author: jyroj
 *
 * Created on July 27, 2021, 8:35 PM
 */

#ifndef AUG_H
#define AUG_H

class Prob3Table{
    protected:
        int rows, cols;
        int *rowSum, *colSum, *table, grandTotal;
    public:
        Prob3Table(); //Constructor then Destructor
        ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
        const int *getTable(void){return table;};
        const int *getRowSum(void){return rowSum;};
        const int *getColSum(void){return colSum;};
        int getGrandTotal(void){return grandTotal;};
};

class Prob3TableInherited: public Prob3Table {
    private:
        int *augTable;
    public:
        Prob3TableInherited(); //Constructor then Destructor
        ~Prob3TableInherited(){delete [] augTable;}; //Destructor
        const int *getAugTable(void){return augTable;};
};

#endif /* AUG_H */

