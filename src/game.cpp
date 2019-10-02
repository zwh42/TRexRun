#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(){
    std::cout<<"game init..." << std::endl;
}

void Game::run(Renderer &renderer){
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    
    while(running){
        frame_start = SDL_GetTicks();
    
    }  
    
}

void Game::handel_event(){
    SDL_Event e;
    
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            is_running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_SPACE:
                    is_jump = true;
                    std::cout<< "T-Rex jump!" << std::endl;  
                    break;
            }
        }
    }
    
}