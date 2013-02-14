#include "ParticleDraw.h"

void ParticleDraw::draw(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}

void ParticleDraw::keyPressed(int key){
    if (key == 'd') {
        particles.clear();
    }
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

void ParticleDraw::mouseDragged(int x, int y){
    Particle myParticle;
    myParticle.setInitialCondition(x, y);
    particles.push_back(myParticle);
}