#ifndef FSEGTMATERIALLIBRARY_H_
#define FSEGTMATERIALLIBRARY_H_

#include <map>
#include <memory>
#include <FSGL/Data/Material/FSGLMaterial.h>
#include <FlameSteelFramework/FlameSteelEngineGameToolkit/Data/Components/SurfaceMaterial/SurfaceMaterial.h>

using namespace std;
using namespace FlameSteelEngine::GameToolkit;

class MaterialLibrary {

public:
	void setMaterialForPath(shared_ptr<FSGLMaterial> material, shared_ptr<string> path);
	void setSurfaceMaterialForPath(shared_ptr<SurfaceMaterial> surfaceMaterial, shared_ptr<string> path);

	shared_ptr<FSGLMaterial> materialForPath(shared_ptr<string> path);
	shared_ptr<SurfaceMaterial> surfaceMaterialForPath(shared_ptr<string> path);
	void clear();

private:
	map<string, shared_ptr<FSGLMaterial>> pathMaterialMap;
	map<string, shared_ptr<SurfaceMaterial>> pathSurfaceMaterialMap;

};

#endif
