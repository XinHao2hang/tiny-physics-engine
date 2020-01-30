#include "DrawCircle.h"



DrawCircle::DrawCircle()
{
}

void DrawCircle::draw(Mat & m)
{
	circle(m, Point(postition.x, postition.y), 40, Scalar(255, 0, 0), 1, 8);
}

void DrawCircle::update(Object* obj)
{
	postition = obj->position;
}

DrawCircle::~DrawCircle()
{
}
