#include "property.cpp"

class Realestate : public Property{
  protected : int rentcost;
  public :  // Constructor for Realestate class
    explicit Realestate(int i, int c, int r, string n) : Property(i,c,n) {
      
    };
  
};
