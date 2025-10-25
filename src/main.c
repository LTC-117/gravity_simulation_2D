#include <SDL2/SDL.h>
#include "main.h"
#include "gravity.h"


int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Gravity Sim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_BORDERLESS);
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    if (surface == NULL) {
        printf("ERROR");
    }

    cel_body p1 = define_planet(20, 0, 0, 450, 300);
    cel_body p2 = define_planet(5, 0, 3.5, 300, 300);

    SDL_Rect erase_rect = (SDL_Rect){0,0,WIDTH,HEIGHT};
    SDL_Event event;
    int simulation_running = 1;

    while (simulation_running != 0) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                simulation_running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    simulation_running = 0;
                }
            }
        }

        SDL_FillRect(surface, &erase_rect, COLOR_BLACK);

        fill_planet(surface, p1, COLOR_GREEN);
        fill_planet(surface, p2, COLOR_CYAN);

        //        update_planet_pos(&p1, &p2, 1);
        update_planet_pos(&p2, &p1, 1);

        SDL_UpdateWindowSurface(window);
        SDL_Delay(5);
    }
}
