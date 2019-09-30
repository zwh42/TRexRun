#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

int main() {
    SDL_Window * window = nullptr;

    SDL_Surface * window_surface = nullptr;
    SDL_Surface * image_surface = nullptr;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

    window_surface = SDL_GetWindowSurface(window);
    image_surface = IMG_Load("../res/cactus.png");

    SDL_BlitSurface(image_surface, NULL, window_surface, NULL);

    SDL_UpdateWindowSurface(window);

    SDL_Event e;
bool quit = false;
while (!quit){
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            quit = true;
        }
        if (e.type == SDL_KEYDOWN){
            quit = true;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN){
            quit = true;
        }
    }
}

    SDL_DestroyWindow(window);
    SDL_FreeSurface(image_surface);
    SDL_Quit();
}