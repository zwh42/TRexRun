#include <iostream>
#include "renderer.h" 


int main() {
    constexpr std::size_t SCREEN_WIDTH{1024};
    constexpr std::size_t SCREEN_HEIGHT{640};
    
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    std::cout<<"SDL renderer create successfully!" << std::endl;
    return 0;



}