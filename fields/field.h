#ifndef FIELD_H
#define FIELD_H

using namespace std;

class Field {

  protected :
    int index;
    int currentPlayerOccupy;
    std::string name;
    char fieldtype;
  public :
    Field (int i, std::string n, char type);
    ~Field();
    void setCurrentPlayerOccupy(int playerIndex);
    int getCurrentPlayerOccupy();
    int getFieldIndex();
    char getFieldType();
    std::string getName();
};
#endif

