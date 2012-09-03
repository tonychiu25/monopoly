//#include <stdlib.h>
#include "fields.cpp"
//#include "fields.h"

class Property : public Fields{
  private : int cost, ownerIndex;
  public :
    explicit Property(int i, std::string n, char t, int c) : Fields(i, n, t) {
      cost = c;
      ownerIndex = -1;
    }

  public : bool checkVacancy() {
    bool propertyBought;
    if (ownerIndex == -1) {  // -1 indicates vacant
      propertyBought = false;
    } else {
      propertyBought = true;
    }

    return propertyBought;
  }

  public : void buyProperty(int playerIndex) {
    ownerIndex = playerIndex;
  }

  public : int getPropertyCost() {
    return cost;
  }

  public : int getOwnerIndex() {
    return ownerIndex;
  }
};
