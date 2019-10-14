#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "renderer.h"
#include "trex.h"
#include "cactus.h"
#include "controller.h"

class Game {
    public:
        Game(Renderer* const renderer, Controller* const controller, TRex trex, Cactus cactus);
        void run();
        void update(int window_width, int window_height);
        bool check_collision(SDL_Rect* a, SDL_Rect* b);

    
    private:
        Renderer* _renderer;
        Controller* _controller;
        TRex _trex;
        Cactus _cactus;
        bool _is_running;
        bool _is_jump;

        int trex_init_x = 160;
        int trex_init_y = 350;
        int trex_max_y = 100;
        int trex_speed_y = 5;
        int trex_air_time = 1000; //ms
        int trex_step_count = (trex_init_y - trex_max_y) / trex_speed_y;

        int cactus_width_low = 35;
        int cactus_width_high = 50;
        int cactus_height_low = 55;
        int cactus_height_high = 85;
        int cactus_speed_x = 6;

       
};

#endif