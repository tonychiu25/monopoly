#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "player.h"

Player::Player(int i, std::string n) {
  id = i;
  name = n;
}

int Player::getId() {
  return id;
}

int Player::getBoardPosition() {
  return boardPosition;
}

int Player::getCashAmount() {
  return cash;
}

std::string Player::getName() {
  return name;
}

void Player::setBoardPosition(int pos) {
  boardPosition = pos;
}

void Player::setCash(int amount) {
  cash = amount;
}
