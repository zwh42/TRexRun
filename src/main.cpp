#include <iostream>
#include <string>
#include "renderer.h"



int main() {
    constexpr std::size_t SCREEN_WIDTH{1024};
    constexpr std::size_t SCREEN_HEIGHT{640};
    std::string TREX_IMAGE{"../res/trex2.png"};
    
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    TRex trex(TREX_IMAGE);
    renderer.render(trex);

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