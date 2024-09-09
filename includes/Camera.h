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
	void rander() {void draw();};
    void draw();
	static Camera& instance(unsigned int chanks)
	{
		static Camera instance(chanks);
		return instance;
	}
};
}
#endif