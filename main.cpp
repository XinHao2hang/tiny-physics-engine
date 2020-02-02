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
	Circle c(20,vec3(400,300,0),40);//ԲȦ
	Circle c1(10, vec3(200, 300, 0), 40);//ԲȦ
	Obj_Forces CG(&c);//�������
	Obj_Forces CG1(&c1);//�������
	//CG.addForce(&G);
	CG.addForce(new Elastic(vec3(-1,0,0),COLLIDEFORCE));
	//CG1.addForce(new Elastic(vec3(1, 0, 0), COLLIDEFORCE));
	world w;
	//����һ��ʵ��ԲȦ
	DrawCircle dc;
	ICircle icircle(CG,dc);
	ICircle icircle1(CG1, dc);
	//����һ��ʵ��ֱ��
	Line l(100000,vec3(50,0,0),vec3(400,0,0),vec3(0,400,0));
	DrawLine dl;
	Obj_Forces LG(&l);
	ILine iline(LG,dl);

	Line l2(100000, vec3(0, 50, 0), vec3(0, 400, 0), vec3(50, 0, 0));
	//DrawLine dl;
	Obj_Forces LG2(&l2);
	ILine iline1(LG2, dl);

	Line l3(20, vec3(0, 50, 0), vec3(0, 400, 0), vec3(400, 0, 0));
	//DrawLine dl;
	Obj_Forces LG3(&l3);
	ILine iline2(LG3, dl);

	w.put(icircle.c);
	w.put(icircle1.c);
	/*w.put(iline.c);
	w.put(iline1.c);
	w.put(iline2.c);*/
	while (1)
	{
		Mat window = Mat::zeros(Size(512, 512), CV_8UC3);
		w.run();
		icircle.update();
		icircle.draw(window);
		icircle1.update();
		icircle1.draw(window);
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