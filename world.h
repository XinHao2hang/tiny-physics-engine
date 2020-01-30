#pragma once
#include<vector>
#include<list>
#include"Object.h"
#include"Force.h"
using namespace std;
class Obj_Force
{
public:
	Object * obj;
	std::list<Force*>forces;
	Obj_Force() {}
	Obj_Force(Object * _obj) :obj(_obj) {}
	//添加力
	void addForce(Force * _force)
	{
		forces.push_back(_force);
	}
	void update(float time)
	{
		//力和速度更新计算
		for(auto force : forces)
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
class world
{
	vector<Obj_Force>objects;
public:
	world();
	void run();
	void put(Obj_Force obj);

	~world();
};

