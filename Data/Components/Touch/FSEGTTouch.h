#ifndef FSEGTTOUCH_H_
#define FSEGTTOUCH_H_

#include <FlameSteelCore/Object.h>
#include <memory>

using namespace std;
using namespace FlameSteelCore;

class FSEGTTouch: public Object {

public:

	FSEGTTouch(int x, int y);

	int x;
	int y;


};

#endif