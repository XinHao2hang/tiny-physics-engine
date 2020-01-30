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
	position += velocity * time + force * time * time;
}

void Object::update(float time)
{
	updatePosition(time);
	updateVelocity(time);
}

void Object::operator<<(const vec3& _force)
{
	force += _force;
}

Object::~Object()
{
}
