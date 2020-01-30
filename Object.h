#pragma once
#include<glm.hpp>

using namespace glm;
class Object
{
public:
	//��������
	int type = 0;
	//�ٶ�
	vec3 velocity = vec3(0,0,0);
	//��
	vec3 force = vec3(0, 0, 0);;
	//��������
	vec3 position = vec3(0, 0, 0);
	//�任����
	mat3 axis;
	//����
	float mass;
	virtual void operator<<(const vec3 & _force);
	//�ٶȼ���
	void updateVelocity(float time);
	//λ�ü���
	void updatePosition(float time);
	//����
	void update(float time);
	Object();
	~Object();
};

