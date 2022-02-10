#pragma once
#ifndef WASTE_H
#define WASTE_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Waste

{

public:
	//Constructor for the Waste (includes a is spawned boolean
	Waste(float wasteX, float wasteY, bool isSpawned);
	//Function to return the sprite itself
	Sprite getSprite();
	//FloatRect designed to get the sprites position
	FloatRect getPosition();
	//Bool function that checks the spawns of the waste sprites
	bool isSpawned();
	//Bool function used to clean up the waste
	bool clean();
	//Function used to respawn the waste
	void respawnWaste();

private:
	//Sharks coordinates are set to (0,0)
	float wasteX = 0;
	float wasteY = 0;

	//bool variable to check if its spawned
	bool w_Spawned;

	//Sprite, texture and position variables
	Sprite w_Sprite;
	Texture w_Texture;
	Vector2f w_Position;
};
#endif