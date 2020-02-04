#pragma once
#include<glm.hpp>
#include"EulerAngle.h"
enum OBJTYPE
{
	NOTHING,CIRCLE,LINE
};
using namespace glm;
class Object
{
public:
	//��������
	OBJTYPE type = NOTHING;
	//�ٶ�
	vec3 velocity = vec3(0,0,0);
	//��
	vec3 force = vec3(0, 0, 0);;
	//��������
	vec3 position = vec3(0, 0, 0);
	//��ת�ٶ�
	vec3 angular_velocity = vec3(0,0,0);
	//��ת�Ƕ�
	vec3 angular = vec3(0, 0, 0);
	//�任����
	mat3 axis = mat3(vec3(1,0,0),vec3(0,1,0),vec3(0,0,1));
	//����
	float mass;
	virtual void operator<<(const vec3 & _force);
	//�ٶȼ���
	void updateVelocity(float time);
	//λ�ü���
	void updatePosition(float time);
	//����
	void update(float time);
	//��ȡλ��
	virtual vec3 getPos() { return position; };
	Object();
	~Object();
};

