This code is a basic text-based adventure game written in C++. Here's a detailed description of its structure and functionality:

Overview

- Developer: m1rskiy
- Date: 30.05.2024

The game involves navigating a dungeon, encountering various rooms with different challenges, and managing a player's inventory, health, and other attributes. The main classes in the code are `Item`, `Player`, and `Dungeon`.

### Classes

1. Item
   - Attributes:
     - `name`: Name of the item.
     - `weight`: Weight of the item.
     - `healthPt`: Health points the item can restore.
     - `damagePt`: Damage points the item can inflict.
     - `price`: Price of the item.
   - Methods:
     - `Item(string n, float w, int h, int d, float p)`: Constructor to initialize an item with specific values.
     - `Item()`: Default constructor to initialize an empty item.
     - `showInfo()`: Displays information about the item.

2. Player
   - Attributes:
     - `nick`: Player's nickname.
     - `backpack`: Vector of items the player carries.
     - `lifePt`: Player's life points.
     - `manaPt`: Player's mana points.
     - `coins`: Player's coins.
   - Methods:
     - `Player(string n, int c)`: Constructor to initialize a player with a nickname and initial coins.
     - `showInfo()`: Displays player's information and their inventory.
     - `addToBackpack(Item newItem)`: Adds a new item to the player's backpack.

3. Dungeon
   - Methods:
     - `room1(Player &p)`: Handles the first room where the player can pick up a sword and a medkit.
     - `room2(Player &p)`: Presents a choice between two doors leading to different rooms.
     - `room3(Player &p)`: Contains a riddle about Napoleon's white horse.
     - `room4(Player &p)`: Involves a combat scenario with a goblin.
     - `room5(Player &p)`: Presents a choice of three treasure chests with different rewards.
     - `room6(Player &p)`: Final battle with a wizard.

### Main Function

- Initialization:
  - A `Player` object `p` is created with the nickname "MartyMcFly" and 33 coins.
  - A welcome message is displayed.
  - The player's information is shown.

- Game Loop:
  - The player enters the first room using `d.room1(p)`.
  - A while loop keeps the game running until `actualRoom` equals 7 (indicating the game is over).
  - Inside the loop:
    - The game pauses, clears the screen, and shows the player's updated information.
    - Depending on the current room (`actualRoom`), the corresponding room method is called.
    - The player's choice and outcomes in each room determine the next room to visit.

### Gameplay

The game flow involves the player making choices, solving riddles, engaging in combat, and collecting items and rewards. Each room presents different challenges and opportunities, contributing to an engaging adventure experience.

- Room 1: Option to pick up a sword and a medkit.
- Room 2: Choice between two doors leading to different scenarios.
- Room 3: Riddle-solving about Napoleon's white horse.
- Room 4: Combat with a goblin, with options to attack or heal.
- Room 5: Choice of treasure chests with different rewards.
- Room 6: Final battle with a wizard, determining the game's outcome.

### Summary

This code creates a simple yet interactive text-based game where the player navigates through a dungeon, makes decisions, engages in combat, and manages their inventory and resources. The use of classes for `Item`, `Player`, and `Dungeon` helps organize the code and separate different aspects of the game logic.