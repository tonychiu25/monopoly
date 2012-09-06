#ifndef PROPERTY_H
#define PROPERTY_H

#include "field.h"

class Property : public Field{
  protected : 
    int propertycost;
    int ownerIndex;
  public :
    void initializeProperty(int i, std::string n, char t, int c);
    bool checkVacancy();
    void buyProperty(int playerIndex);
    int getPropertyCost();
    int getOwnerIndex();
};

#endif
