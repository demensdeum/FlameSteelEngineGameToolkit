#ifndef FLAMESTEELENGINEGAMETOOLKIT_DEFINED
#define FLAMESTEELENGINEGAMETOOLKIT_DEFINED

#include <memory>
#include <map>

using namespace std;

class FSCObject;

namespace FlameSteelEngine {
namespace GameToolkit {

class ObjectsMap {

public:
	ObjectsMap();

	void handleObject(shared_ptr<FSCObject> object);
	void removeObject(shared_ptr<FSCObject> object);
	void removeAllObjects();

	shared_ptr<FSCObject> objectAtXY(int x, int y);

private:
	string tileIndexAtXY(int x, int y);

	map<string, shared_ptr<FSCObject> > tileIndexToObject;
	map<string, string> objectUUIDToTileIndex;
};
};
};

#endif