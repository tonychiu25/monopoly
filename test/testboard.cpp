#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;

#include "testboard.h"
Board *b;

bool testIndexAdded() {
  int i;
  Field * fp;
  for(i=0; i<=39; i++) {
    fp = b->getFieldAtPosition(i);
    assert (fp->getFieldIndex()==i);
  }

  return true;
}

Lot * castToLotPointer(Field *fp) {
  Lot *lp;
  lp = (Lot*)fp;
  
  return lp;
}

bool testGetLot() {
  Field *fp;
  Lot *lp;
  
  // Test Lot was added
  fp = b->getFieldAtPosition(3);
  lp = castToLotPointer(fp);
  assert(lp->getFieldType() == 'L');
}

void testRailUtilityFunctions() {
  
}

bool testLotFunctions() {
  Field *fp;
  Lot *lp;

  fp = b->getFieldAtPosition(16);
  lp = castToLotPointer(fp);
  assert(lp->getPropertyCost() == 180);
  assert(lp->getBuildingCost() == 100);
  assert(lp->getRentCost() == 14);
  lp->addBuilding();
  assert(lp->getRentCost() == 70);
  lp->addBuilding();
  assert(lp->getRentCost() == 200);
  lp->addBuilding();
  assert(lp->getRentCost() == 550);
  lp->addBuilding();
  assert(lp->getRentCost() == 750);
  lp->addBuilding();
  assert(lp->getRentCost() == 950);
}

int main() {
  b = new Board();
  b->generateMonopolyBoard();

  testIndexAdded();
  testGetLot();
  testLotFunctions(); 

  return 1;
}
