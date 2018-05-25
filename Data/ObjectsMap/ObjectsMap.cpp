#include "ObjectsMap.h"

#include <FlameSteelCore/FSCObject.h>

using namespace FlameSteelEngine::GameToolkit;

ObjectsMap::ObjectsMap(int width, int height) {

}

int ObjectsMap::tileIndexAtXY(int x, int y) {
	return x+y*width;
}

void ObjectsMap::addOrUpdateObject(shared_ptr<FSCObject> object) {

	if (objectIndexToTileIndex[object->id] == ObjectsMapNoTileIndex)
	{

	}
	else
	{
		
	}

}

void ObjectsMap::removeObject(shared_ptr<FSCObject> object) {

}

void ObjectsMap::removeAllObjects() {

}

shared_ptr<FSCObject> ObjectsMap::objectAtXY(int x, int y) {

	auto tileIndex = tileIndexAtXY(x, y);

	return tileIndexToObject[tileIndex];
}
