#include "../includes/Camera.h"
#include <GLFW/glfw3.h>



void OGLTypes::Camera::draw()
{
        glRotatef(-this->xAngle, 1, 0, 0);
        glRotatef(-this->yAngle, 0, 1, 0);
        glRotatef(-this->zAngle, 0, 0, 1);
        glTranslatef(this->position.getX(), this->position.getY(), this->position.getZ());
}
OGLTypes::Camera::Camera(int chanks)

{
    this->position = PointFloat3d {0, -1, -5};
    this->chanks = chanks;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
    glFrustum(-1, 1, -1, 1, 2, this->chanks); // перспективная проекция 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(position.getX(), position.getY(), position.getZ());
    glEnable(GL_DEPTH_TEST);
}
