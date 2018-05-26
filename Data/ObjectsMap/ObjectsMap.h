#ifndef FLAMESTEELENGINEGAMETOOLKIT_DEFINED
#define FLAMESTEELENGINEGAMETOOLKIT_DEFINED

#include <memory>
#include <map>

using namespace std;

class FSCObject;

namespace FlameSteelEngine {
namespace GameToolkit {

static const int ObjectsMapNoTileIndex = -1;

class ObjectsMap {

public:
	ObjectsMap(int width, int height);

	void handleObject(shared_ptr<FSCObject> object);
	void removeObject(shared_ptr<FSCObject> object);
	void removeAllObjects();

	shared_ptr<FSCObject> objectAtXY(int x, int y);

private:
	int tileIndexAtXY(int x, int y);

	map<int, shared_ptr<FSCObject> > tileIndexToObject;
	map<string, int> objectUUIDToTileIndex;

	int width;
	int height;
};
};
};

#endif