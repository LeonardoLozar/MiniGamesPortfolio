#pragma once
#include <Windows.h> // For HANDLE and console functions
#include <iostream> // For std::cout and std::flush to draw the frame

class Frame {
public:
	Frame(int frameWidth, int frameHeight);
	void draw_frame();
	int getFrameWidth() const;
	int getFrameHeight() const;
private:
	int frameWidth;
	int frameHeight;
	HANDLE frameHandleOutput;
};