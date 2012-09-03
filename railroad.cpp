#include "property.cpp"

class Railroad : public Property{
  public explicit Railroad (int i, string n, int c) : Property(i, n, 'r', 'c') {}
}
