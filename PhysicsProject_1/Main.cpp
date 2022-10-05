#include <iostream>
#include <cmath>
#include <gdp/Engine.h>

#include "Graphics.h"
#include "Tank.h"
#include "ParticleAccelerator.h"

Graphics G;
const char* Title = "Physics Project";
const int Width = 1366;
const int Height = 768;

void Update() {
    G.Update();
}

//Main entry point
int main(int argc, char* argv) {

    gdp::GDP_Initialize();
    gdp::GDP_CreateWindow(Title, Width, Height);
    
    gdp::GDP_UpdateCallback(&Update);
    
    G.Initialize();
    gdp::GDP_Run();

    G.Destroy();
    gdp::GDP_Destroy();

    return 0;
}