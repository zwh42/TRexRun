#include <iostream>
#include "controller.h"
#include "trex.h"

void Controller::handel_event(bool &is_running, TRex *trex) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            is_running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_SPACE:
                    std::cout<< "SPACE key pressed, T-Rex jump!" << std::endl;  
                    trex->set_jump_state(true);
                    trex->set_fall_state(false);
                    break;
            }
        }
    }
}