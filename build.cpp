#include <stdlib.h>
#include <iostream>
#include "lot.cpp"
//#include "railroad.cpp"

using namespace std;

int main() { 
  
  Lot l(1, "Broadway", 233, 12);
  //Railroad r(5, "Hanzomon", 200);
 
  cout<<l.getName()<<endl;
  cout<<l.getFieldType()<<endl;
  cout<<l.getPropertyCost()<<endl;
  cout<<l.getOwnerIndex()<<endl;
  //cout<<r.getRentCost()<<endl;
  return 0;
}
