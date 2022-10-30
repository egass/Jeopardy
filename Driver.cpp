// CS1300 Fall 2021
// Author: Eric Wilmes and Evan Gassiot
// Recitation: 115 – Alex Ray
// Project 3 
 
#include <iostream>
#include <string>
#include "AI.h"
#include "player.h"
#include "gameboard.h"
#include "categories.h"
#include "AI.cpp"
#include "player.cpp"
#include "gameboard.cpp"
#include "categories.cpp"
#include <vector>

void highScore(Player player){
    string line;
    vector<int> scores;

    ofstream fout;
    fout.open("highscores.txt", ios::app); // open high scores file, start at the end of the file (ios::app)

    fout << endl << player.getName() << ": " << player.getScore(); // add the player's score to the high score file

    fout.close();

    ifstream fin;
    string name;
    string points;
    fin.open("highscores.txt"); // open highscores file to read
    
    if(fin.good()){
        getline(fin, name);
        name = "";
        while(!fin.eof()){ // go through each line in the file
            fin >> name >> points;
            scores.push_back(stoi(points)); // add the scores to a vector of highscores
        }
    }

    // sorting algorithm, sorts the highest scores to the beginning of the vector
    int sortTo = 1;
    int size;
    if(scores.size() > 1){
        do{ // do loop to sort each item
            size = scores.size();
            for(int i = 0; i < size-sortTo; i++){ // go through each item, bubble sort the smallest to the end
                if(scores[i] < scores[i+1]){ // if the current item is less than the next, swap them
                    swap(scores[i], scores[i+1]);
                }
            }
            sortTo++;
        }while(sortTo != size);
    }


    // go through the top 5 scores, if the player's score is on that list, tell them that they have a high score
    for(int i = 0; i < 5; i++){
        if(player.getScore() == scores[i]){
            cout << "Congratulations! Your score of " << player.getScore() << " is #" << i+1 << " on the high score list!" << endl;
            return;
        }
    }

}

int main(){
    Player p;
    AI bot;
    Gameboard game;
    
    int option;
    int row = -1;
    int column = -1;
    int numLeft;
    bool correct;
    bool botCorrect;
    bool first = true;
    string enter;

    game.fillboard();
    game.displayMenu(&p, &bot); // display menu at start

    // start the game:

    do{
        correct = NULL; // reset correct boolean

        bot.displayAiStats(); // display ai stats

        game.displayBoard(); // display the board
        cout << endl;
        numLeft = game.displayStats(); // display the player's stats
        if(numLeft == 0){ // if there are no questions left, break the loop
            break;
        }
        cout << "Your score is " << p.getScore() << endl; // output the player's score
        cout << "Your opponent's score is " << bot.getScore() << endl; // output the opponents score

        do{
            if(((column < 1 || column > 6) || (row < 1 || row > 5)) && first == false){ // if the choice is invalid and it is not the first time through the loop, tell the user their input is invalid.
                cout << "Invalid input, please try again." << endl;
                cin.ignore();
                cin.clear();
            }
            first = false; // set the first time through the loop bool to be false, indicating we have been through the loop multiple times
            cout << "Which column would you like to choose (1-6)?" << endl; // ask for column choice
            cin >> column;

            cout << "Which row would you like to choose (1-5)?" << endl; // ask for row choice
            cin >> row;
        }while((column < 1 || column > 6) || (row < 1 || row > 5)); // while the row and column choice are not in the correct ranges, do the loop

        game.clearScreen(); // clear the screen to display the question

        // if the question has not been asked yet
        if(!game.checkIfAsked(row-1, column-1)){
            correct = game.DisplayQuestion(row-1, column-1); // include input for answer from player, sets a boolean "correct" to true if the player is correct, and false if they are not
        }
        else{
            game.displayBoard(); // display the board
            do{
                if(((column < 1 || column > 6) || (row < 1 || row > 5)) && first == false){ // if the choice is invalid and it is not the first time through the loop, tell the user their input is invalid.
                    cout << "Invalid input, please try again." << endl;
                }
                first = false; // set the first time through the loop bool to be false, indicating we have been through the loop multiple times
                cout << "Which column would you like to choose (1-6)?" << endl;
                cin >> column;

                cout << "Which row would you like to choose (1-5)?" << endl;
                cin >> row;
            }while((column < 1 || column > 6) || (row < 1 || row > 5)); // while the row and column choice are not in the correct ranges, do the loop
            game.clearScreen();
            correct = game.DisplayQuestion(row-1, column-1);
        }
        if(correct == true){ // if they are correct
            cout << endl;
            cout << "Correct!" << endl << endl;
            game.setScore(row-1, column-1, 1);
            // update score based on where the question was on the board
            switch(row){
                case 1: 
                    p.updateScore(400);
                    break;
                case 2: 
                    p.updateScore(800);
                    break;
                case 3: 
                    p.updateScore(1200);
                    break;
                case 4: 
                    p.updateScore(1600);
                    break;
                case 5: 
                    p.updateScore(2000);
                    break;
                default:
                    p.updateScore(0);
                    break;
            }
        }
        else{ // if they are incorrect
            cout << endl;
            cout << "Sorry, that is incorrect. The correct answer is: " << game.getAnswerCategory(row-1, column-1) << endl << endl;
            game.setScore(row-1, column-1, -1);
            // update score based on where the question was
            switch(row){
                case 1: 
                    p.updateScore(-400);
                    break;
                case 2: 
                    p.updateScore(-800);
                    break;
                case 3: 
                    p.updateScore(-1200);
                    break;
                case 4: 
                    p.updateScore(-1600);
                    break;
                case 5: 
                    p.updateScore(-2000);
                    break;
                default:
                    p.updateScore(0);
                    break;
            }
        }

        botCorrect = bot.isCorrect(); // check if the bot is correct for that question

        if(botCorrect){
            cout << bot.displayAiName() << " got the question correct." << endl; // tell the player if the bot got the question correct
            switch(row){
                case 1: 
                    bot.updateScore(400);
                    break;
                case 2: 
                    bot.updateScore(800);
                    break;
                case 3: 
                    bot.updateScore(1200);
                    break;
                case 4: 
                    bot.updateScore(1600);
                    break;
                case 5: 
                    bot.updateScore(2000);
                    break;
                default:
                    bot.updateScore(0);
                    break;
            }
        }
        else{
            cout << bot.displayAiName() << " got the question incorrect." << endl; // tell the player if the bot got the question incorrect
            switch(row){
                case 1: 
                    bot.updateScore(-400);
                    break;
                case 2: 
                    bot.updateScore(-800);
                    break;
                case 3: 
                    bot.updateScore(-1200);
                    break;
                case 4: 
                    bot.updateScore(-1600);
                    break;
                case 5: 
                    bot.updateScore(-2000);
                    break;
                default:
                    bot.updateScore(0);
                    break;
            }
        }

        cout << "Your score is " << p.getScore() << endl; // tell the player their score
        cout << "Your opponent's score is " << bot.getScore() << endl  << "Press Enter to continue"; // tell the player the bot's score
        cin.ignore(); // for the "enter to continue"
        game.clearScreen(); // clear the screen when the player is ready
        
    }while(numLeft > 0); // do the loowop while the number of questions left is not 0

    if(p.getScore() > bot.getScore() && p.getScore() > 0){ // if the player won, tell them
        cout << "You won! Your final score was " << p.getScore() << ", and " << bot.displayAiName() << "'s score was " << bot.getScore() << endl;
    }
    else if(p.getScore() == bot.getScore()){ // if the player tied, tell them
        cout << "You tied. Your final score was " << p.getScore() << ", and " << bot.displayAiName() << "'s score was " << bot.getScore() << endl;
    }
    else{ // if the player lost, tell them
        cout << "Tough luck! You lost. Your final score was " << p.getScore() << ", and " << bot.displayAiName() << "'s score was " << bot.getScore() << endl;
        return 0;
    }
    // do file output and sorting after this line

    highScore(p); // calculate high scores, tell the player if they got a high score if their score is in the top 5    
}