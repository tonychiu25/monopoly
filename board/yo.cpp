#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#include "yo.h"

int main() {
  Board * b = new Board();
  b->generateMonopolyBoard();
  return 1;
}
