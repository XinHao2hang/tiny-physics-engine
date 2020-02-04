#pragma once
#include "DrawObject.h"
#include "Circle.h"
class DrawCircle : public DrawObject
{
public:
	float radius = 0;
	vec3 pointEdge;
	DrawCircle();
	DrawCircle(vec3 pos, float r) :DrawObject(pos), radius(r) {}
	virtual void draw(Mat& m);
	virtual void update(Object* obj);
	~DrawCircle();
};

