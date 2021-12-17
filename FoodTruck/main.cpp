#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include "utils.hpp"
#include "menu.hpp"
#include "random.hpp"
#include "events.hpp"

menuRequests* sessionMenu = new menuRequests;
randomRequests* sessionRandom = new randomRequests;

int main(int argc, char* argv[])
{
    if (TTF_Init() < 0) //TTF-Init
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0)   //Init_video
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    bool isOpen = true; //Booléenne pour l'app
    bool endPfc = false;
    SDL_Window* pWindow = SDL_CreateWindow("PFC", 500, 500, 500, 500, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    TTF_Font* font = TTF_OpenFont("D:\\Programmation\\C++\\Projets\\switch\\sigpatch-downloader\\romfs\\data\\BerlinSansFB.ttf", 40);
    TTF_Font* font_small = TTF_OpenFont("D:\\Programmation\\C++\\Projets\\switch\\sigpatch-downloader\\romfs\\data\\BerlinSansFB.ttf", 20);
    int choice = 0; //0 = menu
    int scoreOrdi = 0, scoreUser = 0;
    eventsRequests* sessionEvents = new eventsRequests;

    while(isOpen)
    {
        if (!endPfc)
            choice = sessionMenu->printText(font, font_small, pRenderer, scoreOrdi, scoreUser);
        
        if (choice ==  1 || choice == 2 || choice == 3){
            SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
            SDL_RenderClear(pRenderer);
            std::string returnValue = sessionRandom->computerTurn(choice);
            utilsRequests* sessionUtils = new utilsRequests;
            sessionUtils->printStringCenter(pRenderer, font_small, returnValue, 250, 0, false);
            if (returnValue[0] == 'G')
                scoreUser++;
            if (returnValue[0] == 'P')
                scoreOrdi++;
            SDL_RenderPresent(pRenderer);
            SDL_Delay(1000);
            choice = 0;
        }

        if (scoreOrdi == 3) {
            endPfc = true;
            if (sessionMenu->printWin(false, font, font_small, pRenderer) == 1) {
                scoreOrdi = 0;
                scoreUser = 0;
                endPfc = false;
            }
        }
        if (scoreUser == 3) {
            endPfc = true;
            if (sessionMenu->printWin(true, font, font_small, pRenderer) == 1) {
                scoreOrdi = 0;
                scoreUser = 0;
                endPfc = false;
            }
        }

        SDL_RenderPresent(pRenderer);        
    }
    return EXIT_SUCCESS;
}