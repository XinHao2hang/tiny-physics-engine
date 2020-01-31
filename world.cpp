#include "world.h"



world::world()
{
}

void world::run()
{
	for (int i=0;i<objects.size();i++)
		objects[i].update(0.01);
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i; j < objects.size(); j++)
		{
			collide::collideCalc(objects[i].obj,objects[j].obj);
		}
	}
}

void world::put(Obj_Forces obj)
{
	objects.push_back(obj);
}

world::~world()
{
}
