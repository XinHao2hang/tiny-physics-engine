#include "Elastic.h"



Elastic::Elastic()
{
}

void Elastic::operator>>(Object* obj)
{
	obj->operator<<(f);
}

Elastic::~Elastic()
{
}
