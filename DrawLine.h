#pragma once
#include "DrawObject.h"
#include "Line.h"
class DrawLine:public DrawObject
{
public:
	DrawLine();
	vec3 A, B;
	virtual void draw(Mat& m) { line(m, Point(A.x+postition.x,A.y+postition.y), Point(B.x+postition.x,B.y+postition.y), Scalar(255, 0, 0), 2); }
	virtual void update(Object* obj) 
	{
		A = ((Line*)(obj))->A;
		B = ((Line*)(obj))->B;
		postition = ((Line*)(obj))->position;
	}
	~DrawLine();
};

