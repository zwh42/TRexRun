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
        void update();
    
    private:
        Renderer* _renderer;
        Controller* _controller;
        TRex _trex;
        bool _is_running;
        bool _is_jump;

        int trex_init_x = 160;
        int trex_init_y = 350;
        int trex_max_y = 100;
        int trex_speed_y = 5;
        int trex_air_time = 1000; //ms
        int trex_step_count = (trex_init_y - trex_max_y) / trex_speed_y;

       
};

#endif