#pragma once

// Forward declaration / public interface for the paddle class
// Actual implementation would be in Paddle.cpp

#include <Windows.h>
#include <iostream>

class Paddle
{
	public:
		Paddle(int startX);
		void moveLeft();
		void moveRight(int maxWidth);
		void draw_paddle(int height);
		int getX() const;
private:
	int positionX;
	HANDLE paddleHandleOutput;
};