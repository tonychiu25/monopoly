#include <stdlib.h>
#include <iostream>
using namespace std;

#include "board.h"

Board::Board() {
}

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

void Board::generateMonopolyBoard() {
  Field * fp;
  Lot * lp;
  int rentlist[5] = {1,2,3,4,5};

  fp = createLot(1, "Broadway", 22,22, rentlist);
  board.push_back(fp);
  fp = createLot(2, "Bronx", 22, 22, rentlist);
  board.push_back(fp);
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
  
  Field *fp;
  fp = board->getFieldAtPosition(0);

  return 1;
}
