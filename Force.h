#pragma once
#include"Object.h"
enum ForceType
{
	CONTINUEFORCE,COLLIDEFORCE
};
class Force
{
public:
	Force();
	virtual ~Force();
	int type = -1;
	virtual void operator>>(Object* obj) = 0;
	bool keep()
	{
		return type == CONTINUEFORCE;
	}
	virtual vec3 getForce() { return vec3(0, 0, 0); }
};

