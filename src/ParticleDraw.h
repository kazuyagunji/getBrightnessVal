#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleDraw {
public:
    vector <Particle> particles;
    void draw();
    void keyPressed(int key);    
    void mouseDragged(int x, int y);
    
};