#include <iostream>
#include <vector>
using namespace std;

const int COLS = 3;     // Declare the number of columns in the array.

bool loShuMagicSquareCheck(int[][COLS], int);   // Function prototype.
void displayArray(int[][COLS], int);   // Function prototype.

int main()
{
    // Define two-dimentional arrays to hold the magic square.
    const int ROWSNUM = 3;      // Declare the number of rows in the array.
    int square1[ROWSNUM][COLS] = { {4,9,2}, {3,5,7}, {8,1,6} };
    int square2[ROWSNUM][COLS] = { {4,1,2}, {3,5,7}, {8,9,6} };


    // Display the program header.
    cout << "\n";
    cout << "Author's Name, e.g., Thi Truong\n";
    cout << "Program Name, e.g., Truong_Project9_LoShu_Magic_Square.cpp\n";
    cout << "Date, e.g., Nov. 12, 2023\n";
    cout << "College Name, e.g., Santa Ana College (SAC)\n";
    cout << "=========================================================\n";

    // Display the square1.
    displayArray(square1, ROWSNUM);

    // Check whether square1 is a Lo Shu Magic Square.
    if (loShuMagicSquareCheck(square1, ROWSNUM))
        cout << "This is a Lo Shu Magic Square!!!" << endl;
    else
        cout << "This is not a Lo Shu Magic Square!!!" << endl;

    // Display the square2.
    displayArray(square2, ROWSNUM);

    // Check whether square2 is a Lo Shu Magic Square.
    if (loShuMagicSquareCheck(square2, ROWSNUM))
        cout << "This is a Lo Shu Magic Square!!!" << endl;
    else
        cout << "This is not a Lo Shu Magic Square!!!" << endl;

    return 0;
}

// Define the function used to display the 2D array.
void displayArray(int twoDArray[][COLS], int rowsNum)
{
    // Display the introduction.
    cout << endl;
    cout << "The magic square is..." << endl << endl;

    // Display the array.
    for (int i = 0; i < rowsNum; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << twoDArray[i][j] << "  ";
        cout << endl;
    }
    cout << endl;   // Add a white line.
}

// Define the function used to check whether it is a Lo Shu Magic Square.
bool loShuMagicSquareCheck(int magicSquare[][COLS], int rowsNum)
{
    // Lo Shu Magic Square must contains the numbers t through 9 exactly.
    for (int row = 0; row < rowsNum; row++)
    {
        vector<int> numbers;
        for (int col = 0; col < COLS; col++)
        {
            // Validate input range from 1 to 9.
            if (magicSquare[row][col] < 1 && magicSquare[row][col] > 9)
                return false;

            // Check for duplicate.
            bool found = false;
            for (int element : numbers)
            {
                if (element == magicSquare[row][col])
                    return false;
            }
        }
    }

    // Compare the sums of row
    // Calculate sum of the first row.
    int firstRowSum = 0;
    for (int element : magicSquare[0])
        firstRowSum += element;

    // Calculate sum of the other rows and compare to the sum of the first row.
    for (int row = 1; row < rowsNum; row++)
    {
        int rowSum = 0;
        for (int element : magicSquare[row])
            rowSum += element;
        if (rowSum != firstRowSum)
            return false;
    }
    // Compare the sums of columns.
    // Calculate the sum of the first column.
    int firstColSum = 0;
    for (int row = 0; row < rowsNum; row++)
    {
        firstColSum += magicSquare[row][0];
    }

    // Calculate the sum of other columns.
    for (int col = 1; col < COLS; col++)
    {
        int colSum = 0;
        for (int row = 0; row < rowsNum; row++)
        {
            colSum += magicSquare[row][col];
        }
        if (colSum != firstColSum)
            return false;

    }
    // Calculate the diagonal sum.
    int diagonalSum1 = magicSquare[0][2] + magicSquare[1][1] + magicSquare[2][0];
    int diagonalSum2 = magicSquare[0][0] + magicSquare[1][1] + magicSquare[2][2];


    // Compare the sums of row, column, and diagonal.
    if (firstRowSum != firstColSum || firstRowSum != diagonalSum1 || firstColSum != diagonalSum2)
    {
        return false;
    }
    return true;
}
