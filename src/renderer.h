#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
// #include "imageobject.h"

class Renderer {
    public:
        Renderer(const std::size_t screen_width, const std::size_t screen_height);
        ~Renderer();

        //void Render(TRex const trex);
        //void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *_sdl_window;
  SDL_Renderer *_sdl_renderer;

  const std::size_t _screen_width;
  const std::size_t _screen_height;

};

#endif