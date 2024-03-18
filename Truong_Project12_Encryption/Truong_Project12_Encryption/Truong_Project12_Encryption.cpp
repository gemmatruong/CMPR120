// This program will decode the encrypted message of enemy.
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

string decodeMessage(string, int);
bool checkValidMessage(string);


int main()
{
    // Define the variables.
    string encryptedMessage;
    string originalMessage;


    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project12_Encryption.cpp\n";
    cout << "Date, e.g., Dec. 3, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Open the file for reading.
    ifstream inputFile("code.txt");

    // Check if the file is open.
    if (!inputFile.is_open())
    {
        cout << "Unable to open the file!\n";
        return 1;
    }
    
    // Display the title.
    cout << "Possible messages are:\n";

    // Use while loop to check if it is the end of the file.
    while (getline(inputFile, encryptedMessage))
    {
        // Use for loop to run through all keys from 1 to 100.
        for (int key = 1; key <= 100; key++)
        {
            // Assign the encoded message to a variable.
            originalMessage = decodeMessage(encryptedMessage, key);
            if (checkValidMessage(originalMessage))
                cout << originalMessage << endl;
        }
    }
    inputFile.close();

    return 0;
}

// Define a function to decode a encrypted message.
string decodeMessage(string message, int k)
{
    // Define the variable to hold the encoded message.
    string decryptedMessage;
    // Use range-based for loop to run through the each char in the string.
    for (char c : message)
    {
        if (c == ' ')
            decryptedMessage.append(1,c);
        else
        {
            // Convert character to its ascii decimal value using static_cast.
            c = static_cast<int>(c);

            // Check if the character is out of printable ASCII range.
            if ((c - k) < 32)
                decryptedMessage.append(1, static_cast<char>((c - k + 127) - 32));
            else
                decryptedMessage.append(1,static_cast<char>(c - k));
        }
    }
    return decryptedMessage;
}

// Define a function to check if the message is meaningful.
bool checkValidMessage(string message)
{
    string punctMarks = ".,!?;:";
    for (char c : message)
    {
        // If the message contains special characters, it must be gibberish.
        if ((!isalnum(c) && !isspace(c)) && punctMarks.find(c) == string::npos)
            return false;
    }
    return true;
}