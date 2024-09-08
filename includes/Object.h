#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "Points.h"
#include <string> 
#include "AbstractObject.h"
#include "ObservableType.h"
#include <unordered_map>

namespace OGLTypes{

class Object: public AbstractObject
{
    public: 
        Object(std::string filename); 
        Object(PointFloat3d points[], unsigned int size, float colors[] = nullptr);
        void draw(); 
        
    protected: 
        bool colorState = 0; 
        unsigned int size = 0;
        float* colors; 
        PointFloat3d* points; 


};
};
#endif