#include <stdlib.h>
#include <iostream>
using namespace std;
#include "rail_utility.h"

Rail_Utility::Rail_Utility(int i, std::string n, int c, char type) : Property(i,n,type,c) {}

void Rail_Utility::setRentCost(int rent) {
  rentCost = rent;
}
