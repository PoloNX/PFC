#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class utilsRequests
{
	public:
		utilsRequests();

		SDL_Rect printStringCenter(SDL_Renderer* renderer, TTF_Font* font, std::string text, int y, int addToX, bool printRect);
};