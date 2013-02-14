#include "Particle.h"

Particle::Particle(){
    setInitialCondition(0, 0);
}

void Particle::setInitialCondition(float px, float py){
    pos.set(px, py);
}

void Particle::draw(){
    ofSetColor(0, 255, 200);
    ofCircle(pos.x, pos.y, 3);
    
}