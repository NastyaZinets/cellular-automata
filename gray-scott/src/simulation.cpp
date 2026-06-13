#include "simulation.h"
#include <iostream>

//update step
Simulation::Simulation(int w, int h){
    width = w;
    height = h;

    U.resize(w * h);
    V.resize(w * h);

    U_next.resize(w * h);
    V_next.resize(w * h);
}

int Simulation::index(int x, int y){
    return y * width + x;
}

void Simulation::init(){
    for(size_t i = U.size()/3; i< U.size()*2/3; i++){
        if(  i % width > width/3 && i % width < width*2/3 ){
        U[i] = 1;
        }
    }
}

void Simulation::calcAvgU(int i){
    
    double sum = 0;
    int num = 0; 

    //i_up
    if(i-width >= 0) {
        sum += U[i-width];
        num++;
    }

    //i_down
    if(i+width < U.size()){
        sum += U[i+width];
        num++;
    }

    //i_left
    if(i % width > 0){
        sum += U[i-1];
        num++;
    }

    //i_right
    if(i % width < width - 1){
        sum += U[i+1];
        num++;
    }

    if( num > 0){
        sum = sum/num;
    }

    U_next[i] = sum;
}



void Simulation::update( float dt){
    for(size_t i = 0; i < U.size(); i++){
        Simulation::calcAvgU(i);
    }

    U = U_next;
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
