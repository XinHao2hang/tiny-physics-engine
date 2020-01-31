#pragma once
#include "Obj_Forces.h"
#include "DrawCircle.h"
class IObject
{
public:
	IObject();
	virtual void draw(Mat& m) {  }
	virtual void update() {  }
	~IObject();
};

