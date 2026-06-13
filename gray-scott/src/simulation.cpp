#include "simulation.h"
#include <iostream>

//update step
Simulation::Simulation(int w, int h){
    width = w;
    height = h;

    U.resize(w * h);
    V.resize(w * h);
}

void Simulation::update( float dt){
    //U[dt] = 0;
    //V[dt] = 1;

    for(size_t i=0; i< U.size(); i++){
        int y = i / width;
        int x = i % width + 1;

        if(y % 16 < 8){
            U[i] = 1;
        }
        else{
            U[i] = 0;
        }

        if(x % 16 < 8){
            V[i] = 0;
        }
        else{
            V[i] = 1;
        }
    }
}

void Simulation::view(){
    std::cout << "U ";
    for(auto el: U){
        std::cout << el << "";
    }
    std::cout << "\n";
    std::cout << "V ";
    for(auto el: V){
        std::cout << el << "";
    }

    std::cout << "\n";
}

const std::vector<double>& Simulation::getU() const{
    return U;
}

const std::vector<double>& Simulation::getV() const{
    return V;
}

int Simulation::getWidth() const{
    return width;
}

int Simulation::getHeight() const{
    return height;
}

//Laplacian

//float compute_lapalcian()

//initialization

//center full v
//other u
