#include "Ball.h"

Ball::Ball(float startX, float startY, float speed)
	: positionX(startX), positionY(startY), speed(speed), dirX(1), dirY(1) {
	ballHandleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Ball::move(int GAME_FPS) {
	float delta = speed / GAME_FPS;
	positionX += dirX * delta;
	positionY += dirY * delta;
}

void Ball::reverseX() {
	dirX *= -1;
}

void Ball::reverseY() {
	dirY *= -1;
}

void Ball::draw_ball() {
	COORD pos = {
		static_cast<SHORT>(positionX + 1), static_cast<SHORT>(positionY + 1) 
	};
	SetConsoleCursorPosition(ballHandleOutput, pos);
	std::cout << "O";
	std::cout << std::flush;
}

int Ball::getX() const {
	return static_cast<int>(positionX);
}

int Ball::getY() const {
	return static_cast<int>(positionY);
}