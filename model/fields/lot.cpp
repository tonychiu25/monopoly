#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "lot.h"

Lot::Lot(int i, std::string n, int c, int houseCost, int rent[], char color) : Property(i,n,'L',c) {
  buildingCost = houseCost;
  buildingCount = 0;
  rentCostList = (int *) malloc (sizeof(int) * rentlistsize);
  memcpy(rentCostList, rent, sizeof(int)*rentlistsize);
  rentCost = rent[0];
  lotcolor = color; 
}

Lot::~Lot() {
  delete rentCostList;
}

int Lot::getBuildingCount() {
  return buildingCount;
}

void Lot::addBuilding() {
  if (buildingCount <= maxBuildingCount) {  
    buildingCount++;
  }
}

int Lot::getBuildingCost() {
  return buildingCost;
}

int Lot::getRentCost() {
  return rentCostList[buildingCount]; 
}

char Lot::getLotColor() {
  return lotcolor;
}
