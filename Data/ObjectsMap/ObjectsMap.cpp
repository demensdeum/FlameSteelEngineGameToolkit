#include "ObjectsMap.h"
#include <FlameSteelCore/FSCObject.h>
#include <iostream>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <FlameSteelCore/FSCObjects.h>
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>

using namespace FlameSteelEngine::GameToolkit;

ObjectsMap::ObjectsMap() {

}

string ObjectsMap::tileIndexAtXY(int x, int y) {

	string index = to_string(x);
	index += string("-");
	index += to_string(y);

	return index;
}

void ObjectsMap::handleObject(shared_ptr<FSCObject> object) {

	if (object.get() == nullptr) {
		throw logic_error("ObjectsMap: trying to handle nullptr object.");
	}

	if (object->getClassIdentifier()->compare(FSEGTConstObjectClassIdentifierOnScreenText) == 0)
	{
		return;
	}

	auto objectPosition = FSEGTUtils::getObjectPosition(object);
	auto tileIndex = tileIndexAtXY(objectPosition->x, objectPosition->z);

	if (objectUUIDToTileIndex.find(object->uuid) != objectUUIDToTileIndex.end()) {

		auto currentTileIndex = objectUUIDToTileIndex[object->uuid];

		if (currentTileIndex.compare(tileIndex) != 0)
		{
			removeObjectAtTileIndex(object, currentTileIndex);

			objectUUIDToTileIndex[object->uuid] = tileIndex;
			addObjectToTileIndex(object, tileIndex);
		}
	}
	else
	{
		objectUUIDToTileIndex[object->uuid] = tileIndex;
		addObjectToTileIndex(object, tileIndex);
	}
}

void ObjectsMap::removeObject(shared_ptr<FSCObject> object) {

	if (object.get() == nullptr) {
		throw logic_error("ObjectsMap: trying to remove nullptr object.");
	}

	if (objectUUIDToTileIndex.find(object->uuid) != objectUUIDToTileIndex.end()) {

		auto currentTileIndex = objectUUIDToTileIndex[object->uuid];

		removeObjectAtTileIndex(object, currentTileIndex);
		objectUUIDToTileIndex.erase(object->uuid);

	}

}

void ObjectsMap::removeObjectAtTileIndex(shared_ptr<FSCObject> object, string tileIndex) {

		auto objects = tileIndexToObjects[tileIndex];
		objects->removeObject(object);

		if (objects->size() < 1)
		{
			tileIndexToObjects.erase(tileIndex);
		}	

}

void ObjectsMap::addObjectToTileIndex(shared_ptr<FSCObject> object, string tileIndex) {

	if (tileIndexToObjects.find(tileIndex) != tileIndexToObjects.end()) {

		auto objects = tileIndexToObjects[tileIndex];
		objects->addObject(object);

	}
	else {

		auto objects = make_shared<FSCObjects>();
		objects->addObject(object);
		tileIndexToObjects[tileIndex] = objects;
		
	}
}

void ObjectsMap::removeAllObjects() {

	tileIndexToObjects.clear();
	objectUUIDToTileIndex.clear();

}

shared_ptr<FSCObjects> ObjectsMap::objectsAtXY(int x, int y) {

	auto tileIndex = tileIndexAtXY(x, y);

	if (tileIndexToObjects.find(tileIndex) != tileIndexToObjects.end()) {

			return tileIndexToObjects[tileIndex];
	}

	return shared_ptr<FSCObjects>();
}
