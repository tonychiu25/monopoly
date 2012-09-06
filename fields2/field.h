#ifndef FIELD_H
#define FIELD_H

class Field {

  protected :
    int index;
    int currentPlayerOccupy;
    std::string name;
    char fieldtype;
  public :
    void initializeField(int i, std::string n, char type);
    void setCurrentPlayerOccupy(int playerIndex);
    int getCurrentPlayerOccupy();
    char getFieldType();
    std::string getName();
};
#endif
