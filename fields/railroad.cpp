#include "property.cpp"

class Railroad : public Property{
  public : explicit Railroad (int i, std::string n, int c) : Property(i, n, 'r', 'c') {}
};

int main() {
  return 1;
}
