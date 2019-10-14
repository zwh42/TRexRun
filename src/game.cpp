#include "game.h"
#include <iostream>
#include "SDL.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Game:: Game(Renderer* const renderer, Controller* const controller, TRex trex, Cactus cactus): 
    _renderer(renderer), _controller(controller), _trex(trex), _cactus(cactus){

};

void Game::run(){
    
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 target_frame_duration = 1000/60;
    Uint32 frame_duration;
    int frame_count = 0;

    int window_width;
    int window_height;
    SDL_GetRendererOutputSize(_renderer->get_renderer(), &window_width, &window_height);
    std::cout<<"window width: " << window_width <<", window height: " << window_height << std::endl; 
    
    srand (time(NULL));

    _trex.set_pos_x(trex_init_x);
    _trex.set_pos_y(trex_init_y);

    _cactus.set_pos_x(0);
    _cactus.set_pos_y(0);
    _cactus.set_width(0);
    _cactus.set_height(0);

   _renderer->render(&_trex);

    _is_running = true;
    while(_is_running){
       frame_start = SDL_GetTicks();

        _controller->handel_event(_is_running, &_trex);
        update(window_width, window_height);
        
        //_renderer->render(&_trex);
        _renderer->render(&_trex, &_cactus);

        frame_end = SDL_GetTicks();
        frame_duration = frame_end - frame_start;
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
            //std::cout<<"delay: " << target_frame_duration - frame_duration << std::endl;
        }
    }  
    
}

void Game::update(int window_width, int window_height){
    
    //t rex
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

    //cactus
    if (_cactus.get_pos_x() <= 0){ // cactus is outside the window
        int cactus_width = rand() % (cactus_width_high - cactus_width_low) + cactus_width_low;
        int cactus_height = rand() % (cactus_height_high - cactus_height_low) + cactus_height_low;

        _cactus.set_pos_x(window_width);
        _cactus.set_pos_y(500 - cactus_height);
        
        _cactus.set_width(cactus_width);
        _cactus.set_height(cactus_height);
    }else {
        _cactus.set_pos_x(_cactus.get_pos_x() - cactus_speed_x);
    }

    SDL_Rect _trex_rect = {_trex.get_pos_x(), _trex.get_pos_y(), _trex.get_width(), _trex.get_height()};
    SDL_Rect _cactus_rect = {_cactus.get_pos_x(), _cactus.get_pos_y(), _cactus.get_width(), _cactus.get_height()};

    if (check_collision(&_trex_rect, &_cactus_rect)){
        std::cout << "collision!" << std::endl;
    }
    

}

bool Game::check_collision(SDL_Rect* a, SDL_Rect* b){
    //std::cout << "trex x, y, w, h = "<<a->x<<", "<<a->y<<", "<<a->w<<", "<<a->h<<", "<<std::endl;
    //std::cout << "cactus x, y, w, h = "<<b->x<<", "<<b->y<<", "<<b->w<<", "<<b->h<<", "<<std::endl; 
    //std::cout<< "intersection result = " << SDL_HasIntersection(a, b) << std::endl;
    return SDL_HasIntersection(a, b);
}

