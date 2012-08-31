#include <stdlib.h>
#include "add.h"

class Property : public Fields{
  protected : int cost, int ownerIndex;
  public :
    Property(int c) {
      int cost = c;
      ownerIndex = -1;
    }

  public bool : checkProperyBought() {
    bool propertyBought;
    if (ownerIndex == -1) {
      propertyBought = false;
    } else {
      propertyBought = true;
    }

    return propertyBought;
  }
}
