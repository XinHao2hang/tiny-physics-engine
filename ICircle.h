#pragma once
#include "IObject.h"
class ICircle : public IObject
{
public:
	ICircle();
	Obj_Forces c;
	DrawCircle dc;
	ICircle(Obj_Forces _c,DrawCircle _dc):c(_c),dc(_dc) {}
	void draw(Mat & m) { dc.draw(m); }
	void update() { dc.update(c.obj); }
	~ICircle();
};

