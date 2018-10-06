/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTAudioPlayer.h
 * Author: demensdeum
 *
 * Created on March 26, 2017, 9:11 AM
 */

#ifndef FSEGTAUDIOPLAYER_H
#define FSEGTAUDIOPLAYER_H

#include <map>
#include <string>
#include <memory>
#include <FlameSteelBattleHorn/Sound.h>
#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOSystem.h>

using namespace std;
using namespace FlameSteelBattleHorn;

class FSEGTAudioPlayer {
public:
    FSEGTAudioPlayer();
    FSEGTAudioPlayer(const FSEGTAudioPlayer& orig);
    virtual ~FSEGTAudioPlayer();
    
    virtual void play(shared_ptr<string> audioName);
    
    shared_ptr<FSEGTIOSystem> ioSystem;    
    
private:
	map<string, shared_ptr<Sound> > soundsMap;
	
};

#endif /* FSEGTAUDIOPLAYER_H */

