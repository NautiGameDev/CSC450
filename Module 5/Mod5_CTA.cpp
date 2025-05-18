/*
    Chris Russell
    CSC450: Programming III
    Module 5 CTA
    May 17, 2025
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void ClearCin() //Clear CIN to prevent buffer overflow
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void AppendFile(string filePath)
{
    ofstream targetFile(filePath, ios::app);

    if(targetFile.is_open())
    {
        bool appending = true;
        ClearCin();

        while(appending) //Loop to allow user to append multiple lines. User can exit loop by entering "q" or "Q".
        {
             //Create break for new line between inputs and previous data

            cout << "\nEnter a line to append to the text file: " << filePath << endl;
            cout << "Or enter Q to finish." << endl;
            cout << "\n  Input >> : ";

            string userInput;

            getline(cin, userInput);

            if (userInput == "q" || userInput == "Q")
            {
                appending = false;
                break;
            }
            else
            {
                targetFile << userInput + "\n";
            }
        }

        cout << filePath << " has been updated successfully." << endl;
        targetFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void ReverseFile(string filePath)
{
    ifstream targetFile(filePath);
    string documentText;

    //Get text from original document    
    if (targetFile.is_open())
    {
        
        string line;

        while(getline(targetFile, line))
        {
            documentText += line + "\n";
        }

        targetFile.close();        
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    //Reverse text and store in new file
    string reversedText(documentText.rbegin(), documentText.rend());


    //Save reversed text to file path
    string reversedFilePath = "CSC450-mod5-reverse.txt";
    ofstream reversedFile(reversedFilePath);

    if(reversedFile.is_open())
    {
        reversedFile << reversedText;
        cout <<  "\n" << filePath << " has successfully been reversed and saved to " << reversedFilePath << endl;
    }
    else
    {
        cout << "\nUnable to write file: " << reversedFilePath << endl;
    }

}

int main()
{
    string filePath = "CSC450_CT5_mod5.txt";
    bool isRunning = true; //Core program loop

    cout << "Target file: " << filePath << endl;

    while(isRunning)
    {
        //COUT menu options
        cout << "\nEnter a number to select an option:" << endl;
        cout << "   1. Append text to text file." << endl;
        cout << "   2. Reverse text file as new file." << endl;
        cout << "   3. Quit program" << endl;

        int userChoice;

        cout << "   Input >>: ";
        cin >> userChoice;

        if(cin.good()) //Executes switch statement if user input is an integer
        {
            switch(userChoice)
            {
                case 1:
                    AppendFile(filePath);
                    break;
                case 2:
                    ReverseFile(filePath);
                    break;
                case 3:
                    isRunning = false;
                    break;
                default:
                    cout << "\nPlease, enter a valid number to select an option." << endl;
                    break;
            }
        }
        else
        {
            ClearCin();
            cout << "\nPlease, enter a number to select an option." << endl;
        }
    }    

    return 0;
}