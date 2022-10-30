// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#include <iostream>
#include <string>
#include "AI.h"

using namespace std;

AI::AI(){ // Default constructor
    name = "Alex Trebek";
    difficulty = -1;
    srand(time(0)); // sets new seed every game so the sequence of right answers makes the AI not repeated
    seed = rand();
}

// Sets the AI difficulty
void AI::setAiDiffifulty(int d){
   difficulty = d;
}
void AI::setAiName(string n){
    name = n; // Setting AI name
}
void AI::setScore(int s){
    score = s;
}
void AI::updateScore(int s){
    score = score + (s);
}

// This function asks for the difficulty then outputs true or false based on the probability of that difficulty.
bool AI::isCorrect(){
    seed++; // changes seed every time the function makes the AI called so numbers aren't repeated
    srand(seed); 

    int random = rand() % 100 + 1; // sets to a random number between 1 and 100

    switch(difficulty){
        case 1: // easy
            // makes the AI right 40% of the time
            if(random >= 40){
                return false;
            }
            else{
                return true;
            }
            break;
        case 2: // medium
            // makes the AI right 60% of the time
            if(random >= 60){
                return false;
            }
            else{
                return true;
            }    
            break;
        case 3: // hard
            // makes the AI right 80% of the time
            if(random >= 80){
                return false;
            }
            else{
                return true;
            }   
            break;
        case 4: // perfect
            return true; // makes the AI right all the time
            break;
        default:
            return false;
            break;
    }
}

void AI::displayAiStats(){
    cout << "You are playing " << name << endl;
    switch(difficulty){
        case 1:
            cout << name <<"'s difficulty: Easy" << endl; // Displaying AI stats
            break;
        case 2:
            cout << name <<"'s difficulty: Medium" << endl; // Displaying AI stats
            break;
        case 3:
            cout << name <<"'s difficulty: Hard" << endl; // Displaying AI stats
            break;
        case 4:
            cout << name <<"'s difficulty: Impossible" << endl; // Displaying AI stats
            break;
    }
}
string AI::displayAiName(){
    return name; // Returning the name
}

int AI::getScore(){
    return score;
}