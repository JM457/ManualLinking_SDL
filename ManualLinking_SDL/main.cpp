#include<iostream>
#include<SDL.h>
#include<stdlib.h>
#include<time.h>
#include"Screen.h"
#include"Particle.h"
#include"Swarm.h"

using namespace std;
using namespace caveofprogramming;

int main(int argc, char* argv[]) {

	srand(time(NULL));
	
	Screen screen;
	if (screen.init() == false) {
		cout << "error in initializing SDL" << endl;
	}

	Swarm swarm;

	

	while (true)
	{
		// update particles
		
	    //animate color
		int elapsed = SDL_GetTicks();
		swarm.update();
		unsigned char green = (unsigned char((1 + sin(elapsed * 0.0004)) * 128));
		unsigned char red = (unsigned char((1 + cos(elapsed * 0.0002)) * 128));
		unsigned char blue = (unsigned char((1 + sin(elapsed * 0.0001)) * 128));


		//draw particles
		const Particle* const pParticle = swarm.getParticle();
		for (size_t i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticle[i];
			int x = (particle.m_x + 1) * Screen::ScreenWidth/2;
			int y = (particle.m_y + 1) * Screen::ScreenHeight/2;
			screen.setPixel(x, y, red, green,blue);
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