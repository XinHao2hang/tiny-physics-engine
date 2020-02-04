#include "Object.h"



Object::Object()
{
}

void Object::updateVelocity(float time)
{
	velocity += force * time;
}

void Object::updatePosition(float time)
{
	position += velocity * time;// +force * time * time * 0.05f;
}

void Object::update(float time)
{
	
	updatePosition(time);
	updateVelocity(time);
	//ÐÞ¸ÄÐý×ª¾ØÕó
	angular += angular_velocity;
	axis = EulerAngle::getMat(angular);
	
	force = vec3(0,0,0);
}

void Object::operator<<(const vec3& _force)
{
	force += _force;
}



Object::~Object()
{
}
