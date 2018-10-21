#include "MaterialLibrary.h"

void MaterialLibrary::setMaterialForPath(shared_ptr<FSGLMaterial> material, shared_ptr<string> path) {
    pathMaterialMap[*path] = material;
}

void MaterialLibrary::setSurfaceMaterialForPath(shared_ptr<SurfaceMaterial> surfaceMaterial, shared_ptr<string> path) {
    pathSurfaceMaterialMap[*path] = surfaceMaterial;
}

shared_ptr<FSGLMaterial> MaterialLibrary::materialForPath(shared_ptr<string> path) {

    auto key = *path;
    
    if (pathMaterialMap.find(key) != pathMaterialMap.end()) {
        return pathMaterialMap[key];
    }
    
	return shared_ptr<FSGLMaterial>();

}

shared_ptr<SurfaceMaterial> MaterialLibrary::surfaceMaterialForPath(shared_ptr<string> path) {

    auto key = *path;
    
    if (pathSurfaceMaterialMap.find(key) != pathSurfaceMaterialMap.end()) {
        return pathSurfaceMaterialMap[key];
    }
    
	return shared_ptr<SurfaceMaterial>();

}

void MaterialLibrary::clear() {
    
	pathSurfaceMaterialMap.clear();
	pathMaterialMap.clear();
    
}
