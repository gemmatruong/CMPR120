// This program check if the charge account number user enters is valid.
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getChargeAccNum();
bool linearSearch(int[], const int, int);


int main()
{
    // Define the number of accounts.
    const int ACC_NUMS = 16;
    // Define an array to hold all the charge account numbers.
    int chargeAccNum[ACC_NUMS];
    int desiredNumber;     // A variable holds the value entered by user.
    char repeat;    // A variable to check if user wants to repeat the program.
    int count = 0; // Loop counter variable.

    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project11_Charge_Account_Validation.cpp\n";
    cout << "Date, e.g., Nov. 25, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";
    
    // Open the file for reading.
    ifstream inputFile("inputFile.txt");

    // Check if the file is open.
    if (!inputFile.is_open())
    {
        cout << "Unable to open the file!\n";
        return 1;
    }

    // Read the numbers from the file into the array.
    while (count < ACC_NUMS && inputFile >> chargeAccNum[count])
        count++;

    // Close the file.
    inputFile.close();

    do
    {
        // Call the getChargeAccNum letting user enter a charge account number.
        desiredNumber = getChargeAccNum();

        // Check if it is a valid number by calling the linearSearch function.
        // If the number is found in the array, it is a valid number.
        // If not, it is an invalid number.
        if (linearSearch(chargeAccNum, ACC_NUMS, desiredNumber))
            cout << "The charge account number entered is valid.\n";
        else
            cout << "The charge account number entered is invalid.\n";
        cout << "-------------------------------\n";
        cout << "Wanna check another number (y/n)? ";
        cin >> repeat;
    } 
    while (repeat == 'y' || repeat == 'Y');

    return 0;
}


int getChargeAccNum()
{
    int num;
    bool valid = false;

    while (not valid)
    {
        // A charge account number must contain 7 digits. If it has 7 digits, it is a valid input.
        cout << "Enter a charge account number: ";
        cin >> num;
        
        if (num < 1000000 || num > 9999999)
            cout << "Charge account number must contain 7 digits.\n";
        else
            valid = true;
    }
    return num;
}

bool linearSearch(int array[], int size, int searchValue)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == searchValue)
            return true;
    }
    return false;
}