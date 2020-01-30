#include <iostream>
#include <queue>
#include "world.h"
#include "Gravity.h"
#include "Circle.h"
#include "DrawCircle.h"

using namespace std;

int main()
{
	int a;
	cin >> a;
	Gravity G(vec3(0,0.1,0));
	Circle c(vec3(100,100,0),40);
	Obj_Force CG;
	CG.obj = &c;
	CG.addForce(&G);
	world w;
	w.put(CG);
	DrawCircle dc(vec3(100, 100, 0), 40);
	while (1)
	{
		Mat window = Mat::zeros(Size(512, 512), CV_8UC3);
		w.run();
		dc.draw(window);
		dc.update(CG.obj);
		imshow("win", window);
		waitKey(1);
	}
	return 0;
}