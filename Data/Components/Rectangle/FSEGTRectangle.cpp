#include "FSEGTRectangle.h"

#include <FlameSteelEngineGameToolkit/Data/Components/Integer/FSEGTIntegerComponent.h>
#include <FlameSteelEngineGameToolkit/Data/Components/Rectangle/FSEGTRectangle.h>

using namespace FlameSteelCore;

FSEGTRectangle::FSEGTRectangle(int x, int y, int width, int height) {

	auto componentX = make_shared<FSEGTIntegerComponent>(x);
	componentX->setClassIdentifier(make_shared<string>("x"));
	componentX->setInstanceIdentifier(make_shared<string>("x"));

	auto componentY = make_shared<FSEGTIntegerComponent>(y);
	componentY->setClassIdentifier(make_shared<string>("y"));
	componentY->setInstanceIdentifier(make_shared<string>("y"));

	auto componentWidth = make_shared<FSEGTIntegerComponent>(width);
	componentWidth->setClassIdentifier(make_shared<string>("width"));
	componentWidth->setInstanceIdentifier(make_shared<string>("width"));

	auto componentHeight = make_shared<FSEGTIntegerComponent>(height);
	componentWidth->setClassIdentifier(make_shared<string>("height"));
	componentWidth->setInstanceIdentifier(make_shared<string>("height"));

	this->addComponent(componentX);
	this->addComponent(componentY);
	this->addComponent(componentWidth);
	this->addComponent(componentHeight);

}

int FSEGTRectangle::x() {
	auto componentX = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("x")));
	return componentX->value;
}

int FSEGTRectangle::y() {
	auto componentX = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("y")));
	return componentX->value;
}

int FSEGTRectangle::width() {
	auto componentX = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("width")));
	return componentX->value;
}

int FSEGTRectangle::height() {
	auto componentX = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("height")));
	return componentX->value;
}

void FSEGTRectangle::setX(int x) {
	auto componentX = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("x")));
	componentX->value = x;
}

void FSEGTRectangle::setY(int y) {
	auto componentY = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("x")));
	componentY->value = y;
}

void FSEGTRectangle::setWidth(int width) {
	auto componentWidth = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("width")));
	componentWidth->value = width;
}

void FSEGTRectangle::setHeight(int height) {
	auto componentHeight = static_pointer_cast<FSEGTIntegerComponent>(getComponent(make_shared<string>("height")));
	componentHeight->value = height;
}

bool FSEGTRectangle::isPointXYInside(int x, int y) {

	if (x >= this->x() && x <= this->x() + this->width()) {
		if (y >= this->y() && y <= this->y() + this->height()) {
			return true;
		}
	}

	return false;
}