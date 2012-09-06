#include <stdlib.h>
#include <iostream>
using namespace std;
#include "fields.h"
/*class Fields {
  private : int index, currentPlayerOccupy;
  private : std::string name;
  private : char type;   // The type of landing on the monopoly board.*/
  Fields::Fields(int i, std::string n, char t) {
      index = i;
      name = n;
      type = t;
      currentPlayerOccupy = -1;
    }

  std::string Fields::getName() {
    return name;
  }

  char Fields::getFieldType() {
    return type;
  }

  int Fields::getCurrentPlayerOccupy() {
    return 1;
  }

  void Fields::setCurrentPlayerOccupy() {
    
  }

  bool Fields::insertProduct(string fproduct, double value) {
    return true;
  }
//};
