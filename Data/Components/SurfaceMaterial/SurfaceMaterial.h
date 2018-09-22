#ifndef FSEGTSURFACEMATERIAL_H_
#define FSEGTSURFACEMATERIAL_H_

#include <FlameSteelCore/Object.h>
#include <SDL2/SDL.h>

using namespace FlameSteelCore;

namespace FlameSteelEngine {
namespace GameToolkit {

class SurfaceMaterial: public Object {

public:
	SDL_Surface *surface = nullptr;

	SurfaceMaterial(int width, int height);
	virtual ~SurfaceMaterial();

};

};
};

#endif