#ifndef IMAGE_OBJECT_H
#define IMAGE_OBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class ImageObject{
    public:
        ImageObject():
    
    private:
       

};

class TRex{
    public:
        TRex(std::string image_path, int width, int height, int pos_x, int pos_y);

    private:
        SDL_Surface * trex_surface = nullptr;
        int _width;
        int _height;
        int _pos_x;
        int _pos_y;

};


#endif