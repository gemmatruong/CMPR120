// This program calculates and displays solutions to the quadratic equation.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // Define variables.
    int A, B, C;
    double discriminant, root1, root2, realPart, imagPart;

    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project4_Equation_Solutions.cpp\n";
    cout << "Date, e.g., Sep. 28, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Display introduction.
    cout << "This program will provide solutions for an equation of the form\n";
    cout << setw(45) << "A*x^2 + B*x + C = 0\n";
    cout << "where A, B, and C are integers, and A is not equal to zero\n";

    // Get A, B, and C.
    cout << "Enter A, B, and C: ";
    cin >> A >> B >> C;
 
    // Check if the leading coefficient is zero or non-zero.
    if (A == 0)
        cout << "No solutions will be calculated for a leading coefficient of 0!";
    else
    {
        // Calculate the dominant if the leading coefficient is non-zero.
        discriminant = B * B - 4 * A * C;

        // Check if discriminat value is positive, zero or negative.
        // When discriminant value is positive, there will be two real solutions.
        if (discriminant > 0)
        {
            root1 = (-B + sqrt(discriminant)) / (2 * A);
            root2 = (-B - sqrt(discriminant)) / (2 * A);
            cout << "The two real solutions are   x = " << setw(12) << scientific 
                << setprecision(4) << root1 << "\n";
            cout << "                             x = " << setw(12) << scientific 
                << setprecision(4) << root2 << "\n";
        }
        // When discriminant value is zero, there will be only one real solution.
        else if (discriminant == 0)
        {
            root1 = (-B) / (2 * A);
            cout << "The only real solution is    x = " << setw(12) << scientific 
                << setprecision(4) << root1 << "\n";
        }
        // When discriminant value is negative, there will be two imaginary solutions.
        else
        {
            discriminant /= (-1);                       // Make discriminant positive.
            realPart = double((-B)) / (2 * A);          // Calculate the real part of solution.
            imagPart = sqrt(discriminant) / (2 * A);    // Calculate the imaginary part of solution.
            cout << "The two imaginary solutions are   x = " << setw(12) << scientific 
                << setprecision(4) << realPart << " + (" << imagPart << ")*I" << "\n";
            cout << "                                  x = " << setw(12) << scientific 
                << setprecision(4) << realPart << " - (" << imagPart << ")*I" << "\n";
        }
    }
    return 0;
}