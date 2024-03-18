// This program calculates and displays monthly payments report.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // Define variables.
    int numOfPayments;
    double annualRate, monthlyRate, loanAmount, monthlyPay, totalPay, interestPaid;

    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project3_Monthly_Payments.cpp\n";
    cout << "Date, e.g., Sep. 15, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Get the loan amount.
    cout << "Enter loan amount: ";
    cin >> loanAmount;
    // Get the annual interest rate.
    cout << "Enter annual interest rate (%): ";
    cin >> annualRate;
    // Get number of payments.
    cout << "Enter number of payments: ";
    cin >> numOfPayments;

    // Calculate monthly interest rate, total amount, and interest paid.
    monthlyRate = annualRate / 100 / 12;
    // Calculate monthly payment.
    monthlyPay = (monthlyRate * pow((1 + monthlyRate), numOfPayments) * loanAmount) / 
                    (pow((1 + monthlyRate), numOfPayments) - 1);
    // Calculate total payment.
    totalPay = monthlyPay * numOfPayments;
    // Calculate interest paid.
    interestPaid = totalPay - loanAmount;

    //Display the Monthly Payment Report.
    cout << "\n";
    cout << "===MONTHLY PAYMENTS REPORT===" << endl;
    cout << "Loan Amount:           $" << setw(10) << fixed << setprecision(2) << loanAmount << endl;
    cout << "Monthly Interest Rate:  " << setw(9) << fixed << setprecision(2) << monthlyRate*100 << "%" << endl;
    cout << "Number of Payments:     " << setw(10) << fixed << setprecision(2) << numOfPayments << endl;
    cout << "Monthly Payment:       $" << setw(10) << fixed << setprecision(2) << monthlyPay << endl;
    cout << "Amount Paid Back:      $" << setw(10) << fixed << setprecision(2) << totalPay << endl;
    cout << "Interest Paid:         $" << setw(10) << fixed << setprecision(2) << interestPaid << endl;

    return 0;
}