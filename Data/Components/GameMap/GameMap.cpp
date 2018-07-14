/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameMap.cpp
 * Author: demensdeum
 * 
 * Created on April 25, 2017, 9:18 AM
 */

#include "GameMap.h"

using namespace FlameSteelEngine::GameToolkit;

static const int GameMapNoMapTile = -1;

GameMap::GameMap() {
    
    width = GameMapWidth;
    height = GameMapHeight;
    
}

GameMap::GameMap(const GameMap& ) {
}

shared_ptr<Object> GameMap::getTileAtXY(int tileX, int tileY) {

    auto tileIndex = this->getTileIndexAtXY(tileX, tileY);
    
	if (tileIndex == GameMapNoMapTile) {

		return shared_ptr<Object>();

	}

	unsigned int unsignedTileIndex = tileIndex;

	if (unsignedTileIndex >= tiles.size()) {

		return shared_ptr<Object>();

	}

    return tiles[tileIndex];

}

void GameMap::setTileAtXY(int tileIndex, int tileX, int tileY) {
    
    map[tileX][tileY] = tileIndex;
    
}

int GameMap::getTileIndexAtXY(int tileX, int tileY) {
    
	if (tileX < 0) {

		return GameMapNoMapTile;

	}

	if (tileX >= width) {

		return GameMapNoMapTile;

	}

	if (tileY < 0) {

		return GameMapNoMapTile;

	}

	if (tileY >= height) {

		return GameMapNoMapTile;

	}

    return map[tileX][tileY];
    
}

void GameMap::addTile(shared_ptr<Object> tile) {
    
    tiles.push_back(tile);
    
}

GameMap::~GameMap() {
}
