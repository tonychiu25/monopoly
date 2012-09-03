#include "property.cpp"

class Utility :  public Property{
  public : explicit Utility (int i, std::string n, int c) : Property(i, n, 'u', 'c') {};
};

int main() {
  Utility u(7, "electric", 33);
  cout<<u.getName()<<endl;
  return 0;
}
