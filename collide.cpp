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
	//C����Բ�ĵ�ֱ�ߵ�ͶӰ
	vec3 AB = B - A;
	vec3 C = A + AB * (dot(AB, (O - A)) / dot(AB, AB));
	//�ж�ͶӰ���Ƿ��ڵ����
	float distance = length(C - O);
	//���ͶӰ�����߶���
	if (abs(dot(normalize(C - A), normalize(C - B))+1)<0.0001)
	{
		//���ڵ�ʱ���ж���������ǲ���С�ڰ뾶
		
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
