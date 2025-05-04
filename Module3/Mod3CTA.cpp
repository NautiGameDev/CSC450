/*
Chris Russell
Module 3 Critical Thinking Assignment
CSC450: Programming III
May 3, 2025
*/

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "Enter three numbers to view the integer and pointer reference output." << endl;
    int firstNumb;
    int secondNumb;
    int thirdNumb;

    /*Pointer references set to an array for use of for-loop and while loop when retreiving user input.*/
    int** ptrArray = new int*[3];
    ptrArray[0] = &firstNumb;
    ptrArray[1] = &secondNumb;
    ptrArray[2] = &thirdNumb;

    for (int i=0; i<3; i++)
    {
        bool inputValid = false;

        /*While loop ensures input is a valid integer before moving on to further steps in the program.*/
        while (!inputValid)
        {
            cout << "\nEnter a number[" << i+1 << "]: " << endl;
            cout << "Input >> ";

            cin >> *ptrArray[i];

            if (cin.good())
            {
                inputValid = true;
                break;
            }
            else
            {
                cout << "\nInput must be an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    cout << "\nYou entered..." << endl;
    cout << "First Number: integer = " << firstNumb << " :: pointer = " << *ptrArray[0] << endl;
    cout << "Second Number: integer = " << secondNumb << " :: pointer = " << *ptrArray[1] << endl;
    cout << "Third Number: integer = " << thirdNumb << " :: pointer = " << *ptrArray[2] << endl;

    delete[] ptrArray;

    cout << "\nPress enter to close program." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 1;
}