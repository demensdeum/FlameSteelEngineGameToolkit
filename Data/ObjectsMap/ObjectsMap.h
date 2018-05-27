#ifndef FLAMESTEELENGINEGAMETOOLKIT_DEFINED
#define FLAMESTEELENGINEGAMETOOLKIT_DEFINED

#include <memory>
#include <map>

using namespace std;

class FSCObject;
class FSCObjects;

namespace FlameSteelEngine {
namespace GameToolkit {

class ObjectsMap {

public:
	ObjectsMap();

	void handleObject(shared_ptr<FSCObject> object);
	void removeObject(shared_ptr<FSCObject> object);
	void removeAllObjects();

	shared_ptr<FSCObjects> objectsAtXY(int x, int y);

private:
	string tileIndexAtXY(int x, int y);
	void addObjectToTileIndex(shared_ptr<FSCObject> object, string tileIndex);
	void removeObjectAtTileIndex(shared_ptr<FSCObject> object, string tileIndex);

	map<string, shared_ptr<FSCObjects> > tileIndexToObjects;
	map<string, string> objectUUIDToTileIndex;
};
};
};

#endif