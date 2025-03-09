# MiniGolf

![MiniGolf](res/MiniGolfArt.png)

A simple 2D mini-golf game developed using Raylib and C in CMake. The player aims to pot the ball into the hole while navigating obstacles.

## Description

MiniGolf is a casual 2D golf game written in C using the Raylib library. The game simulates a mini-golf course where the player clicks to aim and hit the ball toward the hole. The game includes obstacles and friction for realistic gameplay.

- **Gameplay**:
  - Left-click to hit the ball towards the hole.
  - The ball moves with friction, slowing down over time.
  - The game ends when the ball is potted into the hole.

## Features

- **Ball Physics**: Realistic movement of the ball with friction.
- **Obstacles**: Rectangular obstacles that block the ball’s path.
- **Simple Mechanics**: Hit the ball using mouse clicks and try to pot it into the hole.

## Game Controls

- **Left-click**: Hit the ball in the direction of the mouse position.
- **No Menu**: The game starts immediately when you run it.

## CMake Setup

The project uses **CMake** to generate build files for the game. CMake will help you build and run the game across different platforms.

### Steps to Build and Run the Game:

1. **Install Dependencies**:
   - Make sure you have [Raylib](https://www.raylib.com/) installed on your system.
   - Ensure that you have **CMake** installed.

2. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/MiniGolf.git
   cd MiniGolf
   ```

3. **Create a build directory and generate the Makefiles:**
    ```bash
    mkdir build
    cd build
    cmake ..
    ```
4. **Build the game:**
    ```bash
    make
    ```

5. **Run the game: After building, you can run the game with the following command:**
    ```
    make run
    ```

This will compile (if not already comiled) and then run the game
