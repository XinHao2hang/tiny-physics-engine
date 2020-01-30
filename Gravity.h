#pragma once
#include "Force.h"
class Gravity : public Force
{
public:
	vec3 g;
	Gravity();
	Gravity(vec3 _g):g(_g){}
	virtual void operator>>(Object * obj);
	~Gravity();
};
