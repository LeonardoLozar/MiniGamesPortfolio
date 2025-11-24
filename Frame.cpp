#include "Frame.h"

Frame::Frame(int width, int height) : frameWidth(width), frameHeight(height) {
	frameHandleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // Get handle to standard output
}
void Frame::draw_frame() {
	COORD origin = { 0,0 };                            // Top-left corner
	SetConsoleCursorPosition(frameHandleOutput, origin);

	for(int top = 0; top <= frameWidth; ++top) {              // Draw top border
		std::cout << "#";                               // Flush output to ensure it appears immediately
	}

	for (int row = 0; row < frameHeight; ++row) {       // Draw game area
		std::cout << "#";
		for (int col = 0; col < frameWidth; ++col) {
			std::cout << " ";
		}
		std::cout << "#\n";
	}

	for (int floor = 0; floor <= frameWidth + 1; ++floor) {
		std::cout << "#";
	}
	std::cout << "\n";
}

int Frame::getFrameWidth() const { return frameWidth; }
int Frame::getFrameHeight() const { return frameHeight; }