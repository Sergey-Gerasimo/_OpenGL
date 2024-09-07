#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "Points.h"
#include <string>
#include "ObservableType.h"

namespace OGLTypes{

typedef POINTFLOAT PointFloat3d, Vector3d;
typedef std::vector<float> FloatArray;
typedef std::vector<PointFloat3d> PointFloat3dArray;


class Object{
    public: 
        Object(std::string filename); 
        Object(PointFloat3d points[], float colors[], unsigned int size);
        void place(PointFloat3d position); 
        void move2(Vector3d vect); 
        void rotate(float angle, float x, float y, float z); 
        void draw(); 
        void scale(float scalecoef);

    private: 
        unsigned int size = 0;
        float* colors; 
        PointFloat3d* points; 

        PointFloat3d position{PointFloat3d(0.0f, 0.0f, 0.0f)}; 
        float xAngle = 0.0f; 
        float yAngle = 0.0f; 
        float zAngle = 0.0f; 
        float scalecoef = 1.0f; 

};
};
#endif