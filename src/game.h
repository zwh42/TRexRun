#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "renderer.h"
#include "imageobject.h"

class Game {
    public:
        Game(Renderer* const _renderer, TRex trex);
        void run();
    
    private:
        Renderer* _renderer;
        TRex _trex;
        bool _is_running;
        bool _is_jump;

        void handel_event();

};

#endif