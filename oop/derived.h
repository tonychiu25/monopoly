#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"
class Derived : public Base {
  public :
    Derived(int i, int j);
    int getDerivedIndex();
  protected :
    int dIndex;
};
  
#endif
