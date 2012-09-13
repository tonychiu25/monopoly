#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;

#include "testheader.h"
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

bool testSetOwnerProperty() {
  Board * b = new Board();
  b->generateMonopolyBoard();
  b->setOwnerProperty(1,1);
  b->setOwnerProperty(39,1);
  b->setOwnerProperty(15,1);

  Field * fp = b->getFieldAtPosition(1);
  Property * pp = (Property*) fp;
  assert(pp->getOwnerIndex() == 1);

  fp = b->getFieldAtPosition(15);
  pp = (Property*) fp;
  assert(pp->getOwnerIndex() == 1);
  
  fp = b->getFieldAtPosition(39);
  pp = (Property*) fp;
  assert(pp->getOwnerIndex() == 1);
  
  free(b);
}

bool testLotColorSet() {
  Field * fp;
  Lot * lp;
  int i,j;
  char color;
  char colorSequence[] = {'L','L','T','T','T','P','P','P','O','O','O','R','R','R','Y','Y','Y','G','G','G','B','B'};
  Board * b = new Board();
  b->generateMonopolyBoard();
  
  j = 0;
  for (i=0; i<40; i++) {
    fp = b->getFieldAtPosition(i);
    if (fp->getFieldType() == 'L') {
      lp = (Lot*) fp;
      color = lp->getLotColor();
      assert(color == colorSequence[j]);
      j++;    
    }
  }  
}

int main() {
  b = new Board();
  b->generateMonopolyBoard();

  testIndexAdded();
  testGetLot();
  testLotFunctions(); 
  testSetOwnerProperty();
  testLotColorSet();
  cout<<"All tests Successfully passed"<<endl;
  return 1;
}
