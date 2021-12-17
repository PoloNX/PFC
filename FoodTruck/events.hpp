#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class eventsRequests
{
public:
	eventsRequests();

	int mousseClick(SDL_Rect Pierre, SDL_Rect Feuille, SDL_Rect Ciseaux); //Pierre = 1, Feuille = 2, Ciseaux = 3
	int mousseClickEnd(SDL_Rect rejouer, SDL_Rect quitter); //Pierre = 1, Feuille = 2, Ciseaux = 3
};