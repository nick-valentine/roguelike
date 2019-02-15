#ifndef CAMERA_H
#define CAMERA_H

#include "window/abstract.h"
#include "objects/level.h"
#include "utility/point.h"

class Camera
{
public:
	Camera(iPoint pos);
	void move(iPoint delta);
	void moveTo(iPoint to);

	iPoint pos() const;

	void render(window::ptr &win, std::unique_ptr<objects::Level> &l);
private:
	iPoint mPos;
};

#endif // CAMERA_H