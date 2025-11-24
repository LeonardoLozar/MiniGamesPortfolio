/// Here is a simple console-based paddle game in C++ using Windows API for handling keyboard input and console output.
/// Controls:
/// a - Move paddle left
/// d - Move paddle right
/// q - Quit game
/// p - Pause/Unpause game
/// 
/// // The paddle is represented by an underscore (_) character.
/// // The ball is represented by an 'O' character.
/// // The game runs in a loop, checking for key presses and updating the paddle position accordingly.
/// // The console is updated to reflect the paddle's position.
/// // Note: This code is intended to be run on Windows due to the use of conio.h and Windows API functions.
/// 


#include "Pong.h"
#include <conio.h>
#include <thread>
#include <chrono>

const int GAME_WIDTH = 30;
const int GAME_HEIGHT = 10;
const int GAME_FPS = 60;
const float BALL_SPEED = 5.0f;

Pong::Pong()
	: frame(GAME_WIDTH, GAME_HEIGHT),
	paddle(GAME_WIDTH / 2),
	ball(GAME_WIDTH / 2, (GAME_HEIGHT / 2), BALL_SPEED),
	gameRunning(true),
	paused(false) {}

void Pong::run() {
	while (gameRunning) {
		proccessInput();
		if(!paused){
			update();
			draw_pong();
		}
		else {
			COORD pos = {0, GAME_HEIGHT + 2};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << "[PAUSA] Presiona 'p' para continuar" << std::flush;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / GAME_FPS));
	}
}

void Pong::proccessInput() {
	if (_kbhit()) {
		char key = _getch();
		if (key == 'a') {
			paddle.moveLeft();
		}
		else if (key == 'd') {
			paddle.moveRight(GAME_WIDTH);
		}
		else if (key == 'q') {
			gameRunning = false;
		}
		else if (key == 'p') {
			paused = !paused;
		}
	}
}

void Pong::update() {
	ball.move(GAME_FPS);
	if (ball.getX() <= 0 || ball.getX() >= GAME_WIDTH - 1) {
		ball.reverseX();
	}
	if (ball.getY() <= 0) {
		ball.reverseY();
	}
	if (ball.getY() == GAME_HEIGHT && ball.getY() == paddle.getX()) {
		ball.reverseY();
	}
	if (ball.getY() > GAME_HEIGHT) {
		gameRunning = false;
	}
	if (ball.getX() == paddle.getX() && ball.getY() == GAME_HEIGHT - 1 ) {
		ball.reverseY();
	}
}

void Pong::draw_pong() {
	frame.draw_frame();
	paddle.draw_paddle(GAME_HEIGHT);
	ball.draw_ball();
}

