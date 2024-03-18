// This program creates a bard graph comparing five stores's sales.

#include <iostream>
using namespace std;

int main()
{
    // Define an array to store a list of five stores' sales.
    int sales[5];   


    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project6_Sales_Bar_Chart.cpp\n";
    cout << "Date, e.g., Oct. 11, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";


    // Get the today's sales for five stores.
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter today's sales for store " << (i + 1) << ": ";
        cin >> sales[i];
    }
        
    // Display sales bar chart.
    cout << endl;
    cout << "SALES BAR CHART\n";
    cout << "(Each * = $100)\n";
    
    // First for loop represents each store.
    for (int i = 0; i < 5; i++)
    {
        cout << "Store " << (i + 1) << ": ";
        // Second for loop represents each asterisk.
        for (int j = 100; j <= sales[i]; j += 100)  // Variable j represents a *
            cout << "*";
        cout << endl;
    }
    
    return 0;
}