#include <stdlib.h>
#include <iostream>
using namespace std;

class fields {
  protected : int index;
  protected : string name;

};

class CPolygon{
  protected: int width, height;
  public :
    void set_values(int a, int b){
      width = a;
      height = b;
    }
  };

class CTriangle : public CPolygon{
  public:
    int area() {
      return (width * height);
    }
  };

int main() {

  return 0;
}
