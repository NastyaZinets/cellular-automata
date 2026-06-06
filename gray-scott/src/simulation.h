#include <vector>

class Simulation{
    private:
        int width;
        int height;

        std::vector<float> U;
        std::vector<float> V;
    public:
        Simulation(int width, int height);
        void update(float dt);
        void view();
};
