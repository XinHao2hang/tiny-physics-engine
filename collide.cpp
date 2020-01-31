#include "collide.h"



collide::collide()
{
}

CollideInfo collide::collideCalc(Object * a,Object * b)
{
	if ((a->type == LINE && b->type == CIRCLE)||(a->type==CIRCLE && b->type==LINE))
	{
		if (a->type == CIRCLE && b->type == LINE)
			std::swap(a, b);
		return LineAndCircle(a,b);
	}
}

CollideInfo collide::LineAndCircle(Object * line,Object * circle)
{
	Line* linePtr = dynamic_cast<Line*>(line);
	Circle * circlePtr = dynamic_cast<Circle*>(circle);
	vec3 A = linePtr->A + linePtr->position;
	vec3 B = linePtr->B + linePtr->position;
	vec3 O = circlePtr->position;
	//C点是圆心到直线的投影
	vec3 AB = B - A;
	vec3 C = A + AB * (dot(AB, (O - A)) / dot(AB, AB));
	//判断投影点是否在点段内
	float distance = length(C - O);
	//如果投影点在线段内
	if (abs(dot(normalize(C - A), normalize(C - B))+1)<0.0001)
	{
		//若在的时候，判断两点距离是不是小于半径
		
		if (distance < circlePtr->radius)
		{
			while (1);
			return CollideInfo(line,circle,abs(circlePtr->radius - distance),normalize(C-O));
		}
		return CollideInfo(nullptr, nullptr, 0, vec3(0, 0, 0));
	}
	else
	{
		float disOA = length(O -A);
		float disOB = length(O -B);
		if (disOA < circlePtr->radius)
		{
			while (1);
			return CollideInfo(line, circle, abs(circlePtr->radius - disOA), normalize(O - A));
		}
		if (disOB < circlePtr->radius)
		{
			while (1);
			return CollideInfo(line, circle, abs(circlePtr->radius - disOB), normalize(O - B));
		}
	}
	return CollideInfo(nullptr, nullptr, 0, vec3(0,0,0));
}

collide::~collide()
{
}
