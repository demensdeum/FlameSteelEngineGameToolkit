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

	void addOrUpdateObject(shared_ptr<FSCObject> object);
	void removeObject(shared_ptr<FSCObject> object);
	void removeAllObjects();

	shared_ptr<FSCObject> objectAtXY(int x, int y);

private:
	int tileIndexAtXY(int x, int y);

	map<int, shared_ptr<FSCObject> > tileIndexToObject;
	map<int, int> objectIndexToTileIndex;

	int width = 0;
	int height = 0;

};
};
};

#endif