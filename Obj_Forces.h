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
	//�����
	void addForce(Force* _force)
	{
		forces.push_back(_force);
	}
	void update(float time)
	{
		//�����ٶȸ��¼���
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

