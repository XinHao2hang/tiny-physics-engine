#include "EulerAngle.h"



EulerAngle::EulerAngle()
{
}

mat3 EulerAngle::operator()(vec3 angle)
{
	vec3 radian(angle.x*3.141592654/180, angle.y * 3.141592654 / 180, angle.z * 3.141592654 / 180);
	
	return mat3(vec3(1, 0, 0), vec3(0, cos(radian.x), -sin(radian.x)), vec3(0, sin(radian.x), cos(radian.x))) *
		mat3(vec3(cos(radian.y), 0, sin(radian.y)), vec3(0, 1, 0), vec3(-sin(radian.y), 0, cos(radian.y))) *
		mat3(vec3(cos(radian.z), -sin(radian.z), 0), vec3(sin(radian.z), cos(radian.z), 0), vec3(0, 0, 1));
}

mat3 EulerAngle::getMat(vec3 angle)
{
	vec3 radian(angle.x * 3.141592654 / 180, angle.y * 3.141592654 / 180, angle.z * 3.141592654 / 180);
	//radian = angle;
	return mat3(vec3(1, 0, 0), vec3(0, cos(radian.x), -sin(radian.x)), vec3(0, sin(radian.x), cos(radian.x))) *
		mat3(vec3(cos(radian.y), 0, sin(radian.y)), vec3(0, 1, 0), vec3(-sin(radian.y), 0, cos(radian.y))) *
		mat3(vec3(cos(radian.z), -sin(radian.z), 0), vec3(sin(radian.z), cos(radian.z), 0), vec3(0, 0, 1));
}

EulerAngle::~EulerAngle()
{
}
