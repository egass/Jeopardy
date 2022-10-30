# Jeopardy

------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++11 Driver.cpp -o Jeopardy
Run: ./Jeopardy
------------------------
DEPENDENCIES
------------------------
AI.h ~ Ai.cpp ~ categories.h ~ categories.cpp ~ Driver.cpp ~ gameboard.cpp ~ gameboard.h
player.h ~ player.cpp ~ File.txt ~ File2.txt ~ File3.txt ~ File4.txt ~ File5.txt ~ File6.txt ~ highscores.txt
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2021 Project 3
Author: Eric Wilmes and Evan Gassiot
Recitation: 115 - Alex Ray
Date: December 2, 2021
------------------------
ABOUT THIS PROJECT
------------------------
This project is a Jeopardy like board game. The user is prompted with a 2D board where they can select a category
and a point value and they are prompted with a question that they must answer. If the question is answered correctly, then
the user is rewarded with the number of points from that row, but if they answer incorrectly they lose that number of points.
The user also faces off against a bot, the bot has different difficutly levels and based on that level of difficulty the bot
has a percent chance that it will get the same question right as the user. The bots points work the same way as the user and 
it is possible to lose the game if the bot's total points are higher than that of the users. At the end of the game if the users score is greater than 0 and they have answered all of the questions they their score is added
to the leader board and they are told of their position on the leaderboard (#1, #2, #3, etc..).