#include "menu.hpp"
#include "utils.hpp"
#include "events.hpp"
#include <iostream>

menuRequests::menuRequests(void) {
}

utilsRequests* sessionUtils = new utilsRequests;
eventsRequests* sessionEvents = new eventsRequests;

int menuRequests::printWin(bool playerWin, TTF_Font* font, TTF_Font* font_small, SDL_Renderer* render)
{
	SDL_Rect rectPlay{ 0, 0, 0, 0 }, rectExit{ 0, 0, 0, 0 };
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_RenderClear(render);
	if (playerWin)
		sessionUtils->printStringCenter(render, font_small, "Bravo vous avez gagné, voulez-vous refaire une partie ?", 250, 0, false);
	if (!playerWin) 
		sessionUtils->printStringCenter(render, font_small, "Dommage vous avez perdu, voulez-vous refaire une partie ?", 250, 0, false);
	rectPlay = sessionUtils->printStringCenter(render, font, "Rejouer", 200, -75, true);
	rectExit = sessionUtils->printStringCenter(render, font, "Quitter", 200, 75, true);
	if (sessionEvents->mousseClickEnd(rectPlay, rectExit) == 1) 
		return 1;
}

int menuRequests::printText(TTF_Font* font, TTF_Font* font_small, SDL_Renderer* render, int ordi, int player)
{
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255 );
	SDL_RenderClear(render);

	SDL_Rect rectPierre{ 0, 0, 0, 0 }, rectFeuille{ 0, 0, 0, 0 }, rectCiseaux{ 0, 0, 0, 0 };

	sessionUtils->printStringCenter(render, font, "Pierre Feuille Ciseaux", 20, 0, false);
	sessionUtils->printStringCenter(render, font_small, "Par Charlie Geyre 2nd2", 60, 0, false);
	rectPierre = sessionUtils->printStringCenter(render, font, "pierre", 200, -150, true);
	rectFeuille = sessionUtils->printStringCenter(render, font, "feuille", 200, 0, true);
	rectCiseaux = sessionUtils->printStringCenter(render, font, "ciseaux", 200, 150, true);
	sessionUtils->printStringCenter(render, font, ("Ordi : " + std::to_string(ordi)), 100, 150, false);
	sessionUtils->printStringCenter(render, font, ("Joueur : " + std::to_string(player)), 100, -150, false);
	int choice = sessionEvents->mousseClick(rectPierre, rectFeuille, rectCiseaux);
	return choice;
}