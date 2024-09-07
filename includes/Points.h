#ifndef __POINTS_H__
#define __POINTS_H__

namespace OGLTypes
{
class POINTFLOAT{
  public: 
    POINTFLOAT(){x  = 0; y = 0; z = 0;}; 
    POINTFLOAT(float x, float y, float z) {this->x = x; this->y=y; this->z=z;};

    void operator+=(POINTFLOAT value){
          this->x += value.x; 
          this->y += value.y;
          this->z += value.z;
      }

    void operator-=(POINTFLOAT value){
          this->x -= value.x; 
          this->y -= value.y;
          this->z -= value.z;
      }

    float getX(){ return this->x;};
    float getY(){ return this->y;};
    float getZ(){ return this->z;};

    private: 
      float x = 0; 
      float y = 0; 
      float z = 0; 

};
};
#endif 