#pragma once
#include "Object.h"
class Circle : public Object
{
public:
	float radius = 0;//Բ�ΰ뾶
	Circle();
	Circle(float _mass,vec3 _center, float _radius)
	{
		position = _center;
		radius = _radius;
		type = CIRCLE;
		mass = _mass;
	}
	~Circle();
};

