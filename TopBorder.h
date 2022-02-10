#pragma once
#include "TileManager.h"
#include <SFML/Graphics.hpp>
#ifndef TOPBORDER_H
#define TOPBORDER_H

using namespace sf;
class TopBorder {
public:
	//Constructor for the side border
	TopBorder(float X, float Y);
	//Function to return the sprite itself
	Sprite getSprite();
	//FloatRect designed to get the sprites position
	FloatRect getPosition();

private:
	//Automatically sets the coords to (0,0)
	float X = 0;
	float Y = 0;

	//Sprite, texture and position variables
	Sprite topB_Sprite;
	Texture topB_Texture;
	Vector2f topB_Position;
};
#endif