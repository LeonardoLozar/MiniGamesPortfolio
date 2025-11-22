/// Here is a simple console-based paddle game in C++ using Windows API for handling keyboard input and console output.
/// Controls:
/// a - Move paddle left
/// d - Move paddle right
/// q - Quit game
/// 
/// // The paddle is represented by an underscore (_) character.
/// // The game runs in a loop, checking for key presses and updating the paddle position accordingly.
/// // The console is updated to reflect the paddle's position.
/// // Note: This code is intended to be run on Windows due to the use of conio.h and Windows API functions.
/// 

#include "Paddle.h"

#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h>
#include <thread>
#include <chrono>

const int HEIGHT = 10;                          // Height of the game area
const int WIDTH = 20;

// Implementation of the paddle class
paddle::paddle() 
{
    int paddleX = WIDTH / 2; // Initial horizontal position of the paddle
    bool gameRunning = true;

    HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // Get handle to standard output

    auto draw = [&](int x) {                        // Lambda to draw the paddle at position x
        COORD origin = { 0, HEIGHT };               // Top-left corner
        SetConsoleCursorPosition(handleOutput, origin);     // Move cursor to top-left (no full clear)
        for (int i = 0; i < WIDTH; ++i) {           // Draw the paddle
            if (i == x) std::cout << "_";           // Paddle representation
            else std::cout << " ";                  // Empty space
        }
        std::cout << std::flush;                    // Flush output to ensure it appears immediately
        };

    draw(paddleX);                                  // initial draw

    while (gameRunning) {
        if (_kbhit()) {
            char current = _getch();                // Get the current key press

			if (current == 'a' && paddleX > 0) {    // Move left
                paddleX--;                          // Move paddle left
				draw(paddleX); 					    // Redraw paddle
            }
            else if (current == 'd' && paddleX < WIDTH - 1) {
                paddleX++;                          // Move paddle right
                draw(paddleX);
            }
            else if (current == 'q') {              // Quit game
                gameRunning = false;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // throttle (~60 FPS) 
    }
}