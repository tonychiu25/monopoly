#include <stdlib.h>
#include <iostream>
using namespace std;
#include "rail_utility.h"

Rail_Utility::Rail_Utility(int i, std::string n, int c, char type) : Property(i,n,type,c) {}

void Rail_Utility::setRentCost(int rent) {
  rentCost = rent;
}

int main() {
  Rail_Utility * rl = new Rail_Utility(1,"H", 11, 'R');
  rl->setRentCost(2323);
  cout<<rl->getRentCost()<<endl;
  return 1;
}
