#include<iostream>
#include<SDL.h>
#include"Screen.h"

using namespace std;
using namespace caveofprogramming;

int main(int argc, char* argv[]) {

	Screen screen;
	if (screen.init() == false) {
		cout << "error in initializing SDL" << endl;
	}

	while (true)
	{
		// update particles
		//draw particles
		for (size_t y = 0; y <Screen::ScreenHeight ; y++)
		{
			for (size_t x = 0; x < Screen::ScreenWidth; x++)
			{
				screen.setPixel(x, y, 128, 0, 128);
			}
		}


		screen.setPixel(400, 300, 255, 255, 255);
		// update screen
		screen.update();
		//Check for events and messages
		if (screen.ProcessEvents() == false) {
			break;
		}
	}

	// Destroy objects
	screen.close();

	return 0;
}