/*
Chris Russell
Module 2 Critical Thinking Assignment
CSC450: Programming III
April 26, 2025
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cout << "\nConcatenate Application" << endl;

    char firstWord[25];
    char secondWord[25];

    cout << "\nEnter your first word." << endl;
    cout << " >> ";
    cin.getline(firstWord, sizeof(firstWord));

    cout << "\nEnter your second word." << endl;
    cout << " >> ";
    cin.getline(secondWord, sizeof(secondWord));

    strcat(firstWord, secondWord);
    cout << "Concatenated words: " << firstWord << endl;

    cout << "\nPress enter key to close the application" << endl;
    cin.get();

    return 1;
}