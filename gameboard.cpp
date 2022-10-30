// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 

#include <iostream>
#include <fstream>
#include "gameboard.h"
#include "categories.h"
#include <string>
#include <iomanip>

int split(string inputString, char seperator, string inputArray[], int SIZE);

Gameboard::Gameboard(){ // Creating a gameboard and initalizing all the elements to 0
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            scoreboard[i][j] = 0;
        }
    }
}

void Gameboard::displayMenu(Player *p, AI *bot){
    string name;
    string trash;
    int choice = -10001;
    int option;

    cout << "Welcome to Jeopardy!\n\nPlease input your name: "; // asks for name
    getline(cin, name);

    do{
        cout << "You have inputted " << name << ". Is that correct?" << endl;
        cout << "1. Yes\n2. No" << endl;
        cin >> option;

        if(option == 2){ // if the option is not 1 and is valid, ask for the name again
            cout << "Please input your name: ";
            getline(cin, trash);
            getline(cin, name);
        }
    }while(option != 1);
    
    p->setName(name); // sets name

    cout << "Welcome, " << p->getName() << "!" << endl << endl; // welcomes player

    do{
        cout << "Please choose which difficulty you would like to play today:\n1. Easy\n2. Medium\n3. Hard\n4. IMPOSSIBLE" << endl; // asks to input difficulty
        cin >> choice;

        if((choice < 1 || choice > 4) && choice != -10001){ // if the choice is invalid and it is not the first time through the loop, tell the user their input is invalid.
            cout << "Invalid input, please try again." << endl;
            cin.ignore();
            cin.clear();
        }

        cout << "You have inputted " << choice << ". Is that correct?" << endl; // confirms that it is the difficulty that the player wants
        cout << "1. Yes\n2. No" << endl;
        cin >> option;


    }while((choice < 1 || choice > 4) || option != 1); // when the difficulty is valid and the player wants it, end the loop.
    
    bot->setAiDiffifulty(choice); // set the bot's difficulty 
    clearScreen();
}

void Gameboard::displayBoard(){
    // Looping through the board and displaying a certain ASCII char based on the value in the table
    cout << "    ";
    for(int i = 0; i < 6; i++){
        cout << setw(13) << board[0][i].displayCategory();
    }
    cout << endl;
    for(int i = 0; i < 5; i++){ // Displays point value in the category based on the loop value
        if(i == 0){
            cout << setw(4) << "400";
        }
        else if(i == 1){
            cout << setw(4) << "800";
        }
        else if(i == 2){
            cout << setw(4) << "1200";
        }
        else if(i == 3){
            cout <<setw(4) << "1600";
        }
        else if(i == 4){
            cout << setw(4) <<"2000";
        }
        for(int j = 0; j < 6; j++){
            if(scoreboard[i][j] == 1){
                cout << setw(12) << "+";
            }
            else if(scoreboard[i][j] == 0){
                cout << setw(12) << "O";
            }
            else if(scoreboard[i][j] == -1){
                cout << setw(12) <<"-";
            }
            else{
                cout << setw(12) << " ~ ";
            }
        }
        cout << endl;
    }

}
// returns the amount of questions left
int Gameboard::displayStats(){
    int numRight = 0;
    int numWrong = 0;
    int totalLeft = 0; // Looping through the table and finding how many correct/incorrect/answered questions and returing that stat to the user
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            if(scoreboard[i][j] == 1){
                numRight++;
            }
            else if(scoreboard[i][j] == -1){
                numWrong++;
            }
            else if(scoreboard[i][j] == 0){
                totalLeft++;
            }
        }
    }

    cout << "You have answered " << numRight << " questions correctly!" << endl;
    cout << "You have answered " << numWrong << " questions incorrectly." << endl;
    cout << "You still have " << totalLeft << " questions left." << endl;

    return totalLeft;
}

void Gameboard::fillboard(){
    ifstream in1;
    in1.open("File.txt");
    int numlines = 0;
    int numcol = 0;
    string readLine;
    string temp[3];
    
    if(in1.good()){
        while(!in1.eof()){
            getline(in1, readLine);
            if(!isspace(readLine[0]) && (readLine.length() > 1)){ // If the line is not empty then do the following
                split(readLine, '|', temp, 3); // use the split function to cut the string into 
                board[numlines][numcol] = Category(temp[0], temp[1], temp[2]);
                numlines++;
            }
        }
    }
    in1.close();
    numcol++;
    numlines = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    in1.open("File2.txt");
    if(in1.good()){
        while(!in1.eof()){
            getline(in1, readLine);
            if(!isspace(readLine[0]) && (readLine.length() > 1)){ // If the line is not empty then do the following
                split(readLine, '|', temp, 3); // use the split function to cut the string into 
                board[numlines][numcol] = Category(temp[0], temp[1], temp[2]);
                numlines++;
            }
        }
    }
    in1.close();
    numcol++;
    numlines = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    in1.open("File3.txt");
    if(in1.good()){
        while(!in1.eof()){
            getline(in1, readLine);
            if(!isspace(readLine[0]) && (readLine.length() > 1)){ // If the line is not empty then do the following
                split(readLine, '|', temp, 3); // use the split function to cut the string into 
                board[numlines][numcol] = Category(temp[0], temp[1], temp[2]);
                numlines++;
            }
        }
    }
    in1.close();
    numcol++;
    numlines = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    in1.open("File4.txt");
    if(in1.good()){
        while(!in1.eof()){
            getline(in1, readLine);
            if(!isspace(readLine[0]) && (readLine.length() > 1)){ // If the line is not empty then do the following
                split(readLine, '|', temp, 3); // use the split function to cut the string into 
                board[numlines][numcol] = Category(temp[0], temp[1], temp[2]);
                numlines++;
            }
        }
    }
    in1.close();
    numcol++;
    numlines = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    in1.open("File5.txt");
    if(in1.good()){
        while(!in1.eof()){
            getline(in1, readLine);
            if(!isspace(readLine[0]) && (readLine.length() > 1)){ // If the line is not empty then do the following
                split(readLine, '|', temp, 3); // use the split function to cut the string into 
                board[numlines][numcol] = Category(temp[0], temp[1], temp[2]);
                numlines++;
            }
        }
    }
    in1.close();
    numcol++;
    numlines = 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    in1.open("File6.txt");
    if(in1.good()){
        while(!in1.eof()){
            getline(in1, readLine);
            if(!isspace(readLine[0]) && (readLine.length() > 1)){ // If the line is not empty then do the following
                split(readLine, '|', temp, 3); // use the split function to cut the string into 
                board[numlines][numcol] = Category(temp[0], temp[1], temp[2]);
                numlines++;
            }
        }
    }
    in1.close();
    

}

void Gameboard::setScore(int i, int j, int value){ // Setting the score at any position in the board
    if( i > 4 || i < 0 || j > 5 || j < 0 || value > 1 || value < -1){ // If the value is not -1 or 1 or it is outside of the indexible range then tell the user that there is an invalid input
        cout << "Could not set score (invalid input)." << endl;
        return;
    }
    if(value == 1 || value == -1){ // Otherwise set the value
        scoreboard[i][j] = value;
    }

}
bool Gameboard::checkIfAsked(int i, int j){

    if(scoreboard[i][j] == 1 || scoreboard[i][j] == -1){ // If the question has already been asked then return true
        cout << "This question has already been asked" << endl;
        return true;
    }
    else{ // If the question has not already been asked then return false
        return false;
    }

}
// clears the screen
void Gameboard::clearScreen(){
    system("clear");
}

bool Gameboard::DisplayQuestion(int i, int j){
    string a;
    string trash;
    board[i][j].Question(); // output the question
    getline(cin, trash); // reset getline
    getline(cin, a); // get answer from player

    return board[i][j].checkAnswer(a); // return if the player's answer was correct
}

string Gameboard::getAnswerCategory(int i, int j){
    return board[i][j].getAnswer();
}


int split(string inputString, char seperator, string inputArray[], int SIZE){
    int len = inputString.length();
    int oldSeperator = -1;
    int numberPieces = 0;
    int inputArrayCounter = 0;
    int seperatorCounter = 0;

    if(len == 0){ // Checking edge case
        return 0;
    }

    for(int i = 0; i < len; i++){ // Looping through the string
        if(inputArrayCounter+1 > SIZE){ // If the size of the array is less than than the array indexer then return -1
            return -1;
        }
        if(inputString[i] == seperator){ // If the string index is the same as the seperation character execute the following
            inputArray[inputArrayCounter] = inputString.substr(oldSeperator+1, i-oldSeperator-1); // Set the current array index to a substring that goes from the position of the old seperator +1 to the current seperator -1
            inputArrayCounter++; // Array index counter
            numberPieces++; // Add one to the number of pieces 
            oldSeperator = i; // Set the position of the old seperator to the current string index
        }
    }

    inputArray[inputArrayCounter] = inputString.substr(oldSeperator+1, len); // Doing one last string split from the index of the last know seperator variable to the end of the string
    numberPieces++; // Adding one to the number of pieces 

    
    for(int i = 0; i < len; i++){ // Counting the number of seperators in the string
        if(inputString[i] == seperator){
            seperatorCounter++;
        }
    }

    if(seperatorCounter == 0){ // If the number of seperators is equal to 0 then the number of pieces is equal to 1
        numberPieces = 1;
        return numberPieces;
    }

    // for(int i = 0; i < inputArrayCounter; i++){
    //     cout << inputArray[i] << endl;
    // }

    return numberPieces;
}

