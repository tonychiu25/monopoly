#include "property.cpp"

const int maxBuilding = 5;

class Realestate : public Property{
  private : int rentcost, buildingCount, buildingCost;
  public :  // Constructor for Realestate class
    explicit Realestate(int i, string n, int c, int buildCost) : Property(i,n,'r',c) {
      buildingCost = buildCost;
      buildingCount = 0; 
    }

  public : int getBuildingCount() {
    return buildingCount;
  }

  public : void addBuilding() {
      buildingCount++;
  }

    
};
