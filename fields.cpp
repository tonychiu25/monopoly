#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Fields {
  protected : int index;
  protected : string name;

  public : string getName() {
    return name;
  }
};
