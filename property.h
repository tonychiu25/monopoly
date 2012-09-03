#ifndef PROPERTY_H
#define PROPERTY_H
#endif

using namespace std;

private : int index;
private : std::string name;
private : char type;

Property(int i, string n, char t, int c);
bool checkVacancy();
void buyProperty(int playerIndex);
int getPropertyCost();
int getOwnerIndex();
