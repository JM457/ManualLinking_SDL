#include<SDL.h>
namespace caveofprogramming {
	class Screen
	{
	public:
		const static int ScreenWidth = 800;
		const static int ScreenHeight = 600;
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer;
	public:
		Screen();
		bool init();
		void setPixel();
		void update();
		bool ProcessEvents();
		void close();
	};
}