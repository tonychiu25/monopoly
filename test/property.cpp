#include <stdlib.h>
#include <iostream>
using namespace std;
#include "fields.h"
#include "property.h"

/*class Property : public Fields{
  private : int cost, ownerIndex;*/
  Property::Property(int i, std::string n, char t, int c) : Fields(i, n, t) {
      cost = c;
      ownerIndex = -1;
  }
  
  /*Property::Property(int i, std::string n, char t, int c) {

  }*/

  bool Property::checkVacancy() {
    bool propertyBought;
    if (ownerIndex == -1) {  // -1 indicates vacant
      propertyBought = false;
    } else {
      propertyBought = true;
    }

    return propertyBought;
  }

  void Property::buyProperty(int playerIndex) {
    ownerIndex = playerIndex;
  }

  int Property::getPropertyCost() {
    return cost;
  }

  int Property::getOwnerIndex() {
    return ownerIndex;
  }

int main() {
  return 1;
}
