/*
    Chris Russell
    CSC450: Programming III
    Module 7 CTA
    June 1, 2025
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int number = 0;
int totalIncrements = 20;

void count(int incrementAmt)
{
    for (int i=0; i < totalIncrements; i++)
    {
        lock_guard lock(mtx); //Lock numer variable so only one thread can access at a time
        number += incrementAmt;
        cout << "The current number is: " << number << endl;
    }
}

int main()
{
    //Create threads
    thread t1(count, 1);
    thread t2(count, -1);

    t1.join();
    t2.join();

    cout << "\nFinal Number: " << number << endl;


    //Stop application from closing immediately.
    cout << "\n\nPress enter to close application..." << endl;
    cin.get();

    return 1;
}