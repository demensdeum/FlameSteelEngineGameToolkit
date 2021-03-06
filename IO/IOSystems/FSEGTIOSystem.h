/*
 * FSEGTIOSystem.h
 *
 *  Created on: Aug 21, 2016
 *      Author: demensdeum
 */

#ifndef FSEGTIOSYSTEM_H_
#define FSEGTIOSYSTEM_H_

#include <FlameSteelCore/Object.h>

#include <FlameSteelCore/ResourcesManager.h>
#include <FlameSteelEngineGameToolkit/Controllers/MaterialLibrary.h>
#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOSystemParams.h>
#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>

#include <memory>

class FSEGTRenderer;
class FSEGTAudioPlayer;
class FSEGTInputController;

class FSEGTIOSystem: public Object, public FSEGTObjectContextDelegate, public std::enable_shared_from_this<FSEGTIOSystem> {
public:
	FSEGTIOSystem();

	virtual void initialize(shared_ptr<FSEGTIOSystemParams> params = nullptr);

	virtual void clearCache();

	virtual ~FSEGTIOSystem();

        shared_ptr<ResourcesManager> resourcesManager;

	shared_ptr<FSEGTRenderer> renderer;
	shared_ptr<FSEGTInputController> inputController;
	shared_ptr<FSEGTAudioPlayer> audioPlayer;
	shared_ptr<MaterialLibrary> materialLibrary;


	virtual void stop();
};

#endif /* FSEGTIOSYSTEM_H_ */
