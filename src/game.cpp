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
    
    _trex.set_pos_x(trex_init_x);
    _trex.set_pos_y(trex_init_y);

   _renderer->render(&_trex);

    _is_running = true;
    while(_is_running){
       
        _controller->handel_event(_is_running, &_trex);
        update();
        _renderer->render(&_trex);
    }  
    
}

void Game::update(){
    if (_trex.get_jump_state() == true && _trex.get_fall_state() == false){
        if(_trex.get_pos_y() > trex_max_y){
            _trex.set_pos_y(_trex.get_pos_y() - trex_speed_y);
        } else {
            _trex.set_fall_state(true);    
        }
    }
    
    if (_trex.get_fall_state() == true){
        if(_trex.get_pos_y() < trex_init_y){
                _trex.set_pos_y(_trex.get_pos_y() + trex_speed_y);
        }  else {
                _trex.set_fall_state(false);
                _trex.set_jump_state(false);      
            }            
        }
        
    
}

