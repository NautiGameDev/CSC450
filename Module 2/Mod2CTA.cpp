/*
Chris Russell
Module 2 Critical Thinking Assignment
CSC450: Programming III
April 26, 2025
*/

#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

char* GetWord(int wordSize)
{
    bool isInputValid = false;

    int adjustedWordSize = wordSize + 1; //Add 1 to wordsize in order to ensure space for null terminator
    char* word = new char[adjustedWordSize];

    //While loop ensures user input is within the scope of cstring size. 
    //If word is too large, the user is prompted again for another word, else return the word.
    while(!isInputValid)
    {
        cout << "Input >> ";
        cin.getline(word, adjustedWordSize);

        if (cin.fail())
        {
            cout << "\nWord is too large. Please enter a word less than " << (wordSize) << " characters." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        else
        {
            isInputValid = true;
            return word;
        }
    }
}

void ConcatenateWordsBySize(int wordSize)
{
    //Sets cstring to wordSize + 1 to ensure room for null terminator
    char firstWord[wordSize + 1];
    char secondWord[wordSize + 1];

    cout << "\nEnter a word less than " << wordSize << " characters." << endl;
    char* tempFirst = GetWord(wordSize);
    strcpy(firstWord, tempFirst);
    
    cout << "\nEnter another word less than " << wordSize << " characters." << endl;
    char* tempSecond = GetWord(wordSize);
    strcpy(secondWord, tempSecond);

    strcat(firstWord, secondWord);
    cout << "\nConcatenated words: " << firstWord << endl;
}

int main()
{
    cout << " >> ";
    cout << "\nConcatenate Application" << endl;

    //Call function to get two inputs from user for different sizes.
    ConcatenateWordsBySize(4);
    ConcatenateWordsBySize(7);
    ConcatenateWordsBySize(11);

    cout << "\nPress enter key to close the application" << endl;

    cin.get();
    return 1;
}