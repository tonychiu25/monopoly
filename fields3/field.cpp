#include <stdlib.h>
#include <iostream>
using namespace std;
#include "field.h"

Field::Field(int i, std::string n, char type) {
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
