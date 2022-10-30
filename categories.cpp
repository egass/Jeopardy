// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#include <iostream>
#include <string>
#include <fstream>
#include "categories.h"

using namespace std;

// Constructor
Category::Category(){
    name = "";
    question = "";
    answer = "";
}
Category::Category(string n, string q, string a){
    name = n;
    question = q;
    answer = a;
}

//Getters
void Category::Question(){ // Renamed to question 
    if(question.length() == 0){ // Checking to see if there is a question that is able to be asked
        cout << "No Available Question" << endl;
        return;
    }
    cout << question << "." << endl;
}

string Category::getAnswer(){ // Returning the answer
    return answer;
}

//Other functions
bool Category::checkAnswer(string a){ // Checking to see if the users answer aligns with the stored answer
    string ans;
    string sub = answer.substr(answer.length()-1, answer.length()+1);
    if(sub == "\r"){
        ans = answer.substr(0, answer.length()-1); // the answers in the category class have a "/r" on the end, so this removes that
    }
    else{
        ans = answer;
    }
    if(toLower(ans) == toLower(a)){
        return true;
    }
    else{
        return false;
    }
}

string Category::displayCategory(){
    return name;
}

string Category::toLower(string s){ // To lower function
    for(unsigned int i = 0; i < s.length(); i++){ // Loops through the length of the string
        if(int(s[i]) >= 65 && int(s[i]) <= 90){ // Checks to see if the current index is a capital letter
            s[i] = s[i] + 32; // Adds 32 to the character value
        }
    }
    return s; // returns the new edited string
}