#include "game.h"
#include <iostream>
#include "SDL.h"

Game:: Game(Renderer* const renderer, Controller* const controller, TRex trex): 
    _renderer(renderer), _controller(controller), _trex(trex){

};

void Game::run(){
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    
    int trex_init_x = 160;
    int trex_init_y = 350;
    int trex_max_y = 100;
    int trex_speed_y = 5;

    _trex.set_pos_x(trex_init_x);
    _trex.set_pos_y(trex_init_y);

    // _renderer->render(_trex.get_image(), _trex.get_pos_x(), _trex.get_pos_y(), _trex.get_width(), _trex.get_height());
    
    _renderer->render(&_trex);

    _is_running = true;
    while(_is_running){
       
        _controller->handel_event(_is_running, &_trex);
    }  
    
}

