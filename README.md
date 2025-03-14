
# Spacecraft Game

The Spacecraft Game is a simulation game where players select one of three different types of ships and embark on an adventure in space. Players navigate through asteroid belts, land on abandoned planets, and face space pirates in their quest for survival.

## How to Play?

1. At the beginning of the game, the player selects one of three ship types:
   - **Strong Ship:** Has a lower escape chance but reduces incoming damage by half.
   - **Fast Ship:** Has a higher escape chance but takes 1.5x more damage.
   - **Normal Ship:** Has standard escape chances and takes regular damage.
2. The player will encounter random events:
   - **Navigating Asteroid Belts:** The ship may take damage or pass through successfully.
   - **Landing on Abandoned Planets:** The player may find gold or encounter space pirates.
   - **Encountering Space Pirates:** The player can choose to flee, fight, or negotiate.
3. The game continues until the player's fuel runs out. When fuel reaches zero, the player's final score is calculated.

## Game Mechanics

- **Escape:** The success of escaping depends on the ship's escape probability.
- **Combat:** If the player wins, they take no damage; if they lose, they receive damage.
- **Negotiation:** The player can use gold to avoid combat.

## Scoring System

The player's score is determined based on the resources collected throughout the game:
- **Fuel**: 5 points
- **Health**: 10 points
- **Gold**: 10 points

## Installation

To run the game, follow these steps:

1. **C++ Compiler:** Requires a C++17 or newer compiler. GCC or Clang can be used.
2. **Compiling the Code:**
   ```sh
   g++ -std=c++17 main.cpp -o spacecraft_game
   ```
3. **Running the Game:**
   ```sh
   ./spacecraft_game
   ```

## Developer Notes

- The game is based on random events and progresses based on the player's choices.
- Additional features can be implemented by extending the `Ship` class or defining new events.

## License

This project is open-source. Feel free to modify and improve it as you wish.

