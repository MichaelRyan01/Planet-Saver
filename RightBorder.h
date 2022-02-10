//code by sam
#pragma once
#ifndef RIGHTBORDER_H
#define RIGHTBORDER_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class RightBorder

{

public:
	//Constructor for the right border
	RightBorder(float rightBorderX, float rightBorderY);
	//FloatRect designed to get the sprites position
	FloatRect getPosition();
	//Function to return the sprite itself
	Sprite getSprite();

private:
	//Sprite, texture and position variables
	Sprite s_Sprite;
	Texture s_Texture;
	Vector2f s_Position;

};
#endif