#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include "../fields/lot.h"
#include "../fields/rail_utility.h"
#define totalBuildings 36
#define totalSlots 40 

class Board {

  protected :
  public :
    Board();
    ~Board();
    void generateMonopolyBoard();
    void setOwnerProperty(int boardPos, int playerIndex);
    void erectBuilding(int boardPos);
    Field * getFieldAtPosition(int position);
    vector<int>*  getLotColorVector(char color);
    bool canBuildOnLot(int playerIndex, char color);
    bool canPurchaseProperty(int boardPos);
    int getPropertyRent(int boardPos);
  private :
    Lot * castToLotPt(Field * fp);
    Property * castToPropertyPt(Field *fp);
    vector<Field*> board;
    map<char, vector<int>* > lotset;
    void putLotColor(char color, int i);
    void addLotToBoard(int i, std::string n, int c, int buildingCost, int r0, int r1, int r2, int r3, int r4, int r5, char color);
    void addNonLotPropertyToBoard(int i, std::string n, int c, char type);
    void addFieldToBoard(int i, std::string n, char type);
};

#endif
