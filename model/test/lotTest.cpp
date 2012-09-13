#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;

#include "../fields/lot.h"

void checkAddBuilding() {
  int rentList[] = {1,2,3,4,5,6};
  Lot * lp = new Lot(1,"D",3,3,rentList, 'R');
  assert(lp->getBuildingCount() == 0);
  lp->addBuilding();
  assert(lp->getBuildingCount() == 1);
  lp->addBuilding();
  lp->addBuilding();
  assert(lp->getBuildingCount() == 3);
  lp->addBuilding();
  lp->addBuilding();
  assert(lp->getBuildingCount() == 5);
  lp->addBuilding();
  assert(lp->getBuildingCount() == 5);
  lp->~Lot();
  free(lp);
}

void checkRent() {
  int rentList[] = {1,2,3,4,5,6};
  Lot * lp = new Lot(1,"D",3,3,rentList, 'R');

  assert(lp->getRentCost() == 1);
  lp->addBuilding();
  assert(lp->getRentCost() == 2);
  lp->addBuilding();
  assert(lp->getRentCost() == 3);
  
  free(lp);
}

/*int main() {
  checkAddBuilding();
  checkRent();
  return 1;
}*/
