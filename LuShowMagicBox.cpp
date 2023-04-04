#include <iostream>
#include <iomanip>
using namespace std;

// Global constants
const int ROWS = 3; // The number of rows in the array
const int COLS = 3; // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number
char user_answer;
int sumArray1, sumArray2, sumArray3, sumArray4, sumArray5, sumArray6, sumArray7, sumArray8;
int magicArrayRow1[COLS]; //ROW 1 ARRAY WITH 3 ELEMENTS
int magicArrayRow2[COLS]; //ROW 2 ARRAY WITH 3 ELEMENTS
int magicArrayRow3[COLS]; //ROW 3 ARRAY WITH 3 ELEMENTS
const string PROGRAMMER_NAME = "Mark Kasule";
const string PROJECT_NUMBER = "Project #5";
const string DUE_DATE = "12/06/2020";

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

int main()
{
    /* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */

    //ROW 1,2,3 RECORD ELEMENTS FUNCTION CALL
    fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    //SHOW ELEMENTS
    showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    //DETERMINE WHETHER NUMBERS MAKE A MAGIC BOX
    isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    //CHECK IF NUMBERS ARE THE SAME
    checkUnique(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    //CHECK IF NUMBERS FALL IN RANGE MIN AND MAX
    checkRange(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS, MIN, MAX);

    //CONSTANT RETURN TO MENU - PROMPTS
    do
    {
        cout << "" << endl;
        cout << "Do you want to try again?";
        cin >> user_answer;

        //IF ANSWER IS YES else EXIT PROGRAM
        if (user_answer == 'y' || user_answer == 'Y')
        {
            //ROW 1,2,3 RECORD ELEMENTS FUNCTION CALL
            fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

            //ROW 1,2,3 SHOW ELEMENTS FUNCTION CALL
            showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

            //DETERMINE WHETHER NUMBERS MAKE A MAGIC BOX
            isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

            //CHECK IF NUMBERS ARE THE SAME
            checkUnique(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

            //CHECK IF NUMBERS FALL IN RANGE MIN AND MAX
            checkRange(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS, MIN, MAX);
        }
        else if (user_answer != 'n')
        {
            //REQUIRE USER TO ENTER EITHER 'Y' or 'y' OR 'N' or 'n'
            cout << "Opps, please enter (y or Y) for Yes or (n or N) for No!!: ";
            cin >> user_answer;
        }
        else
        {
            system("pause"); //exit program
        }
    } while (user_answer == 'y' || user_answer == 'Y');

    //CONCLUSION
    cout << PROGRAMMER_NAME << endl;
    cout << PROJECT_NUMBER << endl;
    cout << DUE_DATE << endl;
    return 0;
}

//FUNCTION TO STORE ALL ELEMENTS ENTERED BY USER
void fillArray(int aR1[], int aR2[], int aR3[], int aSize)
{
    int index = 0; //initializer

    cout << "Enter number for row " << index << " and column " << index << " : ";
    cin >> aR1[0];
    //ROW1 COL2 INPUT
    cout << "Enter number for row " << index << " and column " << (index + 1) << " : ";
    cin >> aR1[1];
    //ROW1 COL3 INPUT
    cout << "Enter number for row " << index << " and column " << (index + 2) << " : ";
    cin >> aR1[2];

    //ROW2 COL1 INPUT
    cout << "Enter number for row " << (index + 1) << " and column " << index << " : ";
    cin >> aR2[0];
    //ROW2 COL2 INPUT
    cout << "Enter number for row " << (index + 1) << " and column " << (index + 1) << " : ";
    cin >> aR2[1];
    //ROW2 COL3 INPUT
    cout << "Enter number for row " << (index + 1) << " and column " << (index + 2) << " : ";
    cin >> aR2[2];

    //ROW3 COL1 INPUT
    cout << "Enter number for row " << (index + 2) << " and column " << index << " : ";
    cin >> aR3[0];
    //ROW3 COL2 INPUT
    cout << "Enter number for row " << (index + 2) << " and column " << (index + 1) << " : ";
    cin >> aR3[1];
    //ROW3 COL3 INPUT
    cout << "Enter number for row " << (index + 2) << " and column " << (index + 2) << " : ";
    cin >> aR3[2];
}

//FUNCTION TO SHOW ELEMENTS ENTERED BY USER
void showArray(int aR1[], int aR2[], int aR3[], int aSize)
{
    //OUTPUT ROW1
    cout << aR1[0] << " " << aR1[1] << " " << aR1[2] << endl;
    //OUTPUT ROW2
    cout << aR2[0] << " " << aR2[1] << " " << aR2[2] << endl;
    //OUTPUT ROW3
    cout << aR3[0] << " " << aR3[1] << " " << aR3[2] << endl;
}

//CHECK FOR MAGIC SQUARE
//check sum
bool isMagicSquare(int aR1[], int aR2[], int aR3[], int aSize)
{

    //rows sum function call
    checkRowSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    //cols sum function call
    checkColSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    //diagonals
    checkDiagSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    //check for sum of rows, cols, and diagonals
    if (sumArray1 == 15 && sumArray2 == 15 && sumArray3 == 15 && sumArray4 == 15 && sumArray5 == 15 && sumArray6 == 15 && sumArray7 == 15 && sumArray8 == 15)
    {
        cout << "This is a Lo Shu magic square!" << endl;
        return true;
    }
    else
    {
        cout << "This is not a Lo Shu magic square!!" << endl;
        return false;
    }
}
//ROW SUM FUCTION DEFINITITION
bool checkRowSum(int aR1[], int aR2[], int aR3[], int aSize)
{
    sumArray1 = aR1[0] + aR1[1] + aR1[2];
    sumArray2 = aR2[0] + aR2[1] + aR2[2];
    sumArray3 = aR3[0] + aR3[1] + aR3[2];
    return true;
}
//COL SUM FUNCTION DEFINITION
bool checkColSum(int aR1[], int aR2[], int aR3[], int aSize)
{
    sumArray4 = aR1[0] + aR2[0] + aR3[0];
    sumArray5 = aR1[1] + aR2[1] + aR3[1];
    sumArray6 = aR1[2] + aR2[2] + aR3[2];
    return true;
}
//DIAGONAL SUM FUNCTION
bool checkDiagSum(int aR1[], int aR2[], int aR3[], int aSize)
{
    sumArray7 = aR1[0] + aR2[1] + aR3[2];
    sumArray8 = aR1[2] + aR2[1] + aR3[0];
    return true;
}

//CHECK IF NUMBERS ARE UNIQUE FUNCTION DEFINITION

bool checkUnique(int aR1[], int aR2[], int aR3[], int a)
{
    if (aR1[0] != aR1[1] && aR1[1] != aR1[2] && aR1[2] != aR2[0] && aR2[0] != aR2[1] && aR2[1] != aR2[2] && aR2[2] != aR3[0] && aR3[0] != aR3[1] && aR3[1] != aR3[2])
    {
        cout << "Great, all the numbers entered are not the same!!" << endl;
        return true;
    }
    else
    {
        cout << "One or more of the numbers entered is/are the same, though!!" << endl;
        return false;
    }
}

//CHECK IF NUMBERS FALL IN RANGE OF 1-9
bool checkRange(int aR1[], int aR2[], int aR3[], int a, int minNum, int maxNum)
{
    if (aR1[0] >= minNum && aR1[0] <= maxNum || aR1[1] >= minNum && aR1[1] <= maxNum || aR1[2] >= minNum && aR1[2] <= maxNum || aR2[0] >= minNum && aR2[0] <= maxNum || aR2[1] >= minNum && aR2[1] <= maxNum || aR2[2] >= minNum && aR2[2] <= maxNum || aR3[0] >= minNum && aR3[0] <= maxNum || aR3[1] >= minNum && aR3[1] <= maxNum || aR3[2] >= minNum && aR3[2] <= maxNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
