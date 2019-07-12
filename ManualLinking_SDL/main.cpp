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
		int elapsed = SDL_GetTicks();
		Uint8 green = (ceil((1+sin(elapsed*0.0004)) * 128));
	    Uint8 red = (ceil((1 + cos(elapsed * 0.0002)) * 128));
	    Uint8 blue = (ceil((1 + sin(elapsed * 0.0001)) * 128));
	

		for (size_t y = 0; y <Screen::ScreenHeight ; y++)
		{
			for (size_t x = 0; x < Screen::ScreenWidth; x++)
			{
				screen.setPixel(x, y, red, green, blue);
			}
		}

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