#ifndef BOARD_H
#define BOARD_H

#include "../fields3/lot.h"

class Board {

  protected :
    Field * board;
  public :
    Board();
    void generateMonopolyBoard();
  private :
    Field * createLot(int i, std::string n, int c, int buildingCost, int * rentCostList);
    Field * createRail(int i, std::string n, int buycost);
};

#endif
