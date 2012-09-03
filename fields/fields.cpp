#include <stdlib.h>
#include <iostream>
using namespace std;

class Fields {
  private : int index, currentPlayerOccupy;
  private : std::string name;
  private : char type;   // The type of landing on the monopoly board.
  public :
    Fields(int i, std::string n, char t) {
      index = i;
      name = n;
      type = t;
      currentPlayerOccupy = -1;
    }

  public : std::string getName() {
    return name;
  }

  public : char getFieldType() {
    return type;
  }

  public : int getCurrentPlayerOccupy() {
    return 1;
  }

  public : void setCurrentPlayerOccupy() {
    
  }
};
