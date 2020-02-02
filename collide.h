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
	CollideInfo(Obj_Forces*_A, Obj_Forces*_B,float _deep,vec3 _cPoint):A(_A),B(_B),deep(_deep), cPoint(_cPoint) {}
	Obj_Forces* A;
	Obj_Forces* B;
	float deep;//相交最短距离
	vec3 cPoint;//碰撞点
	//生成力
	void generate()
	{
		//没有碰撞就不计算
		if (A == nullptr || B == nullptr)
			return;
		//以下生成的都是碰撞产生的力
		//两个物体都存在说明产生碰撞力
		if (A != nullptr && B != nullptr)
		{
			
			vec3 vecA = normalize(A->obj->position - cPoint);
			vec3 vecB = normalize(B->obj->position - cPoint);
			//碰撞点在两个型心连线上
			if (dot(vecA, vecB) < 0.0001)
			{
				float speedA = length(A->obj->velocity);
				float speedB = length(B->obj->velocity);
				float cosa = dot(vecA, normalize(A->obj->velocity));
				float cosb = dot(vecB, normalize(B->obj->velocity));
				if (speedA == 0)
					cosa = 1;
				if (speedB == 0)
					cosb = 1;
				//两个物体的速度分解,碰撞点到连心线上的分解
				

				vec3 rA = momentumCalc(A->obj->mass, B->obj->mass, speedA * cosa*vecA, speedB * cosb*vecB);
				vec3 rB = momentumCalc(B->obj->mass, A->obj->mass, speedB * cosb*vecB, speedA * cosa*vecA);

				vec3 AC = vecA * speedA * cosa;
				vec3 BC = vecB * speedB * cosb;

				vec3 AR = A->obj->velocity - AC;
				vec3 BR = B->obj->velocity - BC;

				AC = rA;
				BC = rB;

				A->obj->velocity = AC + AR;
				B->obj->velocity = BC + BR;
				
			}
			//受力计算
			vec3 force(0,0,0);
			for (auto fa : A->forces)
			{
				force += fa->getForce();
			}
			A->addForce(new Elastic(-force,COLLIDEFORCE));
			force = vec3(0, 0, 0);
			for (auto fb : B->forces)
			{
				force += fb->getForce();
			}
			B->addForce(new Elastic(-force, COLLIDEFORCE));
		}
	}
	vec3 momentumCalc(float mA, float mB, vec3 vA, vec3 vB)
	{
		return ((mA-mB)*vA+2.0f*mB*vB)/(mA+mB);
	}
	~CollideInfo() {}
};
class collide
{
public:
	collide();
	static CollideInfo LineAndCircle(Obj_Forces* line, Obj_Forces* circle);
	static CollideInfo CircleAndCircle(Obj_Forces* circle1, Obj_Forces* circle2);
	static CollideInfo collideCalc(Obj_Forces* a, Obj_Forces* b);
	~collide();
};

