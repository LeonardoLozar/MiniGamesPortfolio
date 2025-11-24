#pragma once
#include <Windows.h>
#include <iostream>

class Ball {
public:
	Ball(float startX, float startY, float speed);
	void move(int fps);
	void reverseX();
	void reverseY();
	void draw_ball();
	int getX() const;
	int getY() const;
private:
	float positionX, positionY;
	float dirX, dirY;
	float speed;
	HANDLE ballHandleOutput;
};