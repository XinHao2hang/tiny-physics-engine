#pragma once
#include "Object.h"
#include "Force.h"
#include<list>
using namespace std;
class Obj_Forces
{
public:
	Object* obj;
	std::list<Force*>forces;
	Obj_Forces() {}
	Obj_Forces(Object* _obj) :obj(_obj) {}
	//添加力
	void addForce(Force* _force)
	{
		forces.push_back(_force);
	}
	void update(float time)
	{
		//力和速度更新计算
		list<Force*>::iterator itor;
		itor = forces.begin();
		while (itor != forces.end())
		{
			
			(*itor)->operator>>(obj);
			
			if (!(*itor)->keep())
			{
				Force * tForce = *itor;
				forces.erase(itor++);
				delete tForce;
				continue;
			}
			++itor;
		}
		obj->update(time);
	}
};

