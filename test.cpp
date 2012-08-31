#include <stdlib.h>

namespace std;
class A{
  protected : int x,y;
  public :
    A(int one, int two) {
      x = one;
      y = two;
    }
};

class B : public A{
  protected : int z;
  public:
    explicit B(int one, int two, int three) : A(one, two) {
      z = three;
    }

    void printB() {
      cout<<
    }
};

int main() {
  return 0;
}
