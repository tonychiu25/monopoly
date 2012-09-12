#include <stdlib.h>
#include <iostream>
#include "field.h"

Field::Field(int i, std::string n, char type) {
  index = i;
  name = n;
  fieldtype = type;
  currentPlayerOccupy = -1;
}

Field::~Field() {}

void Field::setCurrentPlayerOccupy(int playerIndex) {

}

int Field::getCurrentPlayerOccupy() {
  return currentPlayerOccupy;
}

int Field::getFieldIndex() {
  return index;
}

char Field::getFieldType() {
  return fieldtype;
}

std::string Field::getName() {
  return name;
}
