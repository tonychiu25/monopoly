/*#include <stdlib.h>
#include <iostream>*/
#ifndef FIELDS_H
#define FIELDS_H

using namespace std;

class Fields{
  public : 
    Fields(int i, std::string n, char t);
    std::string getName();
    char getFieldType();
    int getCurrentPlayerOccupy();
    void setCurrentPlayerOccupy();
    bool insertProduct(string fproduct, double value);
  
  protected : 
    int index;
    int currentPlayerOccupy;
    std::string name;
    char type;
};
#endif
