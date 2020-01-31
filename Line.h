#pragma once
#include "Object.h"
class Line :public Object
{
public:
	vec3 A, B;
	Line();
	Line(float _mass, vec3 _A, vec3 _B, vec3 _P) :A(_A), B(_B) { position = _P; type = LINE; mass = _mass; }
	~Line();
};

