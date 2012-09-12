#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "lot.h"

Lot::Lot(int i, std::string n, int c, int houseCost, int rent[], char color) : Property(i,n,'L',c) {
  buildingCost = houseCost;
  buildingCount = 0;
  rentCostList = (int *) malloc (sizeof(int) * maxBuildingCount);
  memcpy(rentCostList, rent, sizeof(int)*maxBuildingCount);
  rentCost = rent[0];
}

Lot::~Lot() {
  delete rentCostList;
}

int Lot::getBuildingCount() {
  return buildingCount;
}

void Lot::addBuilding() {
  if (buildingCount < maxBuildingCount) {  
    buildingCount++;
  }
}

int Lot::getBuildingCost() {
  return buildingCost;
}

int Lot::getRentCost() {
  return rentCostList[buildingCount]; 
}
