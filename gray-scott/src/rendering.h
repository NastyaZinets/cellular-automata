#include <SDL2/SDL.h>
#include <iostream>

class Renderer{
    public:
        bool initialize();
        void render();
        void shutdown();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
};
