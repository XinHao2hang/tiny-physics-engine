#include "Gravity.h"



Gravity::Gravity()
{
}

void Gravity::operator>>(Object * obj)
{
	obj->operator<<(g);
}

Gravity::~Gravity()
{
}
