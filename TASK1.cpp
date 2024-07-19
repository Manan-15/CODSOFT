#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*NUMBER GUESSING GAME*/

int main()
{
    srand(time(0));
    int randomNumber = (rand() % (100 - 1 + 1) + 1);

    bool guessed = false;
    while (guessed == false)
    {
        int guess;
        cout << "guess the number between 1 and 100" << endl;
        cin >> guess;
        if (guess == randomNumber)
        {
            cout << "your guess is correct " << endl;
            guessed = true;
        }
        else if (guess < randomNumber)
        {
            cout << guess << " is less than random number " << endl;
        }
        else if (guess > randomNumber)
        {
            cout << guess << " is greater than random number " << endl;
        }
    }
    return 0;
}