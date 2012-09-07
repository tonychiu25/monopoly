#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "board.h"

Board::Board() {}

Field * Board::createLot(int i, std::string n, int c, int buildingCost, int * rentCostList) {
  Field * fp;
  Lot * lp = new Lot(i, n, c, buildingCost, rentCostList);
 
  fp = (Field*)lp;
  return fp;
}

Field * Board::createRail(int i, std::string n, int buycost) {
  Field * fp;
  Property * pp = new Property(i, n, 'R', buycost);
  
  fp = (Field*)pp;
  return fp;
}

void Board::addLotToBoard(int i, std::string n, int c, int buildingCost, int r0, int r1, int r2, int r3, int r4, int r5) {
  Field * fp;
  int rentCostTmp[6] = {r0,r1,r2,r3,r4,r5};
  int * rentCostList = new int[6];
  memcpy (rentCostList, rentCostTmp, sizeof(int)*6); 

  Lot * lp = new Lot(i, n, c, buildingCost, rentCostList);
  fp = (Field*)lp;
  board.push_back(fp);
}

void Board::generateMonopolyBoard() {
  Field * fp;
  Lot * lp;

  addLotToBoard(1,"dd",2,4,0,1,2,3,4,5);
  
}

Field * Board::getFieldAtPosition(int position) {
  Field * fp;
  fp = board.at(position);
  cout<<fp->getName()<<endl;
  return fp;
}

int main() {
  Board * board = new Board();
  board->generateMonopolyBoard();
  
  Lot * lp;  
  Field * fp = board->getFieldAtPosition(0); 
  lp = (Lot*) fp;
  lp->addBuilding();
  lp->addBuilding();
  cout<<lp->getRentCost()<<endl;

  return 1;
}
