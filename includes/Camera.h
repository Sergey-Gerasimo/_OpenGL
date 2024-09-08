#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "AbstractObject.h"

namespace OGLTypes
{
class Camera: public AbstractObject
{
protected:
	Camera(int chanks=80);
	Camera(const Camera&);
    int chanks = 80;

public:
    void draw();
	static Camera& instance()
	{
		static Camera instance;
		return instance;
	}
};
}
#endif