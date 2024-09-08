#ifndef __ABSTRACT_OBJECT_H__
#define __ABSTRACT_OBJECT_H__
#include "Points.h"


namespace OGLTypes
{

class AbstractObject
{
    public:  
        void place(PointFloat3d position); 
        void move2(Vector3d vect); 
        void rotate(float angle, float x, float y, float z); 
        virtual void draw() = 0; 
        void scale(float scalecoef);
        void setAngleX(float angle); 
        void setAngleY(float angle);
        void setAngleZ(float angle);
        float getAngleX();
        float getAngleY();
        float getAngleZ();
        PointFloat3d getPosition(); 


    protected:
        PointFloat3d position = {0.0f, 0.0f, 0.0f}; 
        float xAngle = 0.0f; 
        float yAngle = 0.0f; 
        float zAngle = 0.0f; 
        float scalecoef = 1.0f;
};

}

#endif