#pragma once
#include "Object.h"
class Circle : public Object
{
public:
	float radius = 0;//Բ�ΰ뾶
	Circle();
	Circle(vec3 _center, float _radius)
	{
		position = _center;
		radius = _radius;
	}
	~Circle();
};

