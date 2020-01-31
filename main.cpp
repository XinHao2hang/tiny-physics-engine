#include <iostream>
#include <queue>
#include "world.h"
#include "Gravity.h"
#include "Circle.h"
#include "DrawCircle.h"
#include "ICircle.h"
#include "ILine.h"
using namespace std;

int main()
{
	Gravity G(vec3(0,0.1,0));//重力
	//Gravity G1(vec3(0, 0.0, 0));//重力
	Circle c(vec3(20,100,0),40);//圆圈
	Obj_Forces CG(&c);//力结合体
	CG.addForce(&G);
	world w;
	//创建一个实例圆圈
	DrawCircle dc;
	ICircle icircle(CG,dc);

	//创建一个实例直线
	Line l(vec3(50,0,0),vec3(400,0,0),vec3(0,400,0));
	DrawLine dl;
	Obj_Forces LG(&l);
	ILine iline(LG,dl);

	w.put(icircle.c);
	w.put(iline.c);
	while (1)
	{
		Mat window = Mat::zeros(Size(512, 512), CV_8UC3);
		w.run();
		icircle.update();
		icircle.draw(window);
		iline.update();
		iline.draw(window);
		imshow("win", window);
		waitKey(1);
	}
	return 0;
}