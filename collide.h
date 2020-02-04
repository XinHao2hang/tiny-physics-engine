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
			
			vec3 vecA = normalize(A->obj->getPos() - cPoint);
			vec3 vecB = normalize(B->obj->getPos() - cPoint);
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

				A->obj->velocity = (AC + AR);
				B->obj->velocity = (BC + BR);
				
				//先将物体原有旋转动量转换
				float Ra = length(A->obj->getPos() - cPoint);
				float Rb = length(B->obj->getPos() - cPoint);

				vec3 roA = cross(A->obj->angular_velocity, vecA)*0.5f;//这里是损失的角动量
				vec3 roB = cross(B->obj->angular_velocity, vecB)*0.5f;

				//计算动量后并且将角速度转换成线速度
				vec3 troA = momentumCalc(A->obj->mass, B->obj->mass, roA, roB)*A->obj->mass*Ra;
				vec3 troB = momentumCalc(B->obj->mass, A->obj->mass, roB, roA)*B->obj->mass*Rb;

				//将运动速度转换成动量，这里暂不明，就是效果好， 我推算一个公式看看的
				rA = AR*A->obj->mass* A->obj->mass;
				rB = BR*B->obj->mass* B->obj->mass;
				
				vec3 all = rA - rB;

				//计算A和B角动量
				vec3 dA = (all+troA-troB);
				vec3 dB = (-all+troB-troA);
				
				A->obj->angular_velocity += -cross(dA, vecA * length(A->obj->getPos() - cPoint))/(A->obj->mass*Ra*Ra);
				B->obj->angular_velocity += -cross(dB, vecB * length(B->obj->getPos() - cPoint))/(B->obj->mass*Rb*Rb);
				 
				//A->addForce(new Elastic(-dA/A->obj->mass/10.0f, COLLIDEFORCE));
			}
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

