// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player{

    public:
    // constructors
    Player();
    Player(string n, int s);

    // mutators/setters
    void setName(string n);
    void updateScore(int s);

    // accessors/getters
    string getName() const;
    int getScore() const;

    // other member functions
    private:
    string name;
    int score = 0;
};
#endif