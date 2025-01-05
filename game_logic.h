#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std; 
string choicename(int choice);
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
// Function to determine the winner of the game
// Returns a string that indicates the result ("User Wins", "Computer Wins", "It's a Draw")
 string determineWinner(int userChoice, int computerChoice);

// Function to generate a random choice for the computer (0 = Rock, 1 = Paper, 2 = Scissors)
int getComputerChoice();

// Function to display a scoreboard
// Takes the user's and computer's scores as input and outputs the current score
void displayScoreboard(int userScore, int computerScore, int draws);
void displayInstructions();

// Function to save the results of the game to a file (for tracking history)
// Writes the user and computer choices along with the result of each round
void saveGameResults(const  string& userChoice, const  string& computerChoice, const  string& result);
void clearScreen();
void displayMenu();
#endif // GAME_LOGIC_H
