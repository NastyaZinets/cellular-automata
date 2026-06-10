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
    int green = 255;
    int red = 0;

    Renderer first_init;
    if (first_init.initialize()){
        while(first_init.isRunning()){
            first_init.processEvents();
            first_init.render(red, green, 0);
            green -= 10;
            red += 10;
        }
    }

    first_init.shutdown();

    return 0;
}

