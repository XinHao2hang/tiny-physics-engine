#pragma once
#include <glm.hpp>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Object.h"
using namespace cv;
using namespace glm;
class DrawObject
{

public:
	vec3 postition;
	DrawObject();
	DrawObject(vec3 pos) :postition(pos) {}
	virtual void draw(Mat& m) {};
	virtual void update(Object* obj) {}
	~DrawObject();
};

