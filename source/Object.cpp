#include "../includes/Object.h"
#include <OpenGL/gl.h> 
#include <iostream>

OGLTypes::Object::Object(PointFloat3d points[], float colors[], unsigned int size)
{
    this->colors = colors; 
    this->points = points;
    this->size = size; 
    
}

OGLTypes::Object::Object(std::string filename){

}

void OGLTypes::Object::move2(OGLTypes::Vector3d position){
    this->position += position;
}

void OGLTypes::Object::place(PointFloat3d position){
    this->position = position; 
}

void OGLTypes::Object::rotate(float angle, float x, float y, float z){

    this->xAngle += angle*x; 
    this->yAngle += angle*y; 
    this->zAngle += angle*z; 
}

void OGLTypes::Object::scale(float scalecoef){
    this->scalecoef = scalecoef;
}

void OGLTypes::Object::draw(){
    glPushMatrix();
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, this->points);
    glColorPointer(3, GL_FLOAT, 0, this->colors);

    glTranslatef(position.getX(), position.getY(), position.getZ());
    glRotatef(yAngle, 0, 1, 0);
    glRotatef(zAngle, 0, 0, 1);
    glRotatef(xAngle, 1, 0, 0);
    glScalef(scalecoef, scalecoef, scalecoef);
    
    glDrawArrays(GL_TRIANGLE_FAN, 0, this->size);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glPopMatrix();
    
}