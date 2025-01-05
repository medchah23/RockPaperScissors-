#include "game_logic.h"
string choicename(int choice) {
	if (choice == 0) {
		return "Rock";
	}
	else if (choice == 1) {
		return "Paper ";
	}
	else if (choice == 2)
	{
		return "Scissors";
	}
	else
	{
		return "Null";
	}
}

string determineWinner(int userChoice, int computerChoice) {
    string Human, Computer;
    Human = choicename(userChoice);
    Computer = choicename(computerChoice);
    if (Human == "Null") {
        return "Invalid User Choice!";
    }
    if (Human == Computer) {
        return "It's a Draw!";
    }
    if ((Human == "Rock" && Computer == "Scissors") ||
        (Human == "Scissors" && Computer == "Paper") ||
        (Human == "Paper" && Computer == "Rock")) {
        return "User Wins! (" + Human + " beats " + Computer + ")";
    }
    else {
        return "Computer Wins! (" + Computer + " beats " + Human + ")";
    }
}
int getComputerChoice() {
    srand(static_cast<unsigned int>(time(0)));
    return rand() % 3;
}

void clearScreen() {
    system("cls");
}
void displayScoreboard(int userScore, int computerScore, int draws) {
    
    const int terminalWidth = 50;  
    
    string title = "Rock Paper Scissors - Scoreboard";
    string userLabel = "User: ";
    string computerLabel = "Computer: ";
    string drawsLabel = "Draws: ";
    string userScoreStr = to_string(userScore);
    string computerScoreStr = to_string(computerScore);
    string drawsStr = to_string(draws);

    clearScreen();

    string border(terminalWidth, '-');

    cout << border << endl;
    cout << setw((terminalWidth + title.length()) / 2) << title << endl;
    cout << border << endl;

    cout << setw((terminalWidth + userLabel.length() + userScoreStr.length()) / 2) << userLabel + userScoreStr << endl;
    cout << setw((terminalWidth + computerLabel.length() + computerScoreStr.length()) / 2) << computerLabel + computerScoreStr << endl;
    cout << setw((terminalWidth + drawsLabel.length() + drawsStr.length()) / 2) << drawsLabel + drawsStr << endl;

    cout << border << endl;

}

void displayInstructions() {
    const int terminalWidth = 50;  
     string title = "Instructions";
     string instructions =
        "1. Choose one of the following options:\n"
        "   0 - Rock\n"
        "   1 - Paper\n"
        "   2 - Scissors\n"
        "2. The game will compare your choice with the computer's choice.\n"
        "3. The rules are:\n"
        "   - Rock beats Scissors\n"
        "   - Scissors beats Paper\n"
        "   - Paper beats Rock\n"
        "4. The result of each round will be displayed after the choices are made.\n"
        "5. The game continues until you decide to exit.";
     clearScreen();
     string border(terminalWidth, '-');
     cout << border <<  endl;
     cout <<  setw((terminalWidth + title.length()) / 2) << title <<  endl;
     cout << border <<  endl;
     cout <<  setw((terminalWidth + instructions.length()) / 2) << instructions <<  endl;
     cout << border <<  endl;
}
void saveGameResults(const  string& userChoice, const  string& computerChoice, const  string& result) {
     ofstream f("SaveGame.sav",  ios::app); 
    if (!f.is_open()) {
         cerr << "Error opening file for saving game results!" <<  endl;
        return;
    }
    char  timeBuffer[80];
    time_t currentTime = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &currentTime);  // localTime is correctly initialized
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", &localTime);  // Pass a pointer to localTime


    
    f << "User Choice: " << userChoice << "\n";
    f << "Computer Choice: " << computerChoice << "\n";
    f << "Result: " << result << "\n";
    f << "Date : " << timeBuffer << endl;
    f << "--------------------------\n";  
    f.close();
     cout << "Game results saved successfully!" <<  endl;
}
void displayMenu() {
    system("clear"); 
    cout << CYAN << R"(
  ######   #####   ##       ##    ##  #####   #######
  ##   ##  ##  ##  ##       ##    ##  ##  ##  ##     
  ######   #####   ##       ##    ##  #####   #######
  ##       ##  ##  ##       ##    ##  ##           ##
  ##       ##  ##  #######   ######   ##       #######
    )" << RESET << endl;

    cout << YELLOW << "Welcome to Rock-Paper-Scissors!" << RESET << endl;
    cout << "Please choose an option:" << endl;
    cout << "0 - Rock" << endl;
    cout << "1 - Paper" << endl;
    cout << "2 - Scissors" << endl;
    cout << "3 - Exit" << endl;
}