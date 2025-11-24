#include "Paddle.h"

// Implementation of the paddle class
Paddle::Paddle(int startX) : positionX(startX) {
	paddleHandleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Paddle::moveLeft() {
	if (positionX > 0) {
		positionX--;
	}
}

void Paddle::moveRight(int maxWidth) {
	if (positionX < maxWidth) {
		positionX++;
	}
}

void Paddle::draw_paddle(int height) {
	COORD pos = { static_cast<SHORT>(positionX + 1), static_cast<SHORT>(height - 1) };
	SetConsoleCursorPosition(paddleHandleOutput, pos);
	std::cout << "_";
	std::cout << std::flush;
}

int Paddle::getX() const {
	return positionX;
}