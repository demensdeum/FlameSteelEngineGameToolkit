/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTAudioPlayer.cpp
 * Author: demensdeum
 * 
 * Created on March 26, 2017, 9:11 AM
 */

#include "FSEGTAudioPlayer.h"

FSEGTAudioPlayer::FSEGTAudioPlayer() {

	Sound::initializeSoundSystem();

}

FSEGTAudioPlayer::FSEGTAudioPlayer(const FSEGTAudioPlayer& ) {
}

void FSEGTAudioPlayer::play(shared_ptr<string> soundName) {

	shared_ptr<Sound> sound = nullptr;

	if (soundsMap.find(*soundName) == soundsMap.end()) {
		sound = make_shared<Sound>(soundName);
		soundsMap[*soundName] = sound;
	}
	else {
		sound = soundsMap[*soundName];
	}

	sound->play();	
}

FSEGTAudioPlayer::~FSEGTAudioPlayer() {
}