#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "renderer.h"
#include "imageobject.h"

class Game {
    public:
        Game();
        void run(Renderer &renderer, std::size_t target_frame_duration);
    
    private:
        TRex trex;
        bool is_running;
        bool is_jump;

        void handel_event();

}

#endif