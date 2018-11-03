#include "FSEGTTouch.h"

FSEGTTouch::FSEGTTouch(int x, int y) {

	this->x = x;
	this->y = y;

	this->setClassIdentifier(make_shared<string>(uuid));
	this->setInstanceIdentifier(make_shared<string>(uuid));

};