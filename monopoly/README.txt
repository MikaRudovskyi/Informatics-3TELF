### Code Explanation

1. Definitions and Constants:
    - Various constants are defined for property status (`UNSOLD`, `SOLD`, `HOME`, `HOTEL`) and the number of players (`N_PLAYERS`) and properties (`N_PROPERTIES`).

2. Dice Class:
    - Contains a method `throW()` to simulate the roll of a six-sided dice.

3. Plot Class:
    - Represents a property in the game with attributes such as name, color, buy price, home price, hotel price, gains, property status, and owner ID.
    - Methods include displaying property info, calculating gain, calculating upgrade cost, and upgrading the property.

4. Player Class:
    - Represents a player with attributes like nickname, symbol, money, and owned properties.
    - Methods include adding and subtracting money, adding a property, and getting the current amount of money.

5. City Class:
    - Manages the game board (plots) and player positions.
    - `_createField()` initializes the board with predefined plots.

6. showPositions Function:
    - Displays the current positions of all players on the board.

7. Main Function:
    - Initializes players and the game board, and starts the game loop.
    - Each player takes turns to roll the dice and move accordingly.
    - Handles special conditions like landing on `Chance`, `Go`, `Jail`, or properties.
    - Players can buy unsold properties, upgrade their own properties, or pay rent if they land on properties owned by others.

The game continues in an infinite loop (`while(true)`), with each player taking their turn, until manually stopped.