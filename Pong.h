#pragma once
#include "Frame.h"
#include "Paddle.h"
#include "Ball.h"

class Pong {
public:
	Pong();
	void run();
private:
	Frame frame;
	Paddle paddle;
	Ball ball;
	bool gameRunning;
	bool paused;
	void proccessInput();
	void update();
	void draw_pong();
};