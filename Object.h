#pragma once
#include<glm.hpp>
enum OBJTYPE
{
	NOTHING,CIRCLE,LINE
};
using namespace glm;
class Object
{
public:
	//物体类型
	OBJTYPE type = NOTHING;
	//速度
	vec3 velocity = vec3(0,0,0);
	//力
	vec3 force = vec3(0, 0, 0);;
	//世界坐标
	vec3 position = vec3(0, 0, 0);
	//变换矩阵
	mat3 axis;
	//质量
	float mass;
	virtual void operator<<(const vec3 & _force);
	//速度计算
	void updateVelocity(float time);
	//位置计算
	void updatePosition(float time);
	//更新
	void update(float time);
	Object();
	~Object();
};

