//init rendering
//init simulation
//load config

//while(running){
//    process input
//    update simulation
//    render frame
//}

#include "simulation.h"
#include "rendering.h"

int main(int argc, char* argv[]){
    //Simulation first_try(4, 4);
    //first_try.view();
    //first_try.update(2);
    //first_try.view();

    Renderer first_init;
    first_init.initialize();
    first_init.render();

    return 0;
}

