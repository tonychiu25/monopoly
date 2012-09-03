#include "fields.cpp"

class Tax : public Fields{
    private : int taxCost;
    public : explicit Tax(int i, std::string n, int c, int tax) : Fields(i, n, 't'){
      taxCost = t; 
    }

    // Returns the cost of landing on this tax field.
    public : int getTaxCost() {
      return taxCost;
    }    
};
