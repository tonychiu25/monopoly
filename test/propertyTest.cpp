#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;

#include "testheader.h"

Property *p;
void checkPropertyFieldSet(int i, std::string n, char type, int cost) {
  assert(p->getPropertyCost()==cost);
  assert(p->getOwnerIndex() == -1);
}

void checkBuyProperty(int i) {
  assert(p->checkVacancy() == false);
  p->buyProperty(i);
  assert(p->getOwnerIndex() == i);
  assert(p->checkVacancy() == true); 
}

/*int main() {
  p = new Property(1,"Hi",'L',32);
  checkPropertyFieldSet(1,"Hi",'L',32);
  checkBuyProperty(44);
  return 1;
}*/
