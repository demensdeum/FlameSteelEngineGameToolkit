#ifndef FSEGTRECTANGLE_H_
#define FSEGTRECTANGLE_H_

#include <FlameSteelCore/Object.h>

using namespace FlameSteelCore;

class FSEGTRectangle: public Object {

public:

	FSEGTRectangle(int x, int y, int width, int height);

	int x();
	int y();
	int width();
	int height();

	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);

	bool isPointXYInside(int x, int y);

};

#endif