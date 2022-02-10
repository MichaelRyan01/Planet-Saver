//code by sam
#pragma once
#ifndef SUBUI_H
#define SUBUI_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>


class SubUI
{
public:
	//Constructor for the SubUI
	SubUI(float subUIX, float subUIY);
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