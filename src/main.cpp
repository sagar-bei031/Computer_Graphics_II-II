#include "DDA.hpp"
#include "BLA.hpp"
#include "MCA.hpp"
#include "MEA.hpp"
#include "rectangle.hpp"
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Computer Graphics Lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        DDA::drawLine(renderer, 800, 0, 960, 720);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        BLA::drawLine(renderer, 800, 720, 960, 0); /* BLA is more efficient and accurate. */

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        MCA::drawCircle(renderer, 700, 400, 200);

        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        MEA::drawEllipse(renderer, 600, 400, 200, 100);

        Rectangle rec(50, 50, 200, 100, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        rec.render(renderer);
        
        rec.scale(2, 2);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        rec.render(renderer);

        rec.translate(0, 250);
        SDL_SetRenderDrawColor(renderer, 100, 200, 0, 255);
        rec.render(renderer);

        rec.rotate(-M_PI_4);
        SDL_SetRenderDrawColor(renderer, 0, 200, 100, 255);
        rec.render(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
