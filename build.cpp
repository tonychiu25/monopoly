#include <stdlib.h>
#include <iostream>
#include "property.cpp"

using namespace std;

int main() { 
  Fields * fd;
  //Property prop(1,200, "Broadway");
  Property prop(1,200, "Yo");
  fd = &prop;
  cout<<fd->getName()<<endl;

  return 0;
}
