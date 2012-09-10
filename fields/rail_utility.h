#ifndef RAIL_UTILITY_H
#define RAIL_UTILITY_H

#include "property.h"

class Rail_Utility : public Property {
  public :
    Rail_Utility(int i, std::string n, int c, char type);
    void setRentCost(int rent);
};

#endif
