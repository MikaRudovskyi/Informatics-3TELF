// Developer m1rskiy - 30.01.2024
#include <iostream>
#include <string>

using namespace std;

int displayHangman(int wrongAttempts)
{
    cout << "   ________" << endl;
    cout << "   |      |" << endl;

    if (wrongAttempts >= 1)
        cout << "   O" << endl;

    if (wrongAttempts >= 2)
        cout << "   |" << endl;

    if (wrongAttempts >= 3)
        cout << "  /";

    if (wrongAttempts >= 4)
        cout << "|";

    if (wrongAttempts >= 5)
        cout << "\\";

    cout << endl;

    if (wrongAttempts >= 6)
        cout << "  /";

    if (wrongAttempts >= 7)
        cout << " \\";

    cout << endl;

    return wrongAttempts;
}

int main()
{
    string secretWord;
    cout << "Enter the secret word: ";
    cin >> secretWord;

    string guessedWord(secretWord.length(), '_');

    int wrongAttempts = 0;

    while (wrongAttempts < 7)
    {
        cout << "Guessed word: " << guessedWord << endl;

        wrongAttempts = displayHangman(wrongAttempts);

        char guessedLetter;
        cout << "Enter a letter: ";
        cin >> guessedLetter;

        bool correctlyGuessed = false;
        for (int i = 0; i < secretWord.length(); ++i)
        {
            if (secretWord[i] == guessedLetter)
            {
                guessedWord[i] = guessedLetter;
                correctlyGuessed = true;
            }
        }

        if (!correctlyGuessed)
        {
            ++wrongAttempts;
        }

        if (guessedWord == secretWord)
        {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    if (wrongAttempts == 7)
    {
        cout << "You lost! The secret word was: " << secretWord << endl;
        displayHangman(7);
    }

    return 0;
}
