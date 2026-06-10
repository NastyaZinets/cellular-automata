#include <SDL2/SDL.h>
#include <iostream>

class Renderer{
    public:
        Renderer();
        bool initialize();
        void render(int r, int g, int b);
        void shutdown();

        void processEvents();
        bool isRunning() const;

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        SDL_Event event;

        bool running;
};
