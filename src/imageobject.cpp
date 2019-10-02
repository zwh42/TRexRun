#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "imageobject.h"

TRex::TRex(std::string image_path, Renderer *const renderer, int const width, int const height):
_renderer(renderer), _width(width), _height(height){
    _image = IMG_Load(image_path.c_str());
    if (nullptr == _image){
        std::cerr << "could not load T Rex image!" << std::endl;
        std::cerr << "SDL Image Load Error: " << IMG_GetError() << std::endl;
    }

}

void TRex::draw(int const pos_x, int const pos_y){
    _renderer->render(_image, pos_x, pos_y, _width, _width);    
}

void TRex::draw(){
    _renderer->render(_image, _pos_x, _pos_y, _width, _width);    
}

void TRex::update_position(int const pos_x, int const pos_y){
    _pos_x = pos_x;
    _pos_y = pos_y;
} 


