#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "cactus.h"


Cactus::Cactus(std::string image_path, int const width, int const height, int pos_x, int pos_y):
     _width(width), _height(height), _pos_x(pos_x), _pos_y(pos_y){
    _image = IMG_Load(image_path.c_str());
    if (nullptr == _image){
        std::cerr << "could not load Cactus image!" << std::endl;
        std::cerr << "SDL Image Load Error: " << IMG_GetError() << std::endl;
    }
}

Cactus::Cactus(std::string image_path){
    _image = IMG_Load(image_path.c_str());
    if (nullptr == _image){
        std::cerr << "could not load Cactus image!" << std::endl;
        std::cerr << "SDL Image Load Error: " << IMG_GetError() << std::endl;
    }    
}

int Cactus::get_width() const {
    return _width;
}

int Cactus::get_height() const {
    return _height;
}

void Cactus::set_width(int width){
    _width = width;
}

void Cactus::set_height(int height){
    _height = height;
}

void Cactus::set_pos_x(int x){_pos_x = x;}
void Cactus::set_pos_y(int y){_pos_y = y;}

int Cactus::get_pos_x() const {return _pos_x;}
int Cactus::get_pos_y() const {return _pos_y;}



SDL_Surface* Cactus::get_image() const {
    return _image;
}