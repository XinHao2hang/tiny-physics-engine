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
	Gravity G(vec3(0,0.1,0), CONTINUEFORCE);//����
	
	//Gravity G1(vec3(0, 0.0, 0));//����
	Circle c(10,vec3(0,0,0),vec3(400,300,0),40);//ԲȦ
	
	Circle c1(10, vec3(0,0,0),vec3(200, 270, 0), 40);//ԲȦ
	Circle c2(10, vec3(0, 0, 0), vec3(100, 300, 0), 40);//ԲȦ
	//c1.angular_velocity = vec3(0, 0, 1);
	Obj_Forces CG(&c);//�������
	Obj_Forces CG1(&c1);//�������
	Obj_Forces CG2(&c2);//�������
	//CG.addForce(&G);
	CG.addForce(new Elastic(vec3(-1,0,0),COLLIDEFORCE));
	//CG1.addForce(new Elastic(vec3(1, 0, 0), COLLIDEFORCE));
	world w;
	//����һ��ʵ��ԲȦ
	DrawCircle dc;
	ICircle icircle(CG,dc);
	ICircle icircle1(CG1, dc);
	ICircle icircle2(CG2, dc);
	//����һ��ʵ��ֱ��
	
	w.put(icircle.c);
	w.put(icircle1.c);
	w.put(icircle2.c);
	while (1)
	{
		Mat window = Mat::zeros(Size(512, 512), CV_8UC3);
		w.run();
		icircle.update();
		icircle.draw(window);
		icircle1.update();
		icircle1.draw(window);
		icircle2.update();
		icircle2.draw(window);
		/*iline.update();
		iline.draw(window);
		iline1.update();
		iline1.draw(window);
		iline2.update();
		iline2.draw(window);*/
		imshow("win", window);
		waitKey(1);
	}
	return 0;
}