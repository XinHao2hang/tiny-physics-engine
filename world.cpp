#include "world.h"



world::world()
{
}

void world::run()
{
	for (int i=0;i<objects.size();i++)
		objects[i].update(0.5);
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i+1; j < objects.size(); j++)
		{
			collide::collideCalc(&objects[i],&objects[j]).generate();
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
