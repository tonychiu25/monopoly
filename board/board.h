#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../fields/lot.h"
#include "../fields/rail_utility.h"

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
    void addLotToBoard(int i, std::string n, int c, int buildingCost, int r0, int r1, int r2, int r3, int r4, int r5);
    void addNonLotPropertyToBoard(int i, std::string n, int c, char type);
    void addFieldToBoard(int i, std::string n, char type);
};

#endif
