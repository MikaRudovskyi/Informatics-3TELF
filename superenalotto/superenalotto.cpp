// Developer m1rskiy - 26.02.2024
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool containsNumber(const int array[], int size, int number) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (array[i] == number) 
        {
            return true;
        }
    }
    return false;
}

void generateRandomNumbers(int randomNumbers[], int size) 
{
    srand(time(0));
    for (int i = 0; i < size; ++i) 
    {
        int randomNumber;
        do 
        {
            randomNumber = rand() % 90 + 1;
        } while (containsNumber(randomNumbers, size, randomNumber));
        randomNumbers[i] = randomNumber;
    }
}

int main() 
{
    const int NUMBERS_TO_PLAY = 6;

    cout << "Welcome to the SuperEnalotto game!" << endl;
    cout << "Enter six numbers between 1 and 90:" << endl;

    int userNumbers[NUMBERS_TO_PLAY];
    for (int i = 0; i < NUMBERS_TO_PLAY; ++i) 
    {
        int number;
        do 
        {
            cout << "Number " << i + 1 << ": ";
            cin >> number;
            if (number < 1 || number > 90) 
            {
                cout << "The number must be between 1 and 90. Try again." << endl;
            }
            else if (containsNumber(userNumbers, i, number)) 
            {
                cout << "Duplicate number. Try again." << endl;
            }
            else 
            {
                userNumbers[i] = number;
                break;
            }
        } while (true);
    }

    int randomNumbers[NUMBERS_TO_PLAY];
    generateRandomNumbers(randomNumbers, NUMBERS_TO_PLAY);

    cout << "\nYour numbers: ";
    for (int i = 0; i < NUMBERS_TO_PLAY; ++i) 
    {
        cout << userNumbers[i] << " ";
    }

    cout << endl;

    cout << "Random numbers: ";
    for (int i = 0; i < NUMBERS_TO_PLAY; ++i) 
    {
        cout << randomNumbers[i] << " ";
    }

    cout << endl;

    int matchedNumbers[NUMBERS_TO_PLAY];
    int count = 0;

    for (int i = 0; i < NUMBERS_TO_PLAY; ++i) 
    {
        for (int j = 0; j < NUMBERS_TO_PLAY; ++j) 
        {
            if (userNumbers[i] == randomNumbers[j]) 
            {
                matchedNumbers[count++] = userNumbers[i];
                break;
            }
        }
    }

    if (count == 0) 
    {
        cout << "Sorry, you didn't match any numbers." << endl;
    }
    else 
    {
        cout << "You matched " << count << " numbers: ";

        for (int i = 0; i < count; ++i) 
        {
            cout << matchedNumbers[i] << " ";
        }

        cout << endl;
    }

    char response;
    cout << "Do you want to play again? (Yes = Y/y, No = other) ";
    cin >> response;

    if (toupper(response) == 'Y') 
    {
        main();
    }
    else 
    {
        cout << "Thanks for playing. Goodbye!" << endl;
    }

    return 0;
}
