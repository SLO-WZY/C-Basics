# Plasma Game (Rock-Paper-Scissors) 🎮

A simple command-line game written in C. It's a sci-fi variation of the classic Rock-Paper-Scissors featuring custom moves: Plasma, Cryo Shield, and EMP.

## Features
* **Input validation:** Prevents infinite loops and crashes when a user types letters instead of numbers.
* **Math-based logic:** Uses modular arithmetic to determine the winner in a single line of code instead of messy `if/else` chains.

## How to compile and run

Assuming you are in this specific directory, run the following commands in your terminal:

```bash
gcc 01_plasma_game.c -o game
./game
