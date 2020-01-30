#pragma once
#include "DrawObject.h"
class DrawCircle : public DrawObject
{
public:
	float radius = 0;
	DrawCircle();
	DrawCircle(vec3 pos, float r) :DrawObject(pos), radius(r) {}
	virtual void draw(Mat& m);
	virtual void update(Object* obj);
	~DrawCircle();
};

