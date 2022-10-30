// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>
#include "categories.h"
#include <iomanip>
using namespace std;

class Gameboard{

    public:
    // Constructor
    Gameboard();

    //Getters
    void displayMenu(Player *p, AI *bot); // displays the menu for choosing difficulty before the game starts
    void displayBoard();
    int displayStats();
    void fillboard();
    bool DisplayQuestion(int i, int j);
    string getAnswerCategory(int i, int j);

    //Setters
    void setScore(int i, int j, int value);
    bool checkIfAsked(int i, int j);

    void clearScreen();

    private:
    Category board[5][6];
    int scoreboard[5][6] = {0};

};

#endif