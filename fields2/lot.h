#ifndef LOT_H
#define LOT_H

#include "property.h"

class Lot : public Property {
  protected :
    int buildingCount;
    int buildingCost;
    
  public :
    int getBuildingCount();
    void addBuilding();
    void initializeLot(int i, std::string n, int c,int buildCost);
};

#endif
