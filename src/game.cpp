#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(Renderer* const renderer, TRex trex): _renderer(renderer), _trex(trex){

};

void Game::run(){
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    
    _trex.update_position(450, 450);
    _trex.draw();
    
    _is_running = true;
    while(_is_running){
       
        handel_event();
    }  
    
}

void Game::handel_event(){
    SDL_Event e;
    
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            _is_running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_SPACE:
                    _is_jump = true;
                    std::cout<< "T-Rex jump!" << std::endl;  
                    break;
            }
        }
    }
    
}