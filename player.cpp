// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

Player::Player(){ // Sets the player stats to be empty
    name = "";
    score = 0;
}
Player::Player(string n, int s){
    // Fills the player stats with the correct information
    name = n;
    score = 0;

}
// mutators/setters
void Player::setName(string n){
    name = n;
}
void Player::updateScore(int s){
    score = score + (s);
}
// accessors/getters
string Player::getName() const{
    return name;
}
int Player::getScore() const{
    return score;
}