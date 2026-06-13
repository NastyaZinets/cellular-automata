#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

class Renderer{
    public:
        Renderer();
        bool initialize(int width, int height);
        //void render(int r, int g, int b);
        void render(const std::vector<double>& U, const std::vector<double>& V);
        void shutdown();

        void processEvents();
        bool isRunning() const;

    private:
        int width;
        int height;

        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;

        std::vector<uint32_t> pixels;

        SDL_Event event;
        bool running;
};
