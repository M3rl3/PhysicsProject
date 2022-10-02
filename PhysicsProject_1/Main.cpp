#include <iostream>
#include <cmath>
#include <gdp/Engine.h>

#include "Graphics.h"
#include "Tank.h"
#include "ParticleAccelerator.h"
#include "MultiParticleAccelerator.h"

Graphics G;
const char* Title = "Physics Project";
const int Width = 640;
const int Height = 480;

void Update() {
    G.Update();
}

//Main entry point
int main(int argc, char* argv) {

    srand(time(0));
    gdp::GDP_Initialize();
    gdp::GDP_CreateWindow(Title, Width, Height);
    
    gdp::GDP_UpdateCallback(&Update);
    
    G.Initialize();
    gdp::GDP_Run();

    G.Destroy();
    gdp::GDP_Destroy();
    
    //accelerateparticles();


    //doshit(98, 90);

    //particlefunctions();

    return 0;
}