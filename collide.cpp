#include "collide.h"



collide::collide()
{
}

CollideInfo collide::collideCalc(Obj_Forces* a, Obj_Forces* b)
{
	if ((a->obj->type == LINE && b->obj->type == CIRCLE)||(a->obj->type==CIRCLE && b->obj->type==LINE))
	{
		if (a->obj->type == CIRCLE && b->obj->type == LINE)
			std::swap(a, b);
		return LineAndCircle(a,b);
	}
	if (a->obj->type == CIRCLE && b->obj->type == CIRCLE)
	{
		return CircleAndCircle(a, b);
	}
	return CollideInfo(nullptr, nullptr, 0, vec3(0, 0, 0));
}

CollideInfo collide::LineAndCircle(Obj_Forces* line, Obj_Forces* circle)
{
	Line* linePtr = dynamic_cast<Line*>(line->obj);
	Circle * circlePtr = dynamic_cast<Circle*>(circle->obj);
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
		if (distance <= circlePtr->radius)
			return CollideInfo(line,circle,abs(circlePtr->radius - distance),C);
		return CollideInfo(nullptr, nullptr, 0, vec3(0, 0, 0));
	}
	else
	{
		float disOA = length(O -A);
		float disOB = length(O -B);
		if (disOA <= circlePtr->radius)
			return CollideInfo(line, circle, abs(circlePtr->radius - disOA), A);
		if (disOB <= circlePtr->radius)
			return CollideInfo(line, circle, abs(circlePtr->radius - disOB), B);
		return CollideInfo(nullptr, nullptr, 0, vec3(0, 0, 0));
	}
	return CollideInfo(nullptr, nullptr, 0, vec3(0,0,0));
}

CollideInfo collide::CircleAndCircle(Obj_Forces* circle1, Obj_Forces* circle2)
{
	Circle* circlePtr1 = dynamic_cast<Circle*>(circle1->obj);
	Circle* circlePtr2 = dynamic_cast<Circle*>(circle2->obj);
	//圆圈相交
	float deep = length(circlePtr1->getPos() - circlePtr2->getPos()) - (circlePtr1->radius + circlePtr2->radius);
	if (deep<=0)
	{
		return CollideInfo(circle1, circle2,-deep, (circlePtr1->getPos() + circlePtr2->getPos())/2.0f);
	}
	return CollideInfo(nullptr, nullptr, 0, vec3(0, 0, 0));
}

collide::~collide()
{
}
