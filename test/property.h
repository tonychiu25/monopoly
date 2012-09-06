#ifndef PROPERTY_H
#define PROPERTY_H
using namespace std;

class Property : public Fields{
  
  public :
    //explicit Property::Property(int i, std::string n, char t, int c) : Fields(i, n, t);
    //Property(int i, std::string n, char t, int c) : Fields(i, n, t);
    Property(int i, std::string n, char t, int c) : Fields(i,n,t);
    bool checkVacancy();
    void buyProperty(int playerIndex);
    int getPropertyCost();
    int getOwnerIndex();

  private :
    int cost;
    int ownerIndex;
}; 
#endif
