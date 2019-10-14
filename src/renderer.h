#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "trex.h"
#include "cactus.h"

class Renderer {
    public:
        Renderer(const std::size_t screen_width, const std::size_t screen_height);
        ~Renderer();

        //void render(TRex const trex, int const pos_x, int const pos_y, int const width, int const height);
        SDL_Renderer* get_renderer();

        void render(SDL_Surface* const sdl_surface, int const pos_x, int const pos_y, int const width, int const height);
        void render(TRex *trex);
        void render(TRex *trex, Cactus *cactus);

 private:
  SDL_Window *_sdl_window;
  SDL_Renderer *_sdl_renderer;

  const std::size_t _screen_width;
  const std::size_t _screen_height;

};

#endif