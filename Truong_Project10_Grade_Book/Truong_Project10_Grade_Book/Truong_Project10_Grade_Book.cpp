// This program calculate and display students' average scores and letter grade.
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int TEST_NUMS = 4;     // Declare the number of tests in the array.

double averageCalculation(double []);
char letterGradeCalculation(double);



int main()
{
    // Define arrays.
    const int STUDENT_NUMS = 5;
    string studentNames[STUDENT_NUMS];      // array holding students' nameS.
    char letterGrade[STUDENT_NUMS];         // array holding letter grade for each student based on average score.
    double testScores[STUDENT_NUMS][TEST_NUMS]; // 2D array holding scores of 4 tests for 5 students.
    double average[STUDENT_NUMS];           // array holding students' average score.


    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project10_Grade_Book.cpp\n";
    cout << "Date, e.g., Nov. 16, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Execute a loop to let user enter students' name and the row of testScores array.
    for (int i = 0; i < STUDENT_NUMS; i++)
    {
        cout << "Enter name of student #" << i + 1 << ": ";
        // Student's name may contain more than one word. getline() to make sure get the full name user enters.
        getline(cin, studentNames[i]);      
        
        // Execute a loop to let user enter the column of testScores array.
        for (int j = 0; j < TEST_NUMS; j++)
        {
            // Use do-while loop to check validation.
            do
            {
                cout << "Enter the score " << j + 1 << " for " << studentNames[i] << ": ";
                cin >> testScores[i][j];
                cin.ignore();   // Make sure to clear undesirable characters from the input buffer.
                
                // If score entered is invalid, display a message.
                if (testScores[i][j] < 0 || testScores[i][j] > 100)
                    cout << "Invalid input. Score must be from 0 to 100.\n";
            }
            while (testScores[i][j] < 0 || testScores[i][j] > 100);
        }

        // Store average score of each student as an element of the array average.
        average[i] = averageCalculation(testScores[i]);
        // Store letter grade transfered from average score as an element of the array letterGrade.
        letterGrade[i] = letterGradeCalculation(average[i]);
        cout << endl; // Add a blank line.
    }

    // Set the format of numeric output.
    cout << fixed << showpoint << setprecision(2);
    // Display the title.
    cout << "    Name\t\tAverage Score\tGrade\n";
    for (int student = 0; student < STUDENT_NUMS; student++)
    {
        cout << studentNames[student] << ":\t\t" << setw(9) << average[student] 
            << setw(11) << letterGrade[student] << endl;
    }

    return 0;
}

double averageCalculation(double scoresList[])
{
    int sum = 0;
    for (int i = 0; i < TEST_NUMS; i++)
        sum += scoresList[i];
    return sum / static_cast<double>(TEST_NUMS);
}

char letterGradeCalculation(double score)
{
    if (score >= 0 && score <= 59)
        return 'F';
    else if (score >= 60 && score <= 69)
        return 'D';
    else if (score >= 70 && score <= 79)
        return 'C';
    else if (score >= 80 && score <= 89)
        return 'B';
    else
        return 'A';
}
