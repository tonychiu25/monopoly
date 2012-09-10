#include <stdlib.h>
#include <iostream>
using namespace std;
#include "lot.h"


int main() {
  
  Field * f = new Lot(1,"Parking Lot", 22,33);
  cout<<f->getFieldType()<<endl;
  Lot * l = (Lot*)f;
  cout<<l->getPropertyCost()<<endl;
  cout<<l->getBuildingCount()<<endl;
  cout<<l->getRentCost()<<endl;

  Property * pp = new Property(2,"das", 'R', 3);
  //cout<<pp->getRentCost()<<endl;
  return 1;
}
