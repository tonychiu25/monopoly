#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "lot.h"

Lot::Lot(int i, std::string n, int c, int houseCost, int rent[]) : Property(i,n,'L',c) {
  buildingCost = houseCost;
  buildingCount = 0;
  rentCostList = (int *) malloc (sizeof(int) * 5);
  memcpy(rentCostList, rent, sizeof(int)*5);
  rentCost = rent[0];
}

int Lot::getBuildingCount() {
  return buildingCount;
}

void Lot::addBuilding() {
  buildingCount++;
}

int Lot::getRentCost() {
  return rentCostList[buildingCount]; 
}
