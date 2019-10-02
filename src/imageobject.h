#ifndef IMAGE_OBJECT_H
#define IMAGE_OBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "renderer.h"

class TRex{
    public:
        TRex(std::string image_path, Renderer* const renderer, int const width, int const height);
        void draw(int const pos_x, int const pos_y);
        void draw();
        void update_position(int const pos_x, int const pos_y); 

    private:
        SDL_Surface*  _image = nullptr;
        //SDL_Texture* _texture = nullptr;
        Renderer* _renderer;
        int _width;
        int _height;
        int _pos_x;
        int _pos_y;
       

};


#endif