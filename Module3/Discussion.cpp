#include <iostream>

using namespace std;


void PrintScores(int scores[])
{
    cout << "\nScores: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Score at index " << i << " = " <<  scores[i] << endl;
    }
}

int main()
{
    int scores[5] = {30, 2, 50, 49, 10};
    int *myScores = scores;

    PrintScores(scores);

    myScores[0] = 15;
    myScores[1] += 21;
    myScores[2] -= 10;
    myScores[3] /= 2;
    myScores[4] *= 3;

    PrintScores(scores);
  
    cout << "\nPress enter to close... " << endl;
    getchar();

    return 1;
}