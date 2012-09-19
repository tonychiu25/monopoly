#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "board.h"

Board::Board() {}
Board::~Board() {}

void Board::addLotToBoard(int i, std::string n, int c, int buildingCost, int r0, int r1, int r2, int r3, int r4, int r5, char color) {
  Field * fp;
  int rentCostTmp[6] = {r0,r1,r2,r3,r4,r5};
  int * rentCostList = new int[6];
  memcpy (rentCostList, rentCostTmp, sizeof(int)*6); 

  Lot * lp = new Lot(i, n, c, buildingCost, rentCostList, color);
  fp = (Field*)lp;
  board.push_back(fp);
  putLotColor(color, i);
}

void Board::addNonLotPropertyToBoard(int i, std::string n, int c, char type) {
  Field * fp;
  Rail_Utility * ru_p = new Rail_Utility(i,n,c,type);
  fp = (Field*)ru_p;
  board.push_back(fp);
}

void Board::addFieldToBoard(int i, std::string n, char type) {
  Field * fp;
  fp = new Field(i, n, type);
  
  board.push_back(fp); 
}

void Board::putLotColor(char color, int i) {
  map<char, vector<int>* >::iterator it;
  vector<int> * lotvector;
  it = lotset.find(color);
  if (it == lotset.end()) {  // element not found
    lotvector = new vector<int>();
    lotvector->push_back(i);
    lotset.insert( pair<char, vector<int>* >(color, lotvector) ); 
  } else {
    lotvector = lotset.find(color)->second;
    lotvector->push_back(i);
  }
}

void Board::setOwnerProperty(int boardPos, int playerIndex) {
  Field * fp;
  Property * pp;
  
  fp = getFieldAtPosition(boardPos);
  pp = castToPropertyPt(fp);
  
  pp->setPropertyOwner(playerIndex);
}

void Board::erectBuilding(int boardPos) {
  Field * fp;
  Lot * lp;

  fp = getFieldAtPosition(boardPos);
  lp = castToLotPt(fp);
  lp->addBuilding(); 
}

vector<int>* Board::getLotColorVector(char color) {
  return lotset.find(color)->second;
}

Lot * Board::castToLotPt(Field * fp) {
  Lot * lp;
  lp = (Lot *) fp;
  return lp;
}

Property * Board::castToPropertyPt(Field *fp) {
  Property * pp;
  pp = (Property *) fp;
  
  return pp;
}

bool Board::canBuildOnLot(int playerIndex, char color) {
  vector<int> * lotvector;
  Lot * lp;
  int lotIndex;
  lotvector = getLotColorVector(color);
  for (int i=0; i<lotvector->size(); i++) {
    lotIndex = lotvector->at(i);
    lp = castToLotPt(getFieldAtPosition(lotIndex));
    if (lp->getOwnerIndex() != playerIndex) {
      return false;
    }
  }

  return true; 
}

bool Board::canPurchaseProperty(int boardPos) {
  Field * fp;
  Property * pp;

  fp = getFieldAtPosition(boardPos);
  pp = (Property*) fp;
  return pp->checkVacancy();
}

int Board::getPropertyRent(int boardPos) {
  Field * fp;
  Property * pp;
  Lot * lp;
  char type;

  fp = getFieldAtPosition(boardPos);
  type = fp->getFieldType();

  if (type == 'L') {
    lp = castToLotPt(fp);
    return lp->getRentCost();
  } else {
    pp = castToPropertyPt(fp);
    return pp->getRentCost();
  }
  /*Property * pp;

  pp = (Property*) fp;
  if (pp->checkVacancy()) {
    return 0;
  } else {
    return pp->getRentCost();
  }*/
}

void Board::generateMonopolyBoard() {
  Field * fp;
  Lot * lp;

  addFieldToBoard(0, "Start", 'S');
  addLotToBoard(1, "Old Kent Road", 60, 50, 2, 10, 30, 90, 160, 250, 'L');
  addFieldToBoard(2, "Community Chest", 'H');
  addLotToBoard(3, "Whitechapel Road", 60, 50, 4, 20, 60, 180, 320, 450, 'L');
  addFieldToBoard(4, "Income Tax", 'I');
  addNonLotPropertyToBoard(5, "Kings Cross Station", 200, 'R');
  addLotToBoard(6, "The Angel Islington", 100, 50, 6, 30, 90, 270, 400, 550, 'T');
  addFieldToBoard(7, "Chance", 'C');
  addLotToBoard(8, "Euston Road", 100, 50, 6, 30, 90, 270, 400, 550, 'T');
  addLotToBoard(9, "Pentonville Road", 120, 50, 8, 40, 100, 300, 450, 600, 'T');
  addFieldToBoard(10, "Jail", 'J');
  addLotToBoard(11, "Pall Mall", 140, 100, 10, 50, 150, 420, 625, 750, 'P');
  addNonLotPropertyToBoard(12, "Electric Company", 150, 'U');
  addLotToBoard(13, "Whitehall", 140, 100, 10, 50, 150, 450, 625, 750, 'P');
  addLotToBoard(14, "Northumberland Avenue", 160, 100, 12, 60, 180, 500, 700, 900, 'P');
  addNonLotPropertyToBoard(15, "Marylebone Station", 200, 'R');
  addLotToBoard(16, "Bow Street", 180, 100, 14, 70, 200, 550, 750, 950, 'O');
  addFieldToBoard(17, "Community Chest", 'H');
  addLotToBoard(18, "Marlborough Street", 180, 100, 14, 70, 200, 550, 750, 950, 'O');
  addLotToBoard(19, "Vine Street", 200, 100, 16, 80, 220, 600, 800, 1000, 'O');
  addFieldToBoard(20, "Free Parking", 'P');
  addLotToBoard(21, "The Strand", 220, 150, 18, 90, 250, 700, 875, 1050, 'R');
  addFieldToBoard(22, "Chance", 'C');
  addLotToBoard(23, "Fleet Street", 220, 150, 18, 90, 250, 700, 875, 1050, 'R');
  addLotToBoard(24, "Trafalgar Square", 240, 150, 20, 100, 300, 750, 925, 1100, 'R');
  addNonLotPropertyToBoard(25, "Fenchurch St Station", 200, 'R');
  addLotToBoard(26, "Leicester Square", 260, 150, 22, 110, 330, 800, 975, 1150, 'Y');
  addLotToBoard(27, "Coventry Street", 260, 150, 22, 110, 330, 800, 975, 1150, 'Y');
  addNonLotPropertyToBoard(28, "Water Works", 260, 'U');
  addLotToBoard(29, "Piccadilly", 280, 150, 22, 120, 360, 850, 1025, 1200, 'Y');
  addFieldToBoard(30, "Go To Jail", 'G');
  addLotToBoard(31, "Regent Street", 300, 200, 26, 130, 390, 900, 1100, 1275, 'G');
  addLotToBoard(32, "Oxford Street", 300, 200, 26, 130, 390, 900, 1100, 1275, 'G');
  addFieldToBoard(33, "Community Chest", 'H');
  addLotToBoard(34, "Bond Street", 320, 200, 28, 150, 450, 1000, 1200, 1400, 'G');
  addNonLotPropertyToBoard(35, "Liverpool Street Station", 200, 'R');
  addFieldToBoard(36, "Chance", 'C');
  addLotToBoard(37, "Park Lane", 350, 200, 35, 175, 500, 1100, 1300, 1500, 'B');
  addFieldToBoard(38, "Luxary Tax", 'X');
  addLotToBoard(39, "Mayfair", 400, 200, 50, 200, 600, 1400, 1700, 2000, 'B'); 
}

Field * Board::getFieldAtPosition(int position) {
  Field * fp;
  fp = board.at(position);
  return fp;
}

/*int main() {
  Board * board = new Board();
  board->generateMonopolyBoard();
  
  board->canBuildOnLot(1, 'G');
  board->setOwnerProperty(39, 34);
  
  Field * fp = board->getFieldAtPosition(39);
  Lot * lp = (Lot*) fp;

  cout<<lp->checkVacancy()<<endl;  

  vector<int> * lv = board->getLotColorVector('O');
  for (int i=0; i<lv->size(); i++) {
    //cout<<lv->at(i)<<endl;
  }
  
  //cout<<board->canPurchaseProperty(2)<<endl;
  
  cout<<board->canPurchaseProperty(37)<<endl; 
  //cout<<board->canBuildOnLot(34, 'B')<<endl;

  return 1;
}*/
