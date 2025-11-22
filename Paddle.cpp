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

// Game area dimensions
const int GAME_HEIGHT = 10;                                 // Height of the game area
const int GAME_WIDTH = 30;                                  // Width of the game area
const int GAME_FPS = 60;                                         // Frames per second

// Implementation of the paddle class
paddle::paddle() 
{
    int paddleX = GAME_WIDTH / 2; // Initial horizontal position of the paddle
    bool gameRunning = true;

    HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // Get handle to standard output

    auto render_game = [&](int x) {                         // Lambda to draw the paddle at position x
        COORD origin = { 0, 0 };                            // Top-left corner
        SetConsoleCursorPosition(handleOutput, origin);     // Move cursor to top-left (no full clear)

		for (int i = 0; i <= GAME_WIDTH; ++i) {              // Draw top border
            std::cout << "#";                               // Flush output to ensure it appears immediately
        }
		std::cout << "#\n";

		for (int row = 0; row < GAME_HEIGHT; ++row) {       // Draw game area
			std::cout << "#";                               // Left border
            for (int col = 0; col < GAME_WIDTH; ++col) {    // Draw each column
				std::cout << " ";                           // Empty space
            }
            std::cout << "#\n";                             // Right border and new line
        }

		for (int floor = 0; floor <= GAME_WIDTH + 1; ++floor) {  // Draw bottom border
            std::cout << "#";
        }
		std::cout << "\n";

		COORD paddlePos = { 
			static_cast<SHORT>(x + 1),                      // Paddle X position + 1 for left border
			static_cast<SHORT>(1 + (GAME_HEIGHT))                 // Paddle Y position at bottom
        }; // Paddle position | static_cast to SHORT (x+1) to 
		
        SetConsoleCursorPosition(handleOutput, paddlePos);  // Position cursor for paddle
		std::cout << "_";                                   // Draw paddle
		std::cout << std::flush;                            // Flush output to ensure it appears immediately
    };

    render_game(paddleX);                                  // initial draw

    while (gameRunning) {
		if (_kbhit()) {                                    // Check if a key has been pressed
            char current = _getch();                       // Get the current key press

			if (current == 'a' && paddleX > 0) {           // Move left
                paddleX--;                                 // Move paddle left
                render_game(paddleX); 					   // Redraw paddle
            }
            else if (current == 'd' && paddleX < GAME_WIDTH - 1) {
                paddleX++;                                 // Move paddle right
                render_game(paddleX);
            }
            else if (current == 'q') {                     // Quit game
                gameRunning = false;
            }
        }

		int frameTime = 1000 / GAME_FPS;                   // Frame time in milliseconds
		std::this_thread::sleep_for(std::chrono::milliseconds(frameTime)); // throttle frame rate  
    }
}