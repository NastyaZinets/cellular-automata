#include "simulation.h"
#include <iostream>

//update step
Simulation::Simulation(int w, int h){
    U.resize(w * h);
    V.resize(w * h);
}

void Simulation::update( float dt){
    U[dt] = 0;
    V[dt] = 1;
}

void Simulation::view(){
    std::cout << "U ";
    for(auto el: U){
        std::cout << el << " ";
    }
    std::cout << "\n";
    std::cout << "V ";
    for(auto el: V){
        std::cout << el << " ";
    }

    std::cout << "\n";
}

//Laplacian

//float compute_lapalcian()

//initialization

//center full v
//other u
