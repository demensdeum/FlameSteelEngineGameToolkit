#include "ObjectsMap.h"

#include <FlameSteelCore/FSCObject.h>

using namespace FlameSteelEngine::GameToolkit;

ObjectsMap::ObjectsMap(int width, int height) {

}

int ObjectsMap::indexAtXY(int x, int y) {
	return x+y*width;
}

void ObjectsMap::addOrUpdateObject(shared_ptr<FSCObject> object) {

	auto object = objectIndexToTileIndex(object->id);

	if (object == nulptr)
	{
		map<int, shared_ptr<FSCObject> > coordinateToObjectMap;
		map<int, int> objectIndexToTileIndex;		
	}
	else
	{
		
	}

}

void ObjectsMap::removeObject(shared_ptr<FSCObject> object) {

}

void ObjectsMap::removeAllObjects() {

}

void ObjectsMap::objectAtXY(int x, int y) {

}
