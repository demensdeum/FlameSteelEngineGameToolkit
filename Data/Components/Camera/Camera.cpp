/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.cpp
 * Author: demensdeum
 * 
 * Created on February 19, 2017, 12:32 PM
 */

#include "Camera.h"
#include <math.h>

using namespace FlameSteelEngine::GameToolkit;

Camera::Camera() {
    
    position = make_shared<FSEGTVector>();
    direction = make_shared<FSEGTVector>();
    plane = make_shared<FSEGTVector>();
}

void Camera::rotate(float diff) {
    
    direction->rotate(diff);
    plane->rotate(diff);
}

void Camera::setPosition(float x, float y) {
    
    position->x = x;
    position->y = y;
    
}

void Camera::setRotation(float angle) {
    
    // euler
    
    angle += 180; // invert
    
    reset();
    //rotate(DEGREES_TO_RADIANS(angle));
}

void Camera::reset() {
    
        direction->x = -1;
        direction->y = 0;
        
        plane->x = 0;
        plane->y = 0.66;    
}

Camera::Camera(const Camera& ) {
}

Camera::~Camera() {
}
