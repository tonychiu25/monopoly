#include <stdlib.h>
#include <iostream>
//using namespace std;
using namespace std;
#include "field.h"

void Field::initializeField(int i, std::string n, char type) {
  index = i;
  name = n;
  fieldtype = type;
  currentPlayerOccupy = -1;
}

void Field::setCurrentPlayerOccupy(int playerIndex) {
  
}

int Field::getCurrentPlayerOccupy() {
  return currentPlayerOccupy;
}

char Field::getFieldType() {
  return fieldtype;
}

std::string Field::getName() {
  return name;
}
