#ifndef TREX_H
#define TREX_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class TRex{
    public:
        TRex(std::string image_path, int const width, int const height, int pos_x, int pos_y);
        int get_width() const;
        int get_height() const;
        
        void set_pos_x(int);
        void set_pos_y(int);

        int get_pos_x() const;
        int get_pos_y() const;

        void set_jump_state(bool state);
        bool get_jump_state() const;

        void set_fall_state(bool state);
        bool get_fall_state() const;

        SDL_Surface* get_image() const; 

    private:
        SDL_Surface*  _image = nullptr;
        
        int _width;
        int _height;
        int _pos_x;
        int _pos_y;
        bool _is_jump;
        bool _is_fall;
};

#endif