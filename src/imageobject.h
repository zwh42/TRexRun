#ifndef IMAGE_OBJECT_H
#define IMAGE_OBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>


class TRex{
    public:
        TRex(std::string image_path);
        SDL_Surface* get_surface() const {
            return _image;
        }     

    private:
        SDL_Surface*  _image = nullptr;
        //SDL_Texture* _texture = nullptr;
        int _width;
        int _height;
        int _pos_x;
        int _pos_y;

};


#endif