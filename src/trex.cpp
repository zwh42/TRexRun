#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "trex.h"


TRex::TRex(std::string image_path, int const width, int const height, int pos_x, int pos_y):
     _width(width), _height(height), _pos_x(pos_x), _pos_y(pos_y){
    _image = IMG_Load(image_path.c_str());
    if (nullptr == _image){
        std::cerr << "could not load T Rex image!" << std::endl;
        std::cerr << "SDL Image Load Error: " << IMG_GetError() << std::endl;
    }
    _is_jump = false;
}

int TRex::get_width() const {
    return _width;
}

int TRex::get_height() const {
    return _height;
}

void TRex::set_pos_x(int x){_pos_x = x;}
void TRex::set_pos_y(int y){_pos_y = y;}

int TRex::get_pos_x() const {return _pos_x;}
int TRex::get_pos_y() const {return _pos_y;}

void TRex::set_jump_state(bool state){
    _is_jump = state;    
}

bool TRex::get_jump_state() const{
    return _is_jump;
}

void TRex::set_fall_state(bool state){
    _is_fall = state;
}
bool TRex::get_fall_state() const {
    return _is_fall;
}

SDL_Surface* TRex::get_image() const {
    return _image;
}