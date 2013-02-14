#pragma once
#include "ofMain.h"

class Particle {
public:
    ofVec2f pos;
    
    Particle();
    virtual ~Particle(){};
    void setInitialCondition(float px, float py);
    void draw();
    
protected:
private:
};