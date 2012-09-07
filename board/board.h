#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../fields3/lot.h"
#include "../fields3/"

class Board {

  protected :
  public :
    Board();
    void generateMonopolyBoard();
    Field * getFieldAtPosition(int position);
  private :
    Field * createLot(int i, std::string n, int c, int buildingCost, int * rentCostList);
    Field * createRail(int i, std::string n, int buycost);
    vector<Field*> board;
};

#endif
