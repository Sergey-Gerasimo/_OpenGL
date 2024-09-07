#include "../includes/Object.h"
#include <OpenGL/gl.h> 

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


    //glTranslatef(position.getValue().getX(), position.getValue().getY(), position.getValue().getZ());
    if (this->position.isChanged()){
        glTranslatef(position.getValue().getX(), position.getValue().getY(), position.getValue().getZ());
        position.disableState();
    }

    if (this->yAngle.isChanged()){
        glRotatef(yAngle.getValue(), 0, 1, 0);
        yAngle.disableState();
    }

    if (zAngle.isChanged()){
        glRotatef(zAngle.getValue(), 0, 0, 1);
        zAngle.disableState();
    }

    if (xAngle.isChanged() == 1){
        glRotatef(xAngle.getValue(), 1, 0, 0);
        xAngle.disableState();
    }

    if (scalecoef.isChanged()){
        glScalef(scalecoef.getValue(), scalecoef.getValue(), scalecoef.getValue());
        position.disableState();
    }
    
    glDrawArrays(GL_TRIANGLE_FAN, 0, this->size);
    
    glPopMatrix();

}