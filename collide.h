#pragma once
#include "Line.h"
#include "Circle.h"
#include "Obj_Forces.h"
#include "Elastic.h"
#include<algorithm>
//碰撞信息
class CollideInfo
{
public:
	CollideInfo() {}
	CollideInfo(Obj_Forces*_A, Obj_Forces*_B,float _deep,vec3 d):A(_A),B(_B),deep(_deep),direction(d) {}
	Obj_Forces* A;
	Obj_Forces* B;
	float deep;//相交最短距离
	vec3 direction;//相交方向
	//生成力
	void generate()
	{
		//没有碰撞就不计算
		if (A == nullptr || B == nullptr)
			return;
		//以下生成的都是碰撞产生的力
		//Elastic* elastic = ;
		if (A->obj->mass > 0)
		{
			A->addForce(new Elastic(vec3(0, -0.1, 0), 0));
			A->obj->velocity = -A->obj->velocity*0.99f;
			
		}
		if (B->obj->mass > 0)
		{
			B->addForce(new Elastic(vec3(0, -0.1, 0), 0));
			B->obj->velocity = -B->obj->velocity*0.99f;
			
		}
	}
	~CollideInfo() {}
};
class collide
{
public:
	collide();
	static CollideInfo LineAndCircle(Obj_Forces* line, Obj_Forces* circle);
	static CollideInfo collideCalc(Obj_Forces* a, Obj_Forces* b);
	~collide();
};

