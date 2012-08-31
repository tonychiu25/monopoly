#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Fields {
  protected : int index;
  protected : string name;
  
  public : Fields(int i, string n) {
    index = i;
    name = n;
  }

  public : string getName() {
    return name;
  }
};
