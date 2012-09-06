#include <stdlib.h>
#include <iostream>
using namespace std;
#include "property.h"

Property::Property(int i, std::string n, char type, int cost) : Field(i,n,type) {
  propertycost = cost;
  ownerIndex = -1;
  rentCost = 0;
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

int Property::getRentCost() {
  return rentCost;
}
