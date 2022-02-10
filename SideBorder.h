#pragma once
#include "TileManager.h"
#include <SFML/Graphics.hpp>
#ifndef SIDEBORDER_H
#define SIDEBORDER_H

using namespace sf;

class SideBorder {
public:
	//Constructor for the side border
	SideBorder(float X, float Y);
	//Function to return the sprite itself
	Sprite getSprite();
	//FloatRect designed to get the sprites position
	FloatRect getPosition();

private:
	//Automatically sets the coordinates to (0,0)
	float X = 0;
	float Y = 0;

	//Sprite, texture and position variables
	Sprite sideB_Sprite;
	Texture sideB_Texture;
	Vector2f sideB_Position;
};
#endif