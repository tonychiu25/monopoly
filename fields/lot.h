#ifndef LOT_H
#define LOT_H

#include "property.h"
#define maxBuildingCount 5

class Lot : public Property{
  protected :
    int buildingCount;
    int buildingCost;
    int rentcost;
    int * rentCostList;
  public :
    Lot (int i, std::string n, int c, int buildingCost, int rent[]);
    ~Lot(); 
    int getBuildingCount();
    int getRentCost();
    int getBuildingCost();
    void addBuilding();
};
#endif
