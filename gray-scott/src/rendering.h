#include <SDL2/SDL.h>
#include <iostream>

class Renderer{
    public:
        bool initialize();
        void render();
        void shutdown();
};
