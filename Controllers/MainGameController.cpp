/*
 * MainGameController.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: demensdeum
 */

#include "MainGameController.h"

#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

using namespace std;
using namespace FlameSteelEngine::GameToolkit;

MainGameController::MainGameController() {

	srand (time(nullptr));

	previousFrameTime = std::chrono::system_clock::now();

    resourcesManager = make_shared<ResourcesManager>();
    resourcesLoader = make_shared<ResourcesLoader>();

    isRunning = false;
    currentController = shared_ptr<GameController>();
    gameControllerMessage = shared_ptr<Message>();
    gameData = shared_ptr<FSEGTGameData>();

    printedSelf = false;
    
#ifdef __EMSCRIPTEN__
    GLOBAL_fsegt_emscripten_gameController = this;
#endif
}

#ifdef __EMSCRIPTEN__

void GLOBAL_fsegt_emscripten_gameLoop() {
    // oh god I don't like javascript for some ugly decisions like those

    GLOBAL_fsegt_emscripten_gameController->gameLoop();
}
#endif

void MainGameController::startGameFromState(int startState) {

    gameData = make_shared<FSEGTGameData>();

    objectsContext = make_shared<FSEGTObjectsContext>();
    objectsContext->setObjects(gameData->getGameObjects());

    objectsContext->subscribe(ioSystem);
    
    this->beforeStart();

    this->switchToState(startState);

    this->setIsRunning(true);

#ifndef __EMSCRIPTEN__
    this->gameLoop();
#else
    emscripten_set_main_loop(GLOBAL_fsegt_emscripten_gameLoop, 60, 1);
#endif    

}

void MainGameController::setIOSystem(shared_ptr<FSEGTIOSystem> ioSystem) {

    ioSystem->resourcesManager = this->resourcesManager;

    this->ioSystem = ioSystem;
}

void MainGameController::setControllerForState(shared_ptr<GameController> controller, int state) {

    stateToControllerMap[state] = controller;

}

void MainGameController::switchToState(int state) {

    this->state = state;
    
    shared_ptr<GameController> controller = stateToControllerMap[state];

    if (controller.get() == nullptr) {

        //cout << "Cannot get controller for state: " << state << endl;

        exit(1);
    }

    ////cout << "Switch controller to state: " << state << endl;
    
    setCurrentController(controller);
}

void MainGameController::gameLoop() {

#ifndef __EMSCRIPTEN__
    while (true) {

	// 60 fps cap
	auto nowTime = std::chrono::system_clock::now();

	auto previousMS = std::chrono::time_point_cast<std::chrono::milliseconds>(previousFrameTime);
	auto nowMS = std::chrono::time_point_cast<std::chrono::milliseconds>(nowTime);

	if (nowMS > previousMS + std::chrono::milliseconds(16))
	{
		previousFrameTime = nowTime;
	}
	else
	{
		continue;
	}

#endif

        this->pollGameControllerMessage();

#ifndef __EMSCRIPTEN__
        if (this->isRunning == false) {
            break; // exit
        }
#endif

        if (this->currentController.get() != nullptr) {

            this->step();
       
        } else {

            ////cout << "MainGameController: no current controller to make a step. Quit." << endl;
            
            if (printedSelf == false) {
            
                printedSelf = true;
                
            //cout << this << endl;
            }
            
            exit(3);
        }

#ifndef __EMSCRIPTEN__                
    }
#endif
}

void MainGameController::step() {
    
    this->currentController->step();
    
}

void MainGameController::pollGameControllerMessage() {
    //TODO handle message
    if (this->gameControllerMessage) {

        this->handleGameControllerMessage(gameControllerMessage);

    }

    this->gameControllerMessage = shared_ptr<Message>();
}

void MainGameController::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}

void MainGameController::handleGameControllerMessage(shared_ptr<Message> ) {

}

void MainGameController::setGameControllerMessage(shared_ptr<Message> message) {
    this->gameControllerMessage = message;
}

void MainGameController::setCurrentController(shared_ptr<GameController> newCurrentController) {
    
    if (currentController.get() != newCurrentController.get()) {
        
        if (currentController.get() != nullptr) {

            currentController->beforeStop();
        }

        currentController = newCurrentController;
        currentController->setIOSystem(this->ioSystem);
        currentController->setGameData(this->getGameData());
        currentController->objectsContext = objectsContext;
        currentController->setGameController(this);
        currentController->listener = this;
        currentController->beforeStart();
    }
}

MainGameController::~MainGameController() {
    stateToControllerMap.clear();
}
