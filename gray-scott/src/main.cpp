//init rendering
//init simulation
//load config

//while(running){
//    process input
//    update simulation
//    render frame
//}

#include "simulation.h"

int main(){
    Simulation first_try(4, 4);
    first_try.view();
    first_try.update(2);
    first_try.view();

    return 0;
}

