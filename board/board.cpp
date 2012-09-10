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

void Board::generateMonopolyBoard() {
  Field * fp;
  Lot * lp;

  addFieldToBoard(0, "Start", 'S');
  addLotToBoard(1, "Old Kent Road", 60, 50, 2, 10, 30, 90, 160, 250);
  addFieldToBoard(2, "Community Chest", 'H');
  addLotToBoard(3, "Whitechapel Road", 60, 50, 4, 20, 60, 180, 320, 450);
  addFieldToBoard(4, "Income Tax", 'I');
  addNonLotPropertyToBoard(5, "Kings Cross Station", 200, 'R');
  addLotToBoard(6, "The Angel Islington", 100, 50, 6, 30, 90, 270, 400, 550);
  addFieldToBoard(7, "Chance", 'C');
  addLotToBoard(8, "Euston Road", 100, 50, 6, 30, 90, 270, 400, 550);
  addLotToBoard(9, "Pentonville Road", 120, 50, 8, 40, 100, 300, 450, 600);
  addFieldToBoard(10, "Jail", 'J');
  addLotToBoard(11, "Pall Mall", 140, 100, 10, 50, 150, 420, 625, 750);
  addNonLotPropertyToBoard(12, "Electric Company", 150, 'U');
  addLotToBoard(13, "Whitehall", 140, 100, 10, 50, 150, 450, 625, 750);
  addLotToBoard(14, "Northumberland Avenue", 160, 100, 12, 60, 180, 500, 700, 900);
  addNonLotPropertyToBoard(15, "Marylebone Station", 200, 'R');
  addLotToBoard(16, "Bow Street", 180, 100, 14, 70, 200, 550, 750, 950);
  addFieldToBoard(17, "Community Chest", 'H');
  addLotToBoard(18, "Marlborough Street", 180, 100, 14, 70, 200, 550, 750, 950);
  addLotToBoard(19, "Vine Street", 200, 100, 16, 80, 220, 600, 800, 1000);
  addFieldToBoard(20, "Free Parking", 'P');
  addLotToBoard(21, "The Strand", 220, 150, 18, 90, 250, 700, 875, 1050);
  addFieldToBoard(22, "Chance", 'C');
  addLotToBoard(23, "Fleet Street", 220, 150, 18, 90, 250, 700, 875, 1050);
  addLotToBoard(24, "Trafalgar Square", 240, 150, 20, 100, 300, 750, 925, 1100);
  addNonLotPropertyToBoard(25, "Fenchurch St Station", 200, 'R');
  addLotToBoard(26, "Leicester Square", 260, 150, 22, 110, 330, 800, 975, 1150);
  addLotToBoard(27, "Coventry Street", 260, 150, 22, 110, 330, 800, 975, 1150);
  addNonLotPropertyToBoard(28, "Water Works", 260, 'U');
  addLotToBoard(29, "Piccadilly", 280, 150, 22, 120, 360, 850, 1025, 1200);
  addFieldToBoard(30, "Go To Jail", 'G');
  addLotToBoard(31, "Regent Street", 300, 200, 26, 130, 390, 900, 1100, 1275);
  addLotToBoard(32, "Oxford Street", 300, 200, 26, 130, 390, 900, 1100, 1275);
  addFieldToBoard(33, "Community Chest", 'H');
  addLotToBoard(34, "Bond Street", 320, 200, 28, 150, 450, 1000, 1200, 1400);
  addNonLotPropertyToBoard(35, "Liverpool Street Station", 200, 'R');
  addFieldToBoard(36, "Chance", 'C');
  addLotToBoard(37, "Park Lane", 350, 200, 35, 175, 500, 1100, 1300, 1500);
  addFieldToBoard(38, "Luxary Tax", 'L');
  addLotToBoard(39, "Mayfair", 400, 200, 50, 200, 600, 1400, 1700, 2000); 
}

Field * Board::getFieldAtPosition(int position) {
  Field * fp;
  fp = board.at(position);
  return fp;
}

int main() {
  Board * board = new Board();
  board->generateMonopolyBoard();
  
  Lot * lp;  
  Field * fp = board->getFieldAtPosition(1);
  lp = (Lot*)fp; 

  lp->addBuilding();
  lp->addBuilding();

  return 1;
}
