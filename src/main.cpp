#include <iostream>
#include <string>
#include "renderer.h"



int main() {
    constexpr std::size_t SCREEN_WIDTH{1024};
    constexpr std::size_t SCREEN_HEIGHT{640};
    constexpr int TREX_WIDHT{100};
    constexpr int TREX_HEIGHT{150};
    constexpr int TREX_POS_X{50};
    constexpr int TREX_POS_Y{350};
    std::string TREX_IMAGE{"../res/trex2.png"};
    
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    TRex trex(TREX_IMAGE);
    renderer.render(trex, TREX_POS_X, TREX_POS_Y, TREX_WIDHT, TREX_HEIGHT);

    std::cout<<"SDL renderer create successfully!" << std::endl;
    
    
    
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
            quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
        }
    }
    
    
    return 0;



}