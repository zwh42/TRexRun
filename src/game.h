#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "renderer.h"
#include "trex.h"
#include "controller.h"

class Game {
    public:
        Game(Renderer* const renderer, Controller* const controller, TRex trex);
        void run();
    
    private:
        Renderer* _renderer;
        Controller* _controller;
        TRex _trex;
        bool _is_running;
        bool _is_jump;

       
};

#endif