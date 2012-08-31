#include <stdlib.h>
#include "fields.cpp"

class Property : public Fields{
  protected : int cost, ownerIndex;
  public :
    Property(int i,int c, string n) {
      int cost = c;
      index = i;
      name = n;
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
};
