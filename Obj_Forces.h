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
		for (auto force : forces)
		{
			force->operator>>(obj);
			/*if (!force->keep())
				forces.remove(force);*/
		}
		obj->update(time);
		//for (auto force : forces)
		//{
		//	//force->operator>>(obj);
		//	if (!force->keep())
		//		forces.remove(force);
		//}
	}
};

