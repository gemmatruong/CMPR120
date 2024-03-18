// This program creates a table displaying the Fahrenheit temperatures 0 through 20
// and their Celcius equivalents.

#include <iostream>
#include <iomanip>
using namespace std;

// celcius function prototype.
double celsius(int);

int main()
{
    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project7_Celcius_Temperature_Table.cpp\n";
    cout << "Date, e.g., Oct. 19, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Set up numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    // Set title for each column in table.
    cout << "Fahrenheit Temperature\t\t" << "Celcius Temperature" << endl;

    // Use for loop to run and display temperatures 0 through 20.
    for (int f = 0; f <= 20; f++)
    {
        cout << setw(12) << f << "\t\t\t" << setw(10) << celsius(f) << endl;
    }

    return 0;
}


double celsius(int fahrenheitTemp)
{
    double celsius;
    celsius = 5.0 / 9.0 * (fahrenheitTemp - 32);
    return celsius;
}
