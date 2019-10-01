#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height)
    : _screen_width(screen_width),
      _screen_height(screen_height){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cerr << "SDL could not initialize!" << std::endl;
        std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
    }

    _sdl_window = SDL_CreateWindow("Run! T-Rex Run!", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, _screen_width, _screen_height, SDL_WINDOW_SHOWN);
    
    if (nullptr == _sdl_window){
        std::cerr << "SDL window could not be created." << std::endl;
        std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
    }

    _sdl_renderer = SDL_CreateRenderer(_sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == _sdl_renderer){
        std::cerr << "SDL renderer could not be created." << std::endl;
        std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
    }
}

    Renderer:: ~Renderer() {
        SDL_DestroyWindow(_sdl_window);
        SDL_Quit();    
    }




    