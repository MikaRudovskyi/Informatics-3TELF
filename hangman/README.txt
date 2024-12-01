### Code Description

This program implements a simple Hangman game in C++. 

1. displayHangman function:
    - This function takes the number of wrong attempts as an argument and prints the corresponding state of the hangman figure.
    - The function prints different parts of the hangman depending on the number of wrong attempts.

2. main function:
    - The program starts by asking the user to enter a secret word.
    - It initializes the guessed word with underscores, representing unguessed letters.
    - The user is then repeatedly asked to guess letters until they either guess the word correctly or make seven wrong attempts.
    - If the guessed letter is in the secret word, it replaces the corresponding underscores in the guessed word with the correct letter.
    - If the guessed letter is not in the secret word, the number of wrong attempts increases.
    - The game ends when the user either guesses the word or makes seven wrong attempts, displaying the hangman figure and the appropriate message in both cases.