#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h>

class randomRequests
{
public:
	randomRequests();

	std::string computerTurn(int choice);	//1 = victoire 2 = d�faite 3 = �galit�
};
