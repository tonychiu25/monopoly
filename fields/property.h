#ifndef PROPERTY_H
#define PROPERTY_H

#include "field.h"

class Property : public Field{
  protected :
    int propertycost;
    int ownerIndex;
    int rentCost;
  public :
    Property(int i, std::string n, char type, int cost);
    ~Property();
    bool checkVacancy();
    void buyProperty(int playerIndex);
    int getPropertyCost();
    int getOwnerIndex();
    int getRentCost();
};

#endif
