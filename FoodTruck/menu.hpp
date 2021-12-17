#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class menuRequests
{
public:
	menuRequests();

	int printText(TTF_Font* font, TTF_Font* font_small, SDL_Renderer* render, int ordi, int player);
	int printWin(bool playerWin, TTF_Font* font, TTF_Font* font_small, SDL_Renderer* render);
};