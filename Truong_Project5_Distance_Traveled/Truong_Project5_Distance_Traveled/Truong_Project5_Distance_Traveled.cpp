// This program calculates and displays the distance a vehicle travels.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Define variables.
    bool valid;
    int time;
    double distance, speed;

    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project4_Equation_Solutions.cpp\n";
    cout << "Date, e.g., Oct. 04, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Check validation by using the loop control variable of bool type.
    valid = false;
    while (not valid)
    {
        // Get the value of variable speed and time.
        cout << "What is the speed of the vehicle in mph? ";
        cin >> speed;

        cout << "How many hours has it traveled? ";
        cin >> time;
        // Speed cannot be negative and time cannot less than 1.
        if (speed >= 0 && time >= 1)
        {
            // Display the introduction.
            cout << "Hour      " << "Distance Traveled\n";
            cout << "----------------------------------------\n";

            // Use for loop to display the distance the vehicle has traveled for each hour
            // of that time period.
            for (int i = 1; i <= time; i++)
            {
                // Set up numeric output formatting.
                cout << fixed << setprecision(1);
                distance = speed * i;
                cout << i << setw(20) << distance << endl;
            }
            // Update the variable valid to stop the loop.
            valid = true;
        }
        else
        {
            cout << "Speed must be non-negative and time cannot be less than 1!\n";
            cout << endl;
        }

    }

    return 0;
}