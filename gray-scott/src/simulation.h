#include <vector>

class Simulation{
    private:
        int width;
        int height;

        std::vector<double> U;
        std::vector<double> V;

        std::vector<double> U_next;
        std::vector<double> V_next;

        void calcAvgU(int i);
        int index(int x, int y);


    public:
        Simulation(int width, int height);
        void init();
        void update(float dt);
        void view();

        const std::vector<double>& getU() const;
        const std::vector<double>& getV() const;

        int getWidth() const;
        int getHeight() const;

};
