#include <stdlib.h>
#include "fields.cpp"

class Property : public Fields{
  protected : int cost, ownerIndex;
  public :
    explicit Property(int i, string n, char t, int c) : Fields(i, n, t) {
      cout<<c<<endl;
      int cost = c;
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
