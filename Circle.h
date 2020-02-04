#pragma once
#include "Object.h"
class Circle : public Object
{
public:
	float radius = 0;//Բ�ΰ뾶
	vec3 pointEdge;
	vec3 center;
	vec3 getPos() { return center + position; }
	Circle();
	Circle(float _mass,vec3 _center,vec3 _position, float _radius)
	{
		center = _center;
		radius = _radius;
		type = CIRCLE;
		mass = _mass;
		position = _position + center;
		pointEdge = vec3(1, 0, 0) * radius + center;
	}
	~Circle();
};

