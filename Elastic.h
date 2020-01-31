#pragma once
#include "Force.h"
class Elastic : public Force
{
public:
	vec3 f;
	Elastic();
	Elastic(vec3 _f, int t) :f(_f) { type = t; }
	void operator>>(Object* obj);
	~Elastic();
};

