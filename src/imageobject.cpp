#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "imageobject.h"

TRex::TRex(std::string image_path){
    _image = IMG_Load(image_path.c_str());
    if (nullptr == _image){
        std::cerr << "could not load T Rex image!" << std::endl;
        std::cerr << "SDL Image Load Error: " << IMG_GetError() << std::endl;
    }

}
