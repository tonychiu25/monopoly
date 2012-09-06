#include <stdlib.h>
#include <iostream>
using namespace std;
#include "lot.h"

void Lot::initializeLot(int i, std::string n, int c, int buildCost) {
  initializeProperty(i,n,'L',c);
  buildingCost = buildCost;
  buildingCount = 0;
}

int Lot::getBuildingCount() {
  return buildingCount;
}

void Lot::addBuilding() {
  buildingCount++;
}

