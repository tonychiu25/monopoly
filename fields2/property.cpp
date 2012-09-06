#include <stdlib.h>
#include <iostream>
using namespace std;
#include "property.h"

void Property::initializeProperty(int i, std::string n, char t, int c) {
  initializeField(i,n,t);
  propertycost = c;
  ownerIndex = -1;
}

bool Property::checkVacancy() {
  bool propertyBought;
  if (ownerIndex == -1) {  // -1 indicates vacant
    propertyBought = false;
  } else {
    propertyBought = true;
  }
}

void Property::buyProperty(int playerIndex){
  ownerIndex = playerIndex;
}

int Property::getPropertyCost(){
  return propertycost;
}

int Property::getOwnerIndex() {
  return ownerIndex;
}
