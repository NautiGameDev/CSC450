/*
Chris Russell
Module 1 Critical Thinking Assignment
April 19, 2025
*/

#include <iostream>
#include <conio.h>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

int main()
{
    string firstName = "Ted";
    string lastName = "Smith";
    string address = "123 Somewhere ln.";
    string city = "Sunnyville";
    int zipCode = 12345;

    cout << "\nFirst name: " + firstName << endl;
    cout << "Last name: " + lastName << endl;
    cout << "Address: " + address << endl;
    cout << "City: " + city << endl;
    cout << "Zip Code: " << to_string(zipCode) << endl;
    cout << "\n" << endl;

    getch();

    return 0;
}