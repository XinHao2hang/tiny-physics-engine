#pragma once
#include "Force.h"
class Gravity : public Force
{
public:
	vec3 g;
	Gravity();
	Gravity(vec3 _g, int t) :g(_g) { type = t; }
	virtual void operator>>(Object * obj);
	~Gravity();
};

