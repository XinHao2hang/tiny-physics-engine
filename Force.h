#pragma once
#include"Object.h"
class Force
{
public:
	Force();
	~Force();
	int type = 0;
	virtual void operator>>(Object* obj) = 0;
	bool keep()
	{
		return type == 1;
	}
};

