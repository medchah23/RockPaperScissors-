#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>
#include "game_logic.h"

using namespace std;

int main() {
    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0, draws = 0;
    bool gameRunning = true;

    while (gameRunning) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (userChoice == 3) {
            cout << "Thank you for playing! Exiting the game..." << endl;
            break;
        }

        computerChoice = getComputerChoice();
        string result = determineWinner(userChoice, computerChoice);
        string userChoiceName = choicename(userChoice);
        string computerChoiceName = choicename(computerChoice);

        if (result == "Invalid User Choice!") {
            cout << "Invalid input! Please enter a valid choice (0, 1, or 2)." << endl;
            continue;
        }

        cout << "You chose: " << userChoiceName << endl;
        cout << "Computer chose: " << computerChoiceName << endl;
        cout << result << endl;

        if (result.find("User Wins") != string::npos) {
            userScore++;
        }
        else if (result.find("Computer Wins") != string::npos) {
            computerScore++;
        }
        else if (result.find("Draw") != string::npos) {
            draws++;
        }

        saveGameResults(userChoiceName, computerChoiceName, result);

        cout << "\nScoreboard: " << endl;
        displayScoreboard(userScore, computerScore, draws);

        char continueGame;
        cout << "Do you want to play another round? (y/n): ";
        cin >> continueGame;

        if (tolower(continueGame) != 'y') {
            gameRunning = false;
        }
    }

    cout << "Final Scores:" << endl;
    displayScoreboard(userScore, computerScore, draws);
    cout << "Goodbye!" << endl;

    return 0;
}
