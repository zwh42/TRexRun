#include <iostream>
#include <string>

#include "renderer.h"
#include "game.h"
#include "controller.h"

int main() {
    constexpr std::size_t SCREEN_WIDTH{1024};
    constexpr std::size_t SCREEN_HEIGHT{640};
    constexpr int TREX_WIDHT{100};
    constexpr int TREX_HEIGHT{150};
    constexpr int TREX_POS_X{50};
    constexpr int TREX_POS_Y{350};
    std::string TREX_IMAGE{"../res/trex2.png"};
    std::string CACTUS_IMAGE{"../res/cactus.png"};
    

    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    Controller controller;
    
    TRex trex(TREX_IMAGE, TREX_WIDHT, TREX_HEIGHT, TREX_POS_X, TREX_POS_Y);
    Cactus cactus(CACTUS_IMAGE);
    Game game(&renderer, &controller, trex, cactus);
    game.run();

/*    
    TRex trex(TREX_IMAGE, &renderer, TREX_WIDHT, TREX_HEIGHT);
    trex.draw(TREX_POS_X, TREX_POS_Y);
    
    trex.update_position(450, 450);
    trex.draw();

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

*/

    
    return 0;



}