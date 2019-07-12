#include "Screen.h"

caveofprogramming::Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
}

bool caveofprogramming::Screen::init()
{
	// SDL video initialization check
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}
	//initialize window
	m_window = SDL_CreateWindow("Particle fire explosion",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		ScreenWidth, ScreenHeight,
		SDL_WINDOW_SHOWN);
	//Check if initialized
	if (m_window == NULL)
	{
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window,
		-1,
		SDL_RENDERER_PRESENTVSYNC);
	//Check if initialized
	if (m_renderer == NULL)
	{
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer,
		SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STATIC,
		ScreenWidth, ScreenHeight);
	//Check if initialized
	if (m_texture == NULL)
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	//Create a memory buffer for renderer color, RGBA, each channel takes 4 bytes=32bits
	m_buffer = new Uint32[ScreenWidth * ScreenHeight];

	for (size_t i = 0; i < ScreenWidth * ScreenHeight; i++)
	{
		m_buffer[i] = 0xff880ff;
	}




	return false;
}

void caveofprogramming::Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	Uint32 color = 0;

	color += red;
	color <= 8;
	color += green;
	color <= 8;
	color += blue;
	color <= 8;
	color += 0xff;

	m_buffer[(y * ScreenWidth) + x] = color;
}

void caveofprogramming::Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, ScreenWidth * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

bool caveofprogramming::Screen::ProcessEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return false;
		}
	}
	return true;
}

void caveofprogramming::Screen::close()
{
	delete m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	
}
