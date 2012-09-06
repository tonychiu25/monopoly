#include <stdlib.h>
#include "derived.h"

using namespace std;

Derived::Derived(int i, int j) : Base(i) {
  dIndex = j;
}

int Derived::getDerivedIndex() {
  return dIndex;
}

Derived * makeDerived(int i, int j) {
  Derived * made = new Derived(i, j);
  return made;
}

int main() {
  Derived *d;
  d = makeDerived(1,2);
  cout<<d->getIndex()<<endl;
  cout<<d->getDerivedIndex()<<endl;
  return 1;
}
