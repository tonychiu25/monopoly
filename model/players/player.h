#ifndef PLAYER_H
#define PLAYER_H

class Player{
  private :
    std::string name;
    int id, boardPosition, cash;
  public :
    Player(int i, std::string n);
    int getId();
    int getBoardPosition();
    int getCashAmount();
    std::string getName(); 
    void setBoardPosition(int pos);
    void setCash(int amount);
};

#endif
