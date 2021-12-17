#include "events.hpp"
#include "menu.hpp"
#include <iostream>

eventsRequests::eventsRequests(void) {
}

bool IsInRectangle(int x, int y, const SDL_Rect& rect)
{
    return (x > rect.x) && (x <= rect.x + rect.w) &&
    (y > rect.y) && (y <= rect.y + rect.h);
}

int eventsRequests::mousseClickEnd(SDL_Rect rejouer, SDL_Rect quitter)
{
    SDL_Event events;

    if (SDL_PollEvent(&events))
    {
        if (events.type == SDL_QUIT)
        {
            SDL_Quit();
        }

        if (events.type == SDL_MOUSEBUTTONUP)
        {
            if (IsInRectangle(events.button.x, events.button.y, rejouer))
            {
                return 1;
            }

            if (IsInRectangle(events.button.x, events.button.y, quitter))
            {
                SDL_Quit();
            }
        }
    }

    return 0;
}

int eventsRequests::mousseClick(SDL_Rect Pierre, SDL_Rect Feuille, SDL_Rect Ciseaux)
{
	SDL_Event events;

	if (SDL_PollEvent (&events))
	{
        if (events.type == SDL_QUIT)
            {
                SDL_Quit();
            }

            if (events.type == SDL_MOUSEBUTTONUP)
            {
                if (IsInRectangle(events.button.x, events.button.y, Pierre))
                {
                    return 1;
                }

                if (IsInRectangle(events.button.x, events.button.y, Feuille))
                {
                    return 2;    
                }
                
                if (IsInRectangle(events.button.x, events.button.y, Ciseaux))
                {
                    return 3;
                }
            }
	}

    return 0;
}