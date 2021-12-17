#include "utils.hpp"

utilsRequests::utilsRequests(void) {}

SDL_Rect utilsRequests::printStringCenter(SDL_Renderer* renderer, TTF_Font* font, std::string text, int y, int addToX, bool printRect)
{
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), SDL_Color{ 0, 0, 0, 255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	int t_w;
	int t_h;
	SDL_QueryTexture(texture, nullptr, nullptr, &t_w, &t_h);
	SDL_Rect rect{ (500/2 - t_w/2) + addToX ,y,t_w,t_h };
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
	if (printRect)
	{
		SDL_SetRenderDrawColor(renderer ,0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);
	}
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	return rect;
}
