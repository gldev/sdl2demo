#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "./game.h"
#include "./logic.h"
#include "./render.h"

int main(int argc, char** argv) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Couldn't init video %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("RocketFuel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

    if(window == NULL) {
        fprintf(stderr, "SDL_CreateWindow error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(window == NULL) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    game_t game = {
        .board = {
            EMPTY_BOARD, EMPTY_BOARD, EMPTY_BOARD,
            EMPTY_BOARD, EMPTY_BOARD, EMPTY_BOARD, 
            EMPTY_BOARD, EMPTY_BOARD, EMPTY_BOARD
        },
        .player = PLAYER_ONE_BOARD,
        .state = RUNNING
    };



    SDL_Event e;
    while(game.state != QUIT) {
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    game.state = QUIT;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    click_on_cell(&game, e.button.x / CELL_WIDTH, e.button.y / CELL_HEIGHT);
                default: {}

            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_game(renderer, &game);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
