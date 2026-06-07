//(SDL/ OpenGL code: window creation, texture upload, event polling)
//conversion simulation -> pixels
//pixel = v * 255;
//draw calls
//SDL_RenderCopy()

#include "rendering.h"

bool Renderer::initialize(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        //std::cout << SDL_GetError() << "\n";
        //SDL_Quit();
        return false;
    }
    return true;
}

void Renderer::render(){

}

void Renderer::shutdown(){

}
