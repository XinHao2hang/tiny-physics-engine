#pragma once
#include "IObject.h"
#include "DrawLine.h"
class ILine : public IObject
{
public:
	Obj_Forces c;
	DrawLine lc;
	ILine();
	ILine(Obj_Forces _c, DrawLine _lc) :c(_c),lc(_lc){}
	void draw(Mat& m) { lc.draw(m); }
	void update() { lc.update(c.obj); }
	~ILine();
};

