//(SDL/ OpenGL code: window creation, texture upload, event polling)
//conversion simulation -> pixels
//pixel = v * 255;
//draw calls
//SDL_RenderCopy()

#include "rendering.h"

bool Renderer::initialize(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << SDL_GetError() << "\n";
        //std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
        //SDL_Quit();
        return false;
    }
    window = SDL_CreateWindow("1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,720,600,0);
    if( window == nullptr){
        std::cout << SDL_GetError() << "\n";
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if( renderer == nullptr){
        std::cout << SDL_GetError() << "\n";
        return false;
    }
    std::cout << "success\n";
    return true;
}

void Renderer::render(int r, int g, int b){
    
    SDL_SetRenderDrawColor(renderer, r, g, b, 250);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay( 1000);
}

void Renderer::shutdown(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit;
}
