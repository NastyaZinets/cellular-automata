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
    Simulation first_try(512, 512);
    //first_try.view();
    first_try.update(2);
    //first_try.view();
    
    Renderer first_init;
    if (first_init.initialize( first_try.getWidth(), first_try.getHeight())){
        while(first_init.isRunning()){
            first_init.processEvents();
            first_init.render(first_try.getU(), first_try.getV());
        }
    }

    first_init.shutdown();

    return 0;
}

