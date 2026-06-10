#include <SDL2/SDL.h>
#include <iostream>

class Renderer{
    public:
        bool initialize();
        void render(int r, int g, int b);
        void shutdown();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
};
