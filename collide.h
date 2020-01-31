#pragma once
#include "Line.h"
#include "Circle.h"
#include<algorithm>
//��ײ��Ϣ
class CollideInfo
{
public:
	CollideInfo() {}
	CollideInfo(Object*_A, Object*_B,float _deep,vec3 d):A(_A),B(_B),deep(_deep),direction(d) {}
	Object* A;
	Object* B;
	float deep;//�ཻ��̾���
	vec3 direction;//�ཻ����
	~CollideInfo() {}
};
class collide
{
public:
	collide();
	static CollideInfo LineAndCircle(Object* line, Object* circle);
	static CollideInfo collideCalc(Object * a,Object * b);
	~collide();
};

