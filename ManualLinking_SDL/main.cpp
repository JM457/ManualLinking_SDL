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
		//Check for events and messages
		if (screen.ProcessEvents() == false) {
			break;
		}
	}

	// Destroy objects
	screen.close();

	return 0;
}