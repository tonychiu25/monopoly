#include <stdlib.h>
#include <iostream>
#include "realestate.cpp"

using namespace std;

int main() { 
  
  Realestate r(1, "Broadway", 233, 12);
  
  cout<<r.getName()<<endl;
  cout<<r.getFieldType()<<endl;
  cout<<r.getPropertyCost()<<endl;
  cout<<r.getOwnerIndex()<<endl;
  cout<<r.getRentCost()<<endl;
  return 0;
}
