#include "world.h"



world::world()
{
}

void world::run()
{
	for (int i=0;i<objects.size();i++)
		objects[i].update(0.01);
}

void world::put(Obj_Force obj)
{
	objects.push_back(obj);
}

world::~world()
{
}
