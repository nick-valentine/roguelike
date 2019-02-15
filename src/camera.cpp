#include "camera.h"

Camera::Camera(iPoint pos) : mPos(pos)
{
}

void Camera::move(iPoint delta)
{
	mPos.x += delta.x;
	mPos.y += delta.y;
}

void Camera::moveTo(iPoint to)
{
	mPos = to;
}

iPoint Camera::pos() const
{
	return mPos;
}

void Camera::render(window::ptr &win, std::unique_ptr<objects::Level> &l)
{
	auto size = win->size();
	l->draw(win, iPoint(mPos.x - size.x/2, mPos.y - size.y/2));
}