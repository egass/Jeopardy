// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#ifndef AI_H
#define AI_H

#include <string>
using namespace std;

class AI {

    public:
    // Constructors
    AI();

    // Setters
    void setAiDiffifulty(int d);
    void setAiName(string n);
    void setScore(int s);
    void updateScore(int s);

    // Getters
    void displayAiStats();
    string displayAiName();
    bool isCorrect();
    int getScore();
    
    private:
    int difficulty; // 1 is easy, 2 is medium, 3 is difficult, 4 is perfect
    int score = 0;
    string name;
    int seed = rand();

};


#endif