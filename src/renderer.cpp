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


void Renderer::render(SDL_Surface* const sdl_surface, int const pos_x, int const pos_y, int const width, int const height){
    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(_sdl_renderer, sdl_surface);
    SDL_Rect sdl_rect = {pos_x, pos_y, width, height};
    SDL_RenderCopy(_sdl_renderer, sdl_texture, NULL, &sdl_rect);
    SDL_RenderPresent(_sdl_renderer);
}

void Renderer::render(TRex *trex){
    SDL_RenderClear(_sdl_renderer);

    SDL_Texture* trex_texture = SDL_CreateTextureFromSurface(_sdl_renderer, trex->get_image());
    SDL_Rect trex_rect = {trex->get_pos_x(), trex->get_pos_y(), trex->get_width(), trex->get_height()};
    SDL_RenderCopy(_sdl_renderer, trex_texture, NULL, &trex_rect);
    SDL_RenderPresent(_sdl_renderer);    
}


    