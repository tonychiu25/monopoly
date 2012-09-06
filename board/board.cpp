#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

#include "board.h"

Board::Board() {
  board = (Field*) malloc (sizeof(Field) * 40);
  
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
  int rentlist[5] = {1,2,3,4,5};

  Field * b = new Field[3];

  fp = createLot(1, "Broadway", 22,22, rentlist);
  fp = createLot(2, "Bronx", 22, 22, rentlist);
}

int main() {
  Board * board = new Board();
  board->generateMonopolyBoard();  

  return 1;
}
