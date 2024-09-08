#include "../includes/Object.h"
#include <OpenGL/gl.h>


OGLTypes::Object::Object(PointFloat3d points[], unsigned int size, float colors[])
{
    this->colors = colors; 
    this->points = points;
    this->size = size; 

    
}

OGLTypes::Object::Object(std::string filename){

}

void OGLTypes::Object::draw(){
    glPushMatrix();
    glEnableClientState(GL_VERTEX_ARRAY);
    if (this->colors != nullptr){
         glEnableClientState(GL_COLOR_ARRAY);
         glColorPointer(3, GL_FLOAT, 0, this->colors);
    }
    glVertexPointer(3, GL_FLOAT, 0, this->points);

    glTranslatef(this->position.getX(), position.getY(), position.getZ());
    glRotatef(yAngle, 0, 1, 0);
    glRotatef(zAngle, 0, 0, 1);
    glRotatef(xAngle, 1, 0, 0);
    glScalef(scalecoef, scalecoef, scalecoef);
    
    glDrawArrays(GL_TRIANGLE_FAN, 0, this->size);
    glDisableClientState(GL_VERTEX_ARRAY);

    if (this->colors != nullptr)
        glDisableClientState(GL_COLOR_ARRAY);

    glPopMatrix();
}