//(SDL/ OpenGL code: window creation, texture upload, event polling)
//conversion simulation -> pixels
//pixel = v * 255;
//draw calls
//SDL_RenderCopy()

#include "rendering.h"

bool Renderer::initialize(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << SDL_GetError() << "\n";
        //SDL_Quit();
        return false;
    }
    window = SDL_CreateWindow("1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,720,600,0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    std::cout << "success\n";
    return true;
}

void Renderer::render(){
    
    int color_green = 255;
    int color_red = 0;
    //SDL_SetRenderDrawColor(renderer, color_red, color_green, 0, 250);
    //SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);
    //SDL_Delay(2000);
    while(color_green > 0){
        SDL_SetRenderDrawColor(renderer, color_red, color_green, 0, 250);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        color_green -= 10;
        color_red += 10;
    }
}

void Renderer::shutdown(){

}
