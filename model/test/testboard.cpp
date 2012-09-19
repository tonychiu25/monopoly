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

  free(b);  
}

bool testErectBuilding() {
  Board * b = new Board();
  Field * fp;
  Lot * lp;

  b->generateMonopolyBoard();
  b->setOwnerProperty(1, 22);

  fp = b->getFieldAtPosition(1);
  lp = (Lot*) fp;

  for (int i=1; i <= 5; i++) {
    b->erectBuilding(1);
    assert(lp->getBuildingCount() == i);
  }

  free(b); 
}

bool testCanBuildOnLot() {
  Board * b = new Board();
  b->generateMonopolyBoard();
  
  b->setOwnerProperty(1,33);
  b->setOwnerProperty(3,33);
  assert(b->canBuildOnLot(33, 'L') == 1);

  b->setOwnerProperty(6,33);
  b->setOwnerProperty(8,33);
  b->setOwnerProperty(9,33);
  assert(b->canBuildOnLot(33, 'T') == 1);

  b->setOwnerProperty(37,33);
  b->setOwnerProperty(39,4);
  assert(b->canBuildOnLot(33, 'B') == 0);
  assert(b->canBuildOnLot(4, 'B') == 0);

  b->setOwnerProperty(31, 33);
  assert(b->canBuildOnLot(33, 'G') == 0);

  assert(b->canBuildOnLot(33, 'R') == 0);
  
  free(b);
}

bool testCanPurchaseProperty() {
  Board * b = new Board();
  b->generateMonopolyBoard();

  assert(b->canPurchaseProperty(1) == 1);
  b->setOwnerProperty(1,1);
  assert(b->canPurchaseProperty(1) == 0);

  assert(b->canPurchaseProperty(5) == 1);
  b->setOwnerProperty(5,1);
  assert(b->canPurchaseProperty(5) == 0);

  assert(b->canPurchaseProperty(12) == 1);
  b->setOwnerProperty(12,1);
  assert(b->canPurchaseProperty(12) == 0);

  assert(b->canPurchaseProperty(28) == 1);
  b->setOwnerProperty(28,1);
  assert(b->canPurchaseProperty(28) == 0);
}

bool testGetPropertyRent() {
  Board * b = new Board();
  b->generateMonopolyBoard();
  int rentlist[] = {50,200,600,1400,1700,2000};
  b->setOwnerProperty(39, 1);
  for(int i=0; i<6; i++) {
    assert(rentlist[i] == b->getPropertyRent(39));
    b->erectBuilding(39);
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
  testErectBuilding();
  testCanBuildOnLot();
  testCanPurchaseProperty();
  testGetPropertyRent();
  cout<<"All tests Successfully passed"<<endl;
  return 1;
}
