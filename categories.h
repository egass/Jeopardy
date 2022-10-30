// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <string>
using namespace std;

class Category{

    public:
    // Constructor
    Category();
    Category(string n, string q, string a);

    //Getters
    void Question();
    string getAnswer();
    void fillboard();
    string displayCategory();

    //Other functions
    bool checkAnswer(string a);
    string toLower(string s);

    private:
    string name;
    string question;
    string answer;


};

#endif