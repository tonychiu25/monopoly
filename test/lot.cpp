#include "property.cpp"

const int maxBuilding = 5;

class Lot : public Property{
  private : int rentcost, buildingCount, buildingCost;
  public :  // Constructor for Realestate class
    explicit Lot(int i, std::string n, int c, int buildCost) : Property(i,n,'l',c) {
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

int main() {
  Lot l(1,"Broadway", 22, 23);
  return 1;
}
