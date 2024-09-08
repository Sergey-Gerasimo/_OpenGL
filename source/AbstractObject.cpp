#include "../includes/AbstractObject.h"



void OGLTypes::AbstractObject::move2(OGLTypes::Vector3d position){
    this->position += position;
}

void OGLTypes::AbstractObject::place(PointFloat3d position){
    this->position = position; 
}

void OGLTypes::AbstractObject::rotate(float angle, float x, float y, float z){

    this->xAngle += angle*x; 
    this->yAngle += angle*y; 
    this->zAngle += angle*z; 
}

void OGLTypes::AbstractObject::scale(float scalecoef){
    this->scalecoef = scalecoef;
}

void OGLTypes::AbstractObject::setAngleX(float angle){
    this->xAngle = angle;
}
void OGLTypes::AbstractObject::setAngleY(float angle){
    this->yAngle = angle; 
}
void OGLTypes::AbstractObject::setAngleZ(float angle){
    this->zAngle = angle;
}
float OGLTypes::AbstractObject::getAngleX()
{
    return this->xAngle;
}

float OGLTypes::AbstractObject::getAngleY()
{
    return this->yAngle;
}
float OGLTypes::AbstractObject::getAngleZ()
{
    return this->zAngle;
}
OGLTypes::PointFloat3d OGLTypes::AbstractObject::getPosition()
{
    return this->position;
}