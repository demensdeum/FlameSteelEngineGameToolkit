#include "ObjectsMap.h"
#include <FlameSteelCore/FSCObject.h>
#include <iostream>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>

using namespace FlameSteelEngine::GameToolkit;

ObjectsMap::ObjectsMap(int width, int height) {

	this->width = width;
	this->height = height;

}

int ObjectsMap::tileIndexAtXY(int x, int y) {
	return x+y*width;
}

void ObjectsMap::handleObject(shared_ptr<FSCObject> object) {

	if (object.get() == nullptr) {
		throw "ObjectsMap: trying to handle nullptr object.";
	}

	auto objectPosition = FSEGTUtils::getObjectPosition(object);
	auto tileIndex = tileIndexAtXY(objectPosition->x, objectPosition->z);

	if (objectUUIDToTileIndex.find(object->uuid) != objectUUIDToTileIndex.end()) {

		auto currentTileIndex = objectUUIDToTileIndex[object->uuid];

		if (currentTileIndex != tileIndex)
		{
			tileIndexToObject.erase(currentTileIndex);

			objectUUIDToTileIndex[object->uuid] = tileIndex;
			tileIndexToObject[tileIndex] = object;
		}
	}
	else
	{
		objectUUIDToTileIndex[object->uuid] = tileIndex;
		tileIndexToObject[tileIndex] = object;
	}
}

void ObjectsMap::removeObject(shared_ptr<FSCObject> object) {

	if (object.get() == nullptr) {
		throw "ObjectsMap: trying to remove nullptr object.";
	}

	if (objectUUIDToTileIndex.find(object->uuid) != objectUUIDToTileIndex.end()) {

		auto currentTileIndex = objectUUIDToTileIndex[object->uuid];
		tileIndexToObject.erase(currentTileIndex);
		objectUUIDToTileIndex.erase(object->uuid);

	}

}

void ObjectsMap::removeAllObjects() {

	tileIndexToObject.clear();
	objectUUIDToTileIndex.clear();

}

shared_ptr<FSCObject> ObjectsMap::objectAtXY(int x, int y) {

	auto tileIndex = tileIndexAtXY(x, y);

	if (tileIndexToObject.find(tileIndex) != tileIndexToObject.end()) {

			return tileIndexToObject[tileIndex];
	}

	return shared_ptr<FSCObject>();
}
