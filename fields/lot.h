#ifndef LOT_H
#define LOT_H

#include "property.h"

class Lot : public Property{
  protected :
    int buildingCount;
    int buildingCost;
    int rentcost;
    int * rentCostList;
  public :
    Lot (int i, std::string n, int c, int buildingCost, int rent[]); 
    int getBuildingCount();
    int getRentCost();
    void addBuilding();
};
#endif
