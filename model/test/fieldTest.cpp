#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;

#include "testheader.h"

// Test that field constructor correctly sets the field attr.
void testSetFieldAttr(int i, std::string n, char type) {
  Field *fp = new Field(i, n, type);
  assert(fp->getFieldIndex() == i);
  assert(fp->getName() == n);
  assert(fp->getFieldType() == type);
}

/*int main() {
  testSetFieldAttr(1, "Hello", 'R');
  testSetFieldAttr(2, "Why", 'G');
  
  return 1;
}*/
