#ifndef LOT_H
#define LOT_H

#include "property.h"
#define maxBuildingCount 5
#define rentlistsize 6

class Lot : public Property{
  protected :
    int buildingCount;
    int buildingCost;
    int rentcost;
    int * rentCostList;
    char lotcolor;
  public :
    Lot (int i, std::string n, int c, int buildingCost, int rent[], char color);
    ~Lot(); 
    int getBuildingCount();
    int getRentCost();
    int getBuildingCost();
    void addBuilding();
    char getLotColor();
};
#endif
