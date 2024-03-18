// This program lets user play the game of Rock, Paper, Scissor against the computer.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string compareChoices(int, int);

int main()
{
    // Set the random seed for random function
    unsigned seed = time(0);
    srand(seed);

    // Define variables.
    int compChoice, userChoice;
    string result;

    // Define an array to hold Rock, Paper, and Scissor.
    string choice[3] = { "Rock", "Paper", "Scissor" };


    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project8_Rock_Paper_Scissor_Game.cpp\n";
    cout << "Date, e.g., Oct. 25, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Display introduction of the game.
    cout << "********* Welcome to ROCK - PAPER - SCISSOR GAME *********\n";
    cout << "...\n";
    cout << "Press Enter to start a new game...";
    cin.get();
    cout << endl;

    // Create while loop to repeat the game until there is a winner.
    while (true)
    {
        // Generate computer's choice.
        compChoice = (rand() % 3) + 1;

        // Get player's choice.
        cout << "Please enter your choice:\n"
            << "\t1 - Rock\n"
            << "\t2 - Paper\n"
            << "\t3 - Scissor\n\n"
            << "Enter your choice: ";
        cin >> userChoice;

        // Check validation that player must enter 1, 2, or 3.
        if (userChoice >= 1 && userChoice <= 3)
        {
            cout << endl;
            cout << "You chose: " << choice[userChoice - 1] << endl;        // Display player's choice.
            cout << "Your opponent chose: " << choice[compChoice - 1] << endl; // Display computer's choice.
            result = compareChoices(userChoice, compChoice);        // Find the result.
            if (result == "win")
            {
                cout << "Congratulation! You are the winner!\n";
                break;
            }
            else if (result == "lose")
            {
                cout << "Sorry. You lose.\n";
                break;
            }
            else
            {
                cout << "It is a draw! Try one more time!\n";
                cout << "===========================\n\n";
            }

        }

        else
        {
            cout << "Please enter a valid number (1, 2, or 3)!\n\n";
        }

    }
    return 0;
}

string compareChoices(int firstChoice, int secondChoice)
{
    string result;
    if (firstChoice == secondChoice)
    {
        result = "draw";
    }
    else if ((firstChoice == 1 && secondChoice == 3) ||
        (firstChoice == 2 && secondChoice == 1) ||
        (firstChoice == 3 && secondChoice == 2))
    {
        result = "win";
    }
    else
    {
        result = "lose";
    }
    return result;
}
