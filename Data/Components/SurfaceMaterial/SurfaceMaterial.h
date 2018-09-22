#ifndef FSEGTSURFACEMATERIAL_H_
#define FSEGTSURFACEMATERIAL_H_

#include <FlameSteelCore/Object.h>
#include <SDL2/SDL.h>
#include <FSGL/Data/Material/FSGLMaterial.h>

using namespace FlameSteelCore;

namespace FlameSteelEngine {
namespace GameToolkit {

class SurfaceMaterial: public Object {

public:
	shared_ptr<FSGLMaterial> material;

	SurfaceMaterial(shared_ptr<FSGLMaterial> material);
	SurfaceMaterial(int width, int height);

};

};
};

#endif