#include <stdlib.h>
#include <iostream>
#include <string>
//using namespace std;

class Fields {
  private : int index;     
  private : std::string name;
  private : char type;   // The type of landing on the monopoly board.
  public :
    Fields(int i, std::string n, char t) {
      index = i;
      name = n;
      type = t;
    }

  public : std::string getName() {
    return name;
  }

  public : char getFieldType() {
    return type;
  }
};
