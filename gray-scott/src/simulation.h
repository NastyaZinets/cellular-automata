#include <vector>

class Simulation{
    private:
        int width;
        int height;

        std::vector<double> U;
        std::vector<double> V;

    public:
        Simulation(int width, int height);
        void update(float dt);
        void view();

        const std::vector<double>& getU() const;
        const std::vector<double>& getV() const;

        int getWidth() const;
        int getHeight() const;

};
