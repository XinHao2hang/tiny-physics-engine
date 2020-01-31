#pragma once
#include<vector>
#include<list>
#include"Object.h"
#include"Force.h"
#include "collide.h"
#include "Obj_Forces.h"
using namespace std;

class world
{
	vector<Obj_Forces>objects;
public:
	world();
	void run();
	void put(Obj_Forces obj);

	~world();
};

