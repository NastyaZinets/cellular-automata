//(SDL/ OpenGL code: window creation, texture upload, event polling)
//conversion simulation -> pixels
//pixel = v * 255;
//draw calls
//SDL_RenderCopy()

#include "rendering.h"

Renderer::Renderer(){
    window = nullptr;
    renderer = nullptr;
    texture = nullptr;
    running = false;
}

bool Renderer::initialize(int w, int h){
    width = w;
    height = h;

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << SDL_GetError() << "\n";
        //std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
        //SDL_Quit();
        return false;
    }

    window = SDL_CreateWindow("1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,height,0);
    if( window == nullptr){
        std::cout << SDL_GetError() << "\n";
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if( renderer == nullptr){
        std::cout << SDL_GetError() << "\n";
        return false;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STREAMING, width, height);
    if( texture == nullptr){
        std::cout << SDL_GetError() << "\n";
        return false;
    }

    pixels.resize(width * height);

    running = true;

    std::cout << "success\n";
    return true;
}

void Renderer::render(const std::vector<double>& U, const std::vector<double>& V){
    
    for( size_t i = 0; i< U.size(); i++){
        uint8_t brightness = static_cast<uint8_t>(255 * U[i]);
        pixels[i] =  (brightness << 24) | (brightness << 16) | (brightness << 8) | 0xFF;
    }
    
    SDL_UpdateTexture(texture, NULL, pixels.data(), width*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    //SDL_SetRenderDrawColor(renderer, r, g, b, 250);
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}

void Renderer::shutdown(){
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Renderer::isRunning() const{
    return running;
}

void Renderer::processEvents(){
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            running = false;
        }
    }
}
