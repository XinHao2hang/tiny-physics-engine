#include "DrawCircle.h"



DrawCircle::DrawCircle()
{
}

void DrawCircle::draw(Mat & m)
{
	circle(m, Point(postition.x, postition.y), 40, Scalar(255, 0, 0), 1, 8);
	line(m, Point(pointEdge.x, pointEdge.y), Point(postition.x, postition.y), Scalar(255, 0, 0), 1);
}

void DrawCircle::update(Object* obj)
{
	postition = obj->position + ((Circle*)obj)->center;
	pointEdge = ((Circle*)obj)->pointEdge * obj->axis + obj->position;
}

DrawCircle::~DrawCircle()
{
}
