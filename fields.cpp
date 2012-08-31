#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Fields {
  protected : int index;     
  protected : string name;
  protected : char type;   // The type of landing on the monopoly board.
  public :
    Fields(int i, string n, char t) {
      index = i;
      name = n;
      type = t;
    }

  public : string getName() {
    return name;
  }

  public : char getFieldType() {
    return type;
  }
};
